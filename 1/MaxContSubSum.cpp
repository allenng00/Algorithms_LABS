//// 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Giải thuật tìm dãy con có tổng lớn nhất trong dãy số thực cho trước
//// Tham khảo: tài liệu lý thuyết
//#include <iostream>
//#include <math.h>
//#include <string>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//// Định nghĩa epsilon, dùng số này tránh sai số khi tính hiệu 2 số thực
//const double epsilon = numeric_limits<double>::epsilon();
//
///// <summary>
///// Hàm xuất mảng số thực
///// </summary>
///// <param name="n"></param>
///// <param name="arr"></param>
///// <param name="start"></param>
///// <param name="end"></param>
//void PrintArray(long n, vector<double> arr, long start, long end) {
//
//	if (start <= end && end < n) {
//
//	}
//	else {
//		start = 0; end = n - 1;
//	}
//
//	for (long pos = start; pos <= end; pos++) {
//		cout << arr[pos] << " ";
//	}
//
//}
//
///// <summary>
///// Hàm tìm dãy cong có tổng lớn nhất trong dãy số thực cho sẵn
///// </summary>
///// <param name="n">Số lượng phần tử của mảng</param>
///// <param name="arr">Mảng số thực</param>
///// <param name="start"></param>
///// <param name="end"></param>
///// <returns></returns>
//double MaxContSubSum(long n, vector<double>& arr, long& start, long& end) {
//
//	double diff = 0, maxSum = 0, curSum = 0;
//
//	for (long j = 0; j < n; j++) {
//		curSum += arr[j];
//
//		if (curSum > maxSum) {
//			maxSum = curSum;
//			end = j;
//		}
//		else if (curSum < 0) {
//			curSum = 0;
//		}
//	}
//
//	curSum = maxSum;
//
//	// Truy vết dãy con
//	for (start = end; ; start--) {
//		diff = curSum - arr[start];
//		// Nếu hiệu bằng 0, rất gần với epsilon
//		if (fabs(diff) <= 2 * epsilon) {
//			break;
//		}
//		else {
//			curSum = diff;
//		}
//	}
//
//	return maxSum;
//	}
//
//int main()
//{
//	long n, start = 0, end = 0;
//	double maxSum = 0;
//	vector<double> arr;
//
//	// Đọc file
//	freopen("input_2.txt", "r", stdin);
//	while (!feof(stdin)) {
//		cin >> n;
//		arr.resize(n);
//
//		for (long pos = 0; pos < n; pos++) {
//			cin >> arr[pos];
//		}
//		break;
//	}
//
//	// Tính tổng dãy con có tổng lớn nhất
//	maxSum = MaxContSubSum(n, arr, start, end);
//	// Xuất dãy con
//	PrintArray(n, arr, start, end);
//	// Xuất ra tổng cần tìm
//	cout << endl << maxSum << endl;
//
//	return 0;
//}
