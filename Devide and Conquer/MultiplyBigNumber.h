#pragma once
// input_1.txt
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
string MultiplyTo2(string str); 

vector<string> PowerOfTwo; // mảng string lưu chuỗi tương ứng là lũy thừa của 2
// Hàm tìm số lớn hơn trong 2 số
template <class T>
T Max(const T& ele1, const T& ele2) {
	return ele1 > ele2 ? ele1 : ele2;
}
// Hàm khởi tạo mảng Power
void GenaratePower(const int& size) {
	int curSize = PowerOfTwo.size();

	if (curSize >= size) {
		return;
	}

	if (curSize == 0) {
		PowerOfTwo.push_back("1");
		curSize = 1;
	}
	for (int pos = curSize; pos < size; pos++) {
		PowerOfTwo.push_back(MultiplyTo2(PowerOfTwo[pos - 1]));
	}
}

// Định nghĩa cấu trúc số nguyên
struct BigNum {
	vector<unsigned char> bValue; // Dạng nhị phân
	int digits = 1;
};

// Hàm cộng hai chuỗi số
string PlusString(string str1, string str2) {
	int len1 = str1.size(), len2 = str2.size(), i1 = len1 - 1, i2 = len2 - 1;
	int r = 0, sum = 0; // bit nhớ, biến ghi tổng
	char result;
	string str_sum;
	// Cho vòng lặp thực hiện cộng từ cuối chuỗi đến đầu chuỗi ngắn hơn 
	while (i1 >= 0 && i2 >= 0) {
		sum = int(str1[i1] - 48) + int(str2[i2] - 48) + r;
		r = sum / 10;
		str_sum.insert(str_sum.begin() + 0, (sum % 10 + 48));
		i1--, i2--;
	}
	// Xét phần mà chuỗi 1 hoặc chuỗi 2 còn thừa
	if (r == 0) { //Nếu không có nhớ
		if (i2 < 0) { // Chuỗi 1 nhiều chữ số hơn
			str_sum.insert(0, str1, 0, (i1 + 1));
		}
		else if (i1 < 0) { // Chuỗi 2 nhiều chữ số hơn
			str_sum.insert(0, str2, 0, i2 + 1);
		}
	}
	else { // Nếu có nhớ
		if (i2 < 0) { // Chuỗi 1 nhiều chữ số hơn
			while (i1 >= 0) {
				sum = int(str1[i1] - 48) + r;
				r = sum / 10;
				str_sum.insert(str_sum.begin() + 0, sum % 10 + 48);
				i1--;
			}
		}
		else if (i1 < 0) { // Chuỗi 2 nhiều chữ số hơn
			while (i2 >= 0) {
				sum = int(str2[i2] - 48) + r;
				r = sum / 10;
				str_sum.insert(str_sum.begin() + 0, (sum % 10 + 48));
				i2--;
			}
		}
		if (r != 0)
			str_sum.insert(str_sum.begin() + 0, (r + 48));
	}
	return str_sum; // trả về tổng
}
// Hàm kiểm tra là lũy thừa của 2 hay không
bool isPowerOfTwo(const int& n)
{
	if (n == 0)
		return false;

	return (ceil(log2(n)) == floor(log2(n)));
}
// Hàm nhân một chuỗi số với 2
string MultiplyTo2(string str) {
	int len = str.size(), k = 0, r = 0;
	// Thực hiên nhân 2 chuỗi số
	for (int pos = len - 1; pos >= 0; pos--) {
		k = r + 2 * (int)(str[pos] - 48);
		str[pos] = k % 10 + 48;
		r = k / 10;
	}
	// Nếu có nhớ, thêm 1 vào đầu chuỗi
	if (r != 0) {
		str.insert(str.begin() + 0, '1');
	}
	return str;
}
// Hàm chia một chuỗi số cho 2
void DevideToTwo(string& str) {
	int len = str.size(), k = 0, r = 0;
	// Thực hiên chia 2 chuỗi số
	for (int pos = 0; pos < len; pos++) {
		k = 10 * r + (int)(str[pos] - 48);
		str[pos] = k / 2 + 48;
		r = k % 2;
	}
	//Nếu phần tử đầu bằng 0 thì xóa
	while (str[0] == '0') {
		str.erase(str.begin() + 0);
	}
}
// Hàm thay đổi số chữ số dạng nhị phân của số nguyên
void SetDigits(BigNum& aNum, int digits = 0) {
	int size = aNum.bValue.size();

	if (digits == 0) {

		if (isPowerOfTwo(size))
			aNum.digits = size;
		else {
			aNum.digits = pow(2.0, floor(log2(size)) + 1);

			int diff = aNum.digits - size;

			for (int count = 0; count < diff; count++)
				aNum.bValue.insert(aNum.bValue.begin(), 0);
		}
	}
	else {
		if (digits > size) {
			aNum.digits = digits;

			int diff = aNum.digits - size;

			for (int count = 0; count < diff; count++)
				aNum.bValue.insert(aNum.bValue.begin(), 0);
		}
	}
}
// Hàm nhập số nguyên
void Scan(istream& In, BigNum& aNum) {
	string temp_str;
	In >> temp_str;

	// Chia 2 chuỗi số (số học)
	while (temp_str != "") {
		if (int(temp_str.back() - 48) % 2 == 1)
			aNum.bValue.insert(aNum.bValue.begin(), 1);
		else
			aNum.bValue.insert(aNum.bValue.begin(), 0);

		DevideToTwo(temp_str);
	}

	SetDigits(aNum);
}
// Hàm dịch trái số nguyên
BigNum operator<< (const BigNum& aNum, const int& ShiftOffset) //ShiftOffset: Số lần dịch
{
	if (ShiftOffset == 0) {
		return aNum;
	}
	int t = ShiftOffset;
	BigNum result; // Biến kết quả dịch
	vector<unsigned char> zeroes(ShiftOffset, 0);

	result.bValue = aNum.bValue;
	result.bValue.insert(result.bValue.end(), zeroes.begin(), zeroes.end());

	return result;
}
// Hàm cộng 2 số nguyên
BigNum operator + (const BigNum& aNum1, const BigNum& aNum2)
{
	int n = 0, x1, x2, t;
	BigNum result;
	int size1 = aNum1.bValue.size(),
		size2 = aNum2.bValue.size();
	int pos1 = size1 - 1, pos2 = size2 - 1;

	while (pos1 >= 0 && pos2 >= 0)
	{
		x1 = aNum1.bValue[pos1];
		x2 = aNum2.bValue[pos2];
		t = x1 + x2 + n; // Tổng của 2 bit của a, b ở vị trí i và số nhớ n
		result.bValue.insert(result.bValue.begin(), t % 2);
		n = t / 2;
		pos1--;
		pos2--;
	}

	while (pos1 >= 0) {
		x1 = aNum1.bValue[pos1];
		t = x1 + n; // Tổng của 2 bit của a, b ở vị trí i và số nhớ n
		result.bValue.insert(result.bValue.begin(), t % 2);
		n = t / 2;
		pos1--;
	}

	while (pos2 >= 0) {
		x2 = aNum2.bValue[pos2];
		t = x2 + n; // Tổng của 2 bit của a, b ở vị trí i và số nhớ n
		result.bValue.insert(result.bValue.begin(), t % 2);
		n = t / 2;
		pos2--;
	}

	if (n != 0) {
		result.bValue.insert(result.bValue.begin(), 1);
	}

	SetDigits(result);

	return result;
}
// Hàm trừ 2 số nguyên
BigNum operator - (const BigNum& aNum1, const BigNum& aNum2)
{
	int n = 0, x1, x2, t;
	BigNum result;
	int size1 = aNum1.bValue.size(),
		size2 = aNum2.bValue.size();
	int pos1 = size1 - 1, pos2 = size2 - 1;

	while (pos2 >= 0)
	{
		x1 = aNum1.bValue[pos1];
		x2 = aNum2.bValue[pos2];
		t = x1 - x2 + n; // Tổng của 2 bit của a, b ở vị trí i và số nhớ n
		result.bValue.insert(result.bValue.begin(), abs(t % 2));
		n = t < 0 ? -1 : 0;
		pos1--;
		pos2--;
	}

	while (pos1 >= 0) {
		x1 = aNum1.bValue[pos1];
		t = x1 + n; // Tổng của 2 bit của a, b ở vị trí i và số nhớ n
		result.bValue.insert(result.bValue.begin(), abs(t % 2));
		n = t < 0 ? -1 : 0;
		pos1--;
	}

	return result;
}
// Hàm nhân 2 số nguyên theo cách nhân cơ bản
BigNum operator *(const BigNum& aNum1, const BigNum& aNum2)
{
	BigNum result, tmp;
	int size2 = aNum2.bValue.size();

	for (int pos2 = size2 - 1, count = 0; 
		pos2 >= 0; 
		pos2--, count++)
	{
		if (aNum2.bValue[pos2] == 1)
		{
			tmp = aNum1 << count;
			result = result + tmp;
		}
	}

	return result;
}
// Hàm xuất giá trị thập phân của số nguyên
string dValue(const BigNum& aNum) {
	int size = aNum.bValue.size();
	if (size == 0) {

		return "0";
	}
	string result = "0";

	for (int pos1 = size - 1, pos2 = 0; pos1 >= 0; pos1--, pos2++) {
		if (aNum.bValue[pos1] == 1) {
			result = PlusString(result, PowerOfTwo[pos2]);
		}
	}

	return result;
}
// Hàm xuất giá trị nhị phân của số nguyên
void printBValue(BigNum aNum) {
	for (auto ele : aNum.bValue) {
		cout << +ele;
	}
}
// Hàm nhân hai số nguyên theo chia để trị
BigNum multiply(BigNum aNum1, BigNum aNum2) {
	int n = Max(aNum1.digits, aNum2.digits);

	if (n <= 64) {
		return aNum1 * aNum2;
	}

	SetDigits(aNum1, n);
	SetDigits(aNum2, n);

	//int numEleL = ceil(float(n) / 2);
	int numEle = n / 2;

	BigNum
		aNum1L = { vector<unsigned char>(aNum1.bValue.begin(), aNum1.bValue.begin() + numEle), numEle },
		aNum1R = { vector<unsigned char>(aNum1.bValue.begin() + numEle, aNum1.bValue.end()), numEle },
		aNum2L = { vector<unsigned char>(aNum2.bValue.begin(), aNum2.bValue.begin() + numEle), numEle },
		aNum2R = { vector<unsigned char>(aNum2.bValue.begin() + numEle, aNum2.bValue.end()), numEle };

	BigNum
		P1 = multiply(aNum1L, aNum2L),
		P2 = multiply(aNum1R, aNum2R),
		P3 = multiply(aNum1L + aNum1R, aNum2L + aNum2R);

	return (P1 << n) + ((P3 - P1 - P2) << numEle) + P2;
}

void test1() {
	BigNum num1, num2;
	ifstream is("input_1.txt");

	if (is.good()) {
		Scan(is, num1);
		Scan(is, num2);	
	}
	// Gọi hàm khởi tạo
	GenaratePower(2 * Max(num1.digits, num2.digits) + 1);
	// Xuất kết quả
	cout << dValue(multiply(num1, num2)) << endl;
}

