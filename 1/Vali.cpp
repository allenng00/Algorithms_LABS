//// 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Giải thuật giải bài toán túi xách 0-1
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//using namespace std;
//
///// <summary>
///// Hàm tìm số lớn hơn trong 2 số
///// </summary>
///// <param name="a">Số thứ nhất</param>
///// <param name="b">Số thứ hai</param>
///// <returns>Trả về số nguyên kiểu int là số lớn hơn trong 2 số trên</returns>
//int max(int a, int b) {
//	int result = a;
//
//	if (b > result) {
//		result = b;
//	}
//
//	return result;
//}
//
///// <summary>
///// Hàm tối ưu việc sắp xếp num vật vào tui 
///// </summary>
///// <param name="matrix">Ma trận kết quả</param>
///// <param name="num">Tổng số vật</param>
///// <param name="values">Giá trị các vật</param>
///// <param name="maxW">Khối lượng tối đa</param>
///// <param name="weight">Khối lượng các vật</param>
//void solve(vector<vector<int>>& matrix,
//	int num, vector<int> values,
//	int maxW, vector<int> weight) {
//	int i_new;
//	// Duyệt các vật theo thứ tự input
//	for (int i = 0; i < num; i++) {
//
//		for (int j = 0; j <= maxW; j++) {
//			// Thêm được vật i
//			if (weight[i] <= j) {
//				// Xét vị trí i bằng 0
//				if (i == 0) {
//					i_new = i;
//				}
//				else {
//					i_new = i - 1;
//				}
//
//				matrix[i][j] = max(
//					matrix[i_new][j],
//					matrix[i_new][j - weight[i]] + values[i]
//				);
//			}
//			else { // Không thêm vật i được, giá trị mới bằng giá trị ở (i-1)
//				matrix[i][j] = (i == 0) ? 0 : matrix[i - 1][j];
//			}
//		}
//	}
//}
//
///// <summary>
///// Hàm truy vết các vật được cho vào túi để giá trị chứa đựng được tối ưu
///// </summary>
///// <param name="num">Số lượng vật</param>
///// <param name="maxW">Khối lượng tối đa</param>
///// <param name="weight">Mảng khối lượng từng vật</param>
///// <param name="matrix">Ma trận kết quả</param>
//void trace(int num, int maxW, vector<int> weight, vector<vector<int>> matrix) {
//	// Khai báo biến
//	int n = num - 1;
//	int w = maxW;
//	vector<int> frequency(num, 0);
//
//	// Truy vết
//	while (n != 0) {
//		if (matrix[n][w] != matrix[n - 1][w]) {
//			frequency[n] = 1;
//			w -= weight[n];
//		}
//		n--;
//	}
//	// Xét n = 0
//	if (matrix[n][w] != 0) {
//		frequency[n] = 1;
//	}
//
//	// Xuất mảng các gói hàng
//	for (int i = 0; i < num; i++) {
//		if (frequency[i] == 1) {
//			cout << i <<" ";
//		}
//	}
//
//	// Xuất giá trị tối ưu
//	cout << endl << matrix[num - 1][maxW] << endl;
//	}
//
//int main() {
//	// Khai báo biến
//	int maxW, num;
//	int w, v;
//	vector<int> weight;
//	vector<int> values;
//	// Đọc file
//	freopen("input_6.txt", "r", stdin);
//
//	while (!feof(stdin)) {
//		cin >> maxW;	// Trọng lượng tối đa
//		cin >> num;		// Số vật
//
//		for (int i = 0; i < num; i++) {
//			cin >> w >> v;	// Nhập trọng lượng và giá trị cho từng vật
//			weight.push_back(w);
//			values.push_back(v);
//		}
//	}
//
//	// Khai báo ma trận để giải bài toán
//	vector<vector<int>> matrix(num, vector<int>(maxW + 1, 0));
//
//	// Xử lý bài toán
//	solve(matrix, num, values, maxW, weight);
//	// Gọi hàm truy vết
//	trace(num, maxW, weight, matrix);
//
//	return 0;
//}