#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
struct MinCoin {
	vector<int> minCoins;
	vector<int> lastCoin;
};

MinCoin MoneyChange(vector<int> coins, int money) {
	int k = coins.size();
	MinCoin result = { vector<int>(money + 1, 0), vector<int>(money + 1, 1) };
	result.lastCoin[0] = 0;

	for (int m = 1; m <= money; m++) {
		int minCoins = m;

		for (int i = 0; i < k; i++) {
			if (coins[i] > m)
				continue;

			if (result.minCoins[m - coins[i]] + 1 < minCoins) {
				minCoins = result.minCoins[m - coins[i]] + 1;
				result.lastCoin[m] = coins[i];
			}
		}
		result.minCoins[m] = minCoins;
	}
	return result;
}

void Trace(vector<int> coins, int money, vector<int> lastCoin) {
	int size = coins.size();
	int index = money, last, pos;
	vector<int> numEachCoin(size, 0);

	while (index > 0) {
		last = lastCoin[index];

		pos = find(coins.begin(), coins.end(), last) - coins.begin();
		if (pos < size)
			numEachCoin[pos]++;

		index -= last;
	}

	for (int pos = 0; pos < size; pos++) {
		cout << coins[pos] << ": " << numEachCoin[pos] << endl;
	}
}

void test2() {
	int money = 0;
	string str, ele;
	stringstream ss;
	vector<int> coins;

	// Mo file de doc
	ifstream is("input_2.txt");

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

	MinCoin result = MoneyChange(coins, money);

	Trace(coins, money, result.lastCoin);
}
