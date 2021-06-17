//// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Giải thuật sắp xếp ShakeSort
//#include <iostream>
//#include <math.h>
//#include <string>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//// Hàm in mảng
//void PrintArray(long n, vector<double> arr) {
//	for (long pos = 0; pos < n; pos++) {
//		cout << arr[pos] << " ";
//	}
//
//}
//
//void ShakerSort(long n, vector<double>& arr) {
//	long bm = 0, day = n - 1, k = n - 1;
//	while (bm < day) {
//		for (long j = day; j >= bm + 1; j--) {
//			if (arr[j] < arr[j - 1]) {
//				swap(arr[j], arr[j - 1]);
//				k = j;
//			}
//		}
//		bm = k;
//		for (long j = bm; j < day; j++) {
//			if (arr[j] > arr[j + 1]) {
//				swap(arr[j], arr[j + 1]);
//				k = j;
//			}
//		}
//		day = k;
//	}
//}
//void TransferLines(istream& inDev, ostream& outDev) {
//	const int maxSize = 255;
//	char buf[maxSize + 1];
//	while (inDev.getline(buf, maxSize)) {
//		outDev << buf << endl;
//
//	}
//
//}
//
//int main()
//{
//	long num;
//	vector<double> arr;
//
//	// Doc File
//	freopen("input_1.txt", "r", stdin);
//	while (!feof(stdin)) {
//		cin >> num;
//		arr.resize(num);
//
//		for (long pos = 0; pos < num; pos++) {
//			cin >> arr[pos];
//		}
//		break;
//	}
//	
//	// Gọi hàm sắp xếp
//	ShakerSort(num, arr);
//	// Xuất mảng
//	PrintArray(num, arr);
//	cout << endl;
//	return 0;
//
//}
