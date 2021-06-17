//#include <iostream>
//#include <vector>
//using namespace std;
//
//int moneyChange(vector<int> coins, int money, vector<int> &frequency) {
//	int minCoins, tmpSum = 0;
//	size_t size = coins.size();
//
//	for (size_t i = 0; i < size; i++) {
//		if (coins[i] == money) {
//			frequency[i] = 1;
//			return 1;
//		}
//	}
//
//	minCoins = money;
//
//	for (size_t i = 0; i < size; i++) {
//		if (money > coins[i]) {
//			tmpSum = 1 + moneyChange(coins, money - coins[i], frequency);
//
//			if (tmpSum < minCoins) {
//				minCoins = tmpSum;
//				frequency[i]++;
//			}
//		}
//	}
//
//	return minCoins;
//}