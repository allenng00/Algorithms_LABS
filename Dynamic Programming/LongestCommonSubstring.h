#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int max(const int& x1, const int& x2) {
	return (x1 > x2 ? x1 : x2);
}

string max(const string& s1, const string& s2) {
	return (s1.length() > s2.length() ? s1 : s2);
}


string LCS_DP(string s1, string s2) {
	int len1 = s1.length(),
		len2 = s2.length();
	vector<vector<string>> L(len1 + 1, vector<string>(len2 + 1, ""));

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + s1[i - 1];
			}
			else {
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
	}

	return L[len1][len2];
}

void test3() {
	string s1, s2;
	ifstream is("input_3.txt");

	if (is.good()) {
		getline(is, s1);
		getline(is, s2);
	}
	else {
		cout << "Mo file khong thanh cong." << endl;
		return;
	}

	cout << LCS_DP(s1, s2) << endl;
}