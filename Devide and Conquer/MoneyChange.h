#pragma once
//input_5.txt
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
// Định nghĩa cấu trúc chia tiền
struct MinCoin {
	int minCoins;	// Tổng số đồng tiền nhỏ nhất
	map<int, int> numEachCoin;	// Danh sách tiền mỗi loại
};
// Hàm tính toán số đồng xu ít nhất từ các loại tiền (coins) để chia số tiền (money)
MinCoin moneyChange(vector<int> coins, int money) {
	MinCoin result;
	// Khởi tạo
	for (auto& coin : coins) {
		result.numEachCoin[coin] = 0;
	}
	// Duyệt hết các loại tiền
	for (auto& coin : coins) {
		if(coin == money) {					// Nếu giá trị đồng tiền đúng bằng số tiền
			result.numEachCoin[coin] = 1;	// Gán số đồng của loại này = 1
			result.minCoins = 1;			// Số đồng nhỏ nhất là 1

			return result;					// Trả về kết quả
		}
	}

	result.minCoins = money;
	result.numEachCoin[1] = money;
	MinCoin tmp;
	// Duyệt các loại đồng tiền hiện có
	for (auto& coin : coins) {
		if (money > coin) {	// Khi mà số tiền cần chia lớn hơn mệnh giá của đồng đang xét
			tmp = moneyChange(coins, money - coin);	// Gọi đệ quy chia tiền cho số tiền (money - coin)

			if (tmp.minCoins + 1 < result.minCoins) { // Nếu kết quả đệ quy + 1 (đồng coin) nhỏ hơn min
				result = { tmp.minCoins + 1, tmp.numEachCoin };	// gán min bằng tmp
				result.numEachCoin[coin]++;						// tăng số đồng lên 1
			}
		}
	}

	return result;
}


void test5() {
	vector<int> coins;
	vector<int> frequency(4, 0);

	long money = 0;
	string str, ele;
	stringstream ss;

	// Mo file de doc
	ifstream is("input_5.txt");

	if (is.good()) {
		getline(is, str);
		ss << str;

		while (!ss.eof())
		{
			ss >> ele;
			coins.push_back(stoi(ele, nullptr, 10));
		}

		is >> money;
	}

	MinCoin result = moneyChange(coins, money);
	
	// Xuất kết quả chia
	for (auto iter = result.numEachCoin.rbegin(); 
		iter != result.numEachCoin.rend(); ++iter) {
		cout << iter->first << ": " << iter->second << endl;
	}

}




