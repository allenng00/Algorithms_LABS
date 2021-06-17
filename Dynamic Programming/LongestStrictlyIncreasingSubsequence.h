#pragma once
// input_4.txt
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int max(vector<vector<int>> an2DArray) {
	int size = an2DArray.size(), max = an2DArray[0].size();
	int i, imax = 0;
	for (i = 1; i < size; i++) {
		if (an2DArray[i].size() > max) {
			max = an2DArray[i].size();
			imax = i;
		}
	}

	return imax;
}

vector<int> LSIS_DP(vector<int> anArray) {
	int size = anArray.size();
	vector<vector<int>> L(size, vector<int>());
	for (int i = 0; i < size; i++) {
		L[i].push_back(anArray[i]);
	}

	vector<int> temp;

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if ((anArray[j] < anArray[i])
				&& (L[j].size() + 1 > L[i].size())) {
				temp = L[j];
				temp.push_back(anArray[i]);
				L[i] = temp;
			}
		}
	}

	return L[max(L)];
}

void test4() {
	vector<int> array;
	ifstream is("input_4.txt");
	int num, ele;

	if (is.good()) {
		is >> num;

		for (int i = 0; i < num; i++) {
			is >> ele;

			array.push_back(ele);
		}
	}



	vector<int> result = LSIS_DP(array);

	for (int item : result) {
		cout << item << " ";
	}
	cout << endl << result.size() << endl;
}
