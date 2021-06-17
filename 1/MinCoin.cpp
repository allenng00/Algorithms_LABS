//// 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Giải thuật tìm số xu ít nhất khi dùng các đồng xu có mệnh giá cơ sở chia đều mức tiền cho trươcs
//#include <iostream>
//#include <math.h>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
///// <summary>
///// Ham tim so xu it nhat
///// </summary>
///// <param name="kinds">Mảng chưa loại các mệnh giá xu</param>
///// <param name="num">Số loại</param>
///// <param name="Total">Tổng tiền muốn chia</param>
//void minCoins(vector<int> kinds, int num, int Total)
//{
//	bool count = false;
//
//	vector<int> countCoin(num, 0);
//	// base case
//	if (Total == 0)
//		return;
//
//	int subTotal = Total;
//	for (int i = 0; i < num; i++) {
//		countCoin[i] = subTotal / kinds[i];
//		subTotal = subTotal % kinds[i];
//	}
//	// Duyệt và xuất kết quả
//	for (int i = 0; i < num; i++) {
//		cout << kinds[i] << ": " << countCoin[i] << endl;
//	}
//}
//
//int main()
//{
//	long total = 0;
//	vector<int> kinds;
//	string str, ele;
//	stringstream ss;
//
//	// Mo file de doc
//	freopen("input_3.txt", "r", stdin);
//
//	while (!feof(stdin)) {
//		getline(cin, str);
//		ss << str;
//
//		while (!ss.eof())
//		{
//			ss >> ele;
//			kinds.push_back(stol(ele, nullptr, 10));
//		}
//
//		cin >> total;
//	}
//
//	minCoins(kinds, kinds.size(), total);
//
//	return 0;
//
//}