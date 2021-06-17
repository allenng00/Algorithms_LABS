///*
//3.cpp
//Giải thuật tìm tập con của tập đã cho, sao cho tổng cá phần tử của tập con này bằng với t
//Đề xuất 2 giải pháp: Quay lui và quay lui vét cạn
//*/
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
///// <summary>
///// Hàm tìm phần tử trung vị cho sắp xếp nhanh
///// </summary>
///// <param name="arr">biến vector mãng số nguyên</param>
///// <param name="low">biên dưới</param>
///// <param name="high">biên trên</param>
///// <returns>biến kiểu nguyên là vị trí phần tử trung vị</returns>
//long Median(vector<long>& arr, long low, long high)
//{
//	long pivot = arr[high], left = low, right = high - 1;
//	while (1) {
//		while (left <= right && arr[left] < pivot) left++;
//		while (right >= left && arr[right] > pivot) right--;
//
//		if (left >= right) break;
//		swap(arr[left], arr[right]);
//		left++; right--;
//	}
//	swap(arr[left], arr[high]);
//	return left;
//}
//
///// <summary>
///// Hàm sắp xếp nhanh theo chiều tăng dần 1 mãng số nguyên
///// </summary>
///// <param name="arr">biến vector mảng số nguyên</param>
///// <param name="low">biên dưới</param>
///// <param name="high">biên trên</param>
//void Quicksort(vector<long>& arr, long low, long high)
//{
//	if (low < high)
//	{	/* pos là chỉ số nơi phần tử này đã đứng đúng vị trí
//		và là phần tử chia mảng làm 2 mảng con trái & phải */
//		long pos = Median(arr, low, high);
//		Quicksort(arr, low, pos - 1);
//		Quicksort(arr, pos + 1, high);
//	}
//}
//
///// <summary>
///// Hàm xuất các phần tử được chọn trong mảng số nguyên gốc
///// </summary>
///// <param name="num">số nguyên - số lượng phần tử của mảng</param>
///// <param name="arr">mảng gốc</param>
///// <param name="check">mảng kiểm trả phần tử tương ứng trong mảng gốc có thỏa không</param>
//void PrintSubArray(long num, vector<long> arr, vector<bool>check) {
//	// Duyệt hết mảng
//	for (long pos = 0; pos < num; pos++) {
//		// Nếu check[pos] = true thì xuất phần tử arr[pos]
//		if (check[pos]) {
//			cout << arr[pos] << " ";
//		}
//	}
//
//	cout << endl;
//}
//
///// <summary>
///// Hàm xuất các phần tử được chọn
///// </summary>
///// <param name="size">số nguyên - kich thước của các mảng con</param>
///// <param name="subArr">mảng số nguyên dạng vector</param>
//void PrintSubArray2(long size, vector<long> subArr) {
//	// Duyệt và xuất toàn mảng
//	for (int i = 0; i < size; i++) {
//		cout << subArr[i] << " ";
//	}
//
//	cout << endl;
//}
//
///// <summary>
///// Hàm tìm chuỗi con trong chuỗi cho trước có tổng bằng t bằng phương pháp quay lui
///// </summary>
///// <param name="k">số nguyên - vị trí đang xét</param>
///// <param name="curSum">số nguyên - tổng tích lũy hiện tại</param>
///// <param name="sum">số nguyên - tổng của toàn mảng</param>
///// <param name="expectSum">số nguyên - tổng cần so sánh (mong đợi)</param>
///// <param name="num">số nguyên - kích thước mảng gốc</param>
///// <param name="check">vector bool - đánh dấu phần tử thỏa</param>
///// <param name="arr">vector nguyên - mảng gốc</param>
//void SoS_version1(
//	long k, long curSum, long sum,
//	long expectSum, long num,
//	vector<bool> check, vector<long>arr) {
//
//	if (curSum == expectSum) { // Nếu tổng hiện tại bằng tổng mong đợi (t)
//		PrintSubArray(num, arr, check);	// Gọi hàm xuất các phần tử thỏa yêu cầu
//	}
//	else {
//
//		if ((curSum + sum >= expectSum) //
//			&& (curSum + arr[k] <= expectSum)) {
//			check[k] = true;
//			SoS_version1(k + 1, curSum + arr[k], sum - arr[k], expectSum, num, check, arr);
//			check[k] = false;
//			SoS_version1(k + 1, curSum, sum - arr[k], expectSum, num, check, arr);
//		}
//	}
//}
//
///// <summary>
///// Hàm tìm chuỗi con trong chuỗi cho trước có tổng bằng t bằng phương pháp quay lui vét cạn
///// </summary>
///// <param name="size">số nguyên - kích thước mảng con thỏa bài toán</param>
///// <param name="curSum">số nguyên - tổng tích lũy của mảng hiện tại đang xét</param>
///// <param name="sum">số nguyên - tổng của mảng gốc</param>
///// <param name="start">số nguyên - điểm bắt đầu của quá trình xét</param>
///// <param name="expectSum">số nguyên - tổng dãy con cần tìm (mong đợi)</param>
///// <param name="num">số nguyên - kích thước mảng gốc</param>
///// <param name="subArr">vector nguyên - mảng phụ thỏa đề bài</param>
///// <param name="arr">vector nguyên - mảng gốc</param>
//void SoS_version2(
//	long size, long curSum, long sum, long start,
//	long expectSum, long num,
//	vector<long> subArr, vector<long>arr) {
//
//	if (curSum == expectSum) {
//		PrintSubArray2(size - 1, subArr);
//	}
//	else {
//		long lost = 0;
//		for (long i = start; i < num; i++) {
//
//			if ((curSum + sum - lost >= expectSum) && (curSum + arr[i] <= expectSum)) {
//				subArr[size - 1] = arr[i];
//				SoS_version2(size + 1, curSum + arr[i], sum - lost - arr[i], i + 1, expectSum, num, subArr, arr);
//			}
//		}
//	}
//}
//
//int main() {
//	// Khai báo biến
//	long num, t, sum = 0;
//	char temp;
//	vector<long> arr;
//	ifstream is("input_3.txt");
//
//	// Đọc file
//	if (is.good()) {
//		is >> num;
//
//		if (num > 0) {
//			arr.resize(num);
//
//			is >> arr[0];
//			sum = arr[0];
//
//			for (long i = 1; i < num; i++) {
//				is >> temp >> arr[i];
//				sum += arr[i];
//			}
//
//			is >> t;
//		}
//		else {
//			return -1;
//		}
//	}
//
//	vector<bool> check(num, false);
//	vector<long> subArr(num, 0);
//
//	// Sắp xếp tăng cho mảng
//	Quicksort(arr, 0, arr.size() - 1);
//
//	if (arr[0] <= t && t <= sum) {
//		SoS_version1(0, 0, sum, t, num, check, arr);
//		cout << endl;
//		SoS_version2(1, 0, sum, 0, t, num, subArr, arr);
//	}
//	return 0;
//}