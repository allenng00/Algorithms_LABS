#pragma once

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int Max(const int& x1, const int& x2) {
	return (x1 > x2 ? x1 : x2);
}

void Trace() {

}

void BestWay(vector<vector<int>> source) {
	int size = source.size() + 1;

	vector<vector<int>> Table(size, vector<int>(size, 0));

	for (int idr = 1; idr < size; idr++) {
		for (int idc = 1; idc <= idr; idc++) {
			Table[idr][idc] = Max(Table[idr - 1][idc - 1], Table[idr - 1][idc]) + source[idr - 1][idc - 1];
		}
	}
	int max = Table[size - 1][0], idy, idx = size - 1;

	for (int i = 2; i < size; i++) {
		if (Table[idx][i] > max) {
			max = Table[idx][i];
			idy = i;
		}
	}
	cout << max << endl;

	vector<int> result(1, idy);

	while (idx > 1) {
		if (Table[idx - 1][idy - 1] > Table[idx - 1][idy]) {
			result.insert(result.begin(), --idy);
		}
		else {
			result.insert(result.begin(), idy);
		}

		idx--;
	}

	for (int i = 0, j = 0; i < size - 1; i++, j++) {
		cout << source[j][result[i] - 1] << " ";
	}

}

void test1() {
	vector<vector<int>> source;
	int num, ele;
	ifstream is("input_1.txt");

	if (is.good()) {
		is >> num;

		for (int i = 0; i < num; i++) {
			vector<int> temp(i + 1, 0);

			for (int j = 0; j <= i; j++) {
				is >> temp[j];
			}

			source.push_back(temp);
		}
	}

	BestWay(source);
}