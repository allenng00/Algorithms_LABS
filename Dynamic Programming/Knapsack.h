#pragma once

// input_7.txt 7.cpp
// Giải thuật giải bài toán túi xách 0-1
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/// <summary>
/// Hàm tìm số lớn hơn trong 2 số
/// </summary>
/// <param name="a">Số thứ nhất</param>
/// <param name="b">Số thứ hai</param>
/// <returns>Trả về số nguyên kiểu int lớn hơn trong 2 số trên</returns>
int Max_(int a, int b) {
	return (a > b ? a : b);
}

/// <summary>
/// Hàm tối ưu việc sắp xếp num vật vào tui 
/// </summary>
/// <param name="matrix">Ma trận kết quả</param>
/// <param name="num">Tổng số vật</param>
/// <param name="values">Giá trị các vật</param>
/// <param name="maxW">Khối lượng tối đa</param>
/// <param name="weight">Khối lượng các vật</param>
void Knapsack(vector<vector<int>>& matrix,
	int num, vector<int> values,
	int maxW, vector<int> weight) {
	// Duyệt các vật theo thứ tự input
	for (int i = 1; i <= num; i++) {

		for (int j = 1; j <= maxW; j++) {
			// Thêm được vật i
			if (weight[i - 1] <= j) {
				matrix[i][j] = Max_(
					matrix[i - 1][j],
					matrix[i - 1][j - weight[i - 1]] + values[i - 1]);
			}
			else { // Không thêm vật i được, giá trị mới bằng giá trị ở (i-1)
				matrix[i][j] = matrix[i - 1][j];
			}
		}
	}
}

/// <summary>
/// Hàm truy vết các vật được cho vào túi để giá trị chứa đựng được tối ưu
/// </summary>
/// <param name="num">Số lượng vật</param>
/// <param name="maxW">Khối lượng tối đa</param>
/// <param name="weight">Mảng khối lượng từng vật</param>
/// <param name="matrix">Ma trận kết quả</param>
void trace(int num, int maxW, vector<int> weight, vector<vector<int>> matrix) {
	// Khai báo biến
	int n = num;
	int w = maxW;
	vector<int> frequency(num, 0);

	// Truy vết
	while (n != 1) {
		if (matrix[n][w] != matrix[n - 1][w]) {
			frequency[n - 1] = 1;
			w -= weight[n - 1];
		}
		n--;
	}
	// Xét n = 1
	if (matrix[n][w] != 0) {
		frequency[n - 1] = 1;
	}

	// Xuất mảng các gói hàng
	for (int i = 0; i < num; i++) {
		if (frequency[i] == 1) {
			cout << i << " ";
		}
	}

	// Xuất giá trị tối ưu
	cout << endl << matrix[num][maxW] << endl;
}

void test7() {
	// Khai báo biến
	int maxW, num;
	int w, v;
	vector<int> weight;
	vector<int> values;
	// Đọc file
	ifstream is("input_7.txt");

	if (is.good()) {
		is >> maxW;	// Trọng lượng tối đa
		is >> num;		// Số vật

		for (int i = 0; i < num; i++) {
			is >> w >> v;	// Nhập trọng lượng và giá trị cho từng vật
			weight.push_back(w);
			values.push_back(v);
		}
	}

	// Khai báo ma trận để giải bài toán
	vector<vector<int>> matrix(num + 1, vector<int>(maxW + 1, 0));

	// Xử lý bài toán
	Knapsack(matrix, num, values, maxW, weight);
	// Gọi hàm truy vết
	trace(num, maxW, weight, matrix);

}