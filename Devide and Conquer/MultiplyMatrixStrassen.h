#pragma once
// input_2.txt
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Matrix {
	vector<vector<int>> matrix;
	int size;
};

// Hàm kiểm tra là lũy thừa của 2 hay không
bool isPowerOfTwo2(const int& n)
{
	if (n == 0)
		return false;

	return (ceil(log2(n)) == floor(log2(n)));
}
// Hàm đổi kích thước ma trận theo thành phần size 
void reSize(Matrix& aMatrix) {
	aMatrix.matrix.clear();
	aMatrix.matrix.resize(aMatrix.size);

	for (int row = 0; row < aMatrix.size; row++) {
		aMatrix.matrix[row].resize(aMatrix.size);
	}
}
// Hàm đọc dữ liệu cho ma trận
void Scan(istream& In, Matrix& aMatrix) {
	for (int row = 0; row < aMatrix.size; row++) {
		for (int col = 0; col < aMatrix.size; col++) {
			In >> aMatrix.matrix[row][col];
		}
	}
}
// Hàm chuẩn hóa ma trận (thêm các dòng và cột bằng 0)
Matrix Normalize(Matrix aMatrix) {
	Matrix result = aMatrix;
	int size = result.size;

	if (isPowerOfTwo2(size) == false) {
		result.size = pow(2.0, floor(log2(size)) + 1);	// Chọn kích thước tối ưu để chuẩn hóa
		int diff = result.size - size;	// Tính độ lệch cần thêm

		vector<int> subCol(diff, 0);	// Các phần tử 0 theo cột cần thêm (thêm diff cột)
		vector<vector<int>> subRows(diff, vector<int>(result.size, 0));	// Các dòng 0 cần thêm (diff dòng)

		for (int row = 0; row < size; row++) {
			result.matrix[row].insert(
				result.matrix[row].begin(),
				subCol.begin(),
				subCol.end()
			);
		}

		result.matrix.insert(
			result.matrix.begin(),
			subRows.begin(),
			subRows.end()
		);

	}
	return result;
}
// Hàm chuyển về dạng bình thường của ma trận ban đầu
Matrix deNormalize(Matrix aMatrix, int aSize) {
	Matrix result = aMatrix;
	int size = result.size;

	int diff = size - aSize;

	for (int count = 0; count < diff; count++) {
		result.matrix.erase(result.matrix.begin());
	}

	result.size = aSize;
	for (int row = 0; row < aSize; row++) {

		result.matrix[row].erase(
			result.matrix[row].begin(),
			result.matrix[row].begin() + diff
		);
	}

	return result;
}
// Hàm quá tải toán tử cộng hai ma trận
Matrix operator+(Matrix aMatrix1, Matrix aMatrix2) {
	int size = aMatrix1.size;
	Matrix result = aMatrix1;

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			result.matrix[row][col] += aMatrix2.matrix[row][col];
		}
	}
	return result;
}
// Hàm quá tải toán tử trừ hai ma trận
Matrix operator-(Matrix aMatrix1, Matrix aMatrix2) {
	int size = aMatrix1.size;
	Matrix result = aMatrix1;

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			result.matrix[row][col] -= aMatrix2.matrix[row][col];
		}
	}

	return result;
}
// Hàm chia nhỏ một ma trận vuông kích thước 2^n ra thành 4 ma trận thành phần, trả về vector
vector<Matrix> Separate(Matrix aMatrix) {
	int size = aMatrix.size / 2;

	vector<Matrix> result(4, aMatrix);

	// A11
	result[0].size = size;
	result[0].matrix.erase(
		result[0].matrix.begin() + size,
		result[0].matrix.end()
	);
	for (int row = 0; row < size; row++) {
		result[0].matrix[row].erase(
			result[0].matrix[row].begin() + size,
			result[0].matrix[row].end()
		);
	}

	// A12
	result[1].size = size;
	result[1].matrix.erase(
		result[1].matrix.begin() + size,
		result[1].matrix.end()
	);
	for (int row = 0; row < size; row++) {
		result[1].matrix[row].erase(
			result[1].matrix[row].begin(),
			result[1].matrix[row].begin() + size
		);
	}

	// A21
	result[2].size = size;
	result[2].matrix.erase(
		result[2].matrix.begin(),
		result[2].matrix.begin() + size
	);
	for (int row = 0; row < size; row++) {
		result[2].matrix[row].erase(
			result[2].matrix[row].begin() + size,
			result[2].matrix[row].end()
		);
	}

	// A22
	result[3].size = size;
	result[3].matrix.erase(
		result[3].matrix.begin(),
		result[3].matrix.begin() + size
	);
	for (int row = 0; row < size; row++) {
		result[3].matrix[row].erase(
			result[3].matrix[row].begin(),
			result[3].matrix[row].begin() + size
		);
	}

	return result;
}
// Hàm kết hợp ma trận từ danh sách 4 ma trận thành phần
Matrix Combine(vector<Matrix> aList) {
	int size = aList[0].size;
	int newSize = 2 * size;

	Matrix result = aList[0];
	result.size = newSize;

	// A11 + A12
	for (int row = 0; row < size; row++) {
		result.matrix[row].insert(
			result.matrix[row].end(),
			aList[1].matrix[row].begin(),
			aList[1].matrix[row].end());
	}
	// B21 + B22
	result.matrix.insert(
		result.matrix.end(),
		aList[2].matrix.begin(),
		aList[2].matrix.end()
	);
	for (int row = size; row < newSize; row++) {
		result.matrix[row].insert(
			result.matrix[row].end(),
			aList[3].matrix[row - size].begin(),
			aList[3].matrix[row - size].end());
	}

	return result;
}

// Hàm quá tải toán tử xuất một ma trận
ostream& operator<<(ostream& Out, const Matrix& aMatrix) {
	for (int row = 0; row < aMatrix.size; row++) {
		for (int col = 0; col < aMatrix.size; col++) {
			Out << aMatrix.matrix[row][col] << " ";
		}
		Out << endl;
	}
	return Out;
}
// Hàm nhân ma trận Strassen
void Strassen(int size, Matrix aMatrix1, Matrix aMatrix2, Matrix& result) {

	if (size == 1) {
		result.matrix.push_back(
			vector<int>{ aMatrix1.matrix[0][0] * aMatrix2.matrix[0][0]});
		result.size = 1;
		return;
	}

	vector<Matrix> 
		List1 = Separate(aMatrix1), 
		List2 = Separate(aMatrix2);
	Matrix M1, M2, M3, M4, M5, M6, M7;

	Strassen(size / 2, List1[0] + List1[3], List2[0] + List2[3], M1);
	Strassen(size / 2, List1[2] + List1[3], List2[0], M2);
	Strassen(size / 2, List1[0], List2[1] - List2[3], M3);
	Strassen(size / 2, List1[3], List2[2] - List2[0], M4);
	Strassen(size / 2, List1[0] + List1[1], List2[3], M5);
	Strassen(size / 2, List1[2] - List1[0], List2[0] + List2[1], M6);
	Strassen(size / 2, List1[1] - List1[3], List2[2] + List2[3], M7);

	result = Combine(vector<Matrix>{
			M1 + M4 - M5 + M7, 
			M3 + M5, 
			M2 + M4, 
			M1 + M3 - M2 + M6});

}

void test2() {
	Matrix a, b;
	ifstream is("input_2.txt");

	if (is.good()) {
		is >> a.size;

		b.size = a.size;
		reSize(a);
		reSize(b);

		Scan(is, a);
		Scan(is, b);
	}
	int trueSize = a.size;
	// Chuẩn hóa, thêm các dòng và cột 0 vào để thành ma trận kích tước 2^n x 2^n 
	Matrix newa = Normalize(a), 
		newb = Normalize(b);
	Matrix newc;
	// Gọi hàm nhân Strassen
	Strassen(newa.size, newa, newb, newc);
	// In kết quả
	cout << deNormalize(newc, trueSize);
}