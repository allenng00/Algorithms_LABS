#pragma once
// input_8.txt 8.cpp
// Giải thuật tìm đường đi người bán hàng
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



void test8() {
	int num;
	int i, j, w;
	int bestWeight = INT_MAX;
	char ch;

	// Mo file de doc
	ifstream is("input_8.txt");

	is >> num;
	vector<vector<long>> graph(num, vector<long>(num, 0));
	vector<long> path(num, -1);
	vector<long> bestPath(num + 1, 0);
	vector<string> temp;

	do {
		is >> i;
		if (i == -1) {
			break;
		}

		is >> j >> w;
		graph[i - 1][j - 1] = w;
		graph[j - 1][i - 1] = w;

	} while (true);
}