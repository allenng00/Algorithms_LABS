#pragma once
//input_6.txt
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void print(const vector<int>& aSubset)
{
	int size = aSubset.size();

	for (int i = size - 1; i >= 0; i--) {
		cout << aSubset[i] << " ";
	}
}

void printSubset(
	vector<int> arr, vector<vector<int>> V,
	int i, int k, vector<int>& aSubset)
{
	// Nếu i bằng 0 mà tổng k còn khác 0
	// Thì xét xem khả năng của arr[1] = k;
	// Nếu i bằng 0 mà tổng cũng bằng 0 thì xuất kết quả
	if (i == 0) {
		if (k != 0 && V[1][k] == 1)
		{
			aSubset.push_back(arr[i]);
			// Nếu bằng k, xuất mảng kết quả
			if (arr[i] == k) {

				print(aSubset);
				cout << endl;
			}
			return;
		}

		if (k == 0)
		{
			print(aSubset);
			cout << endl;
			return;
		}

	}


	// Bỏ qua phân tử thứ i đang xét và xét đến i - 1
	// Dùng một bộ kết quả mới new_ss để không làm ảnh hướng đến aSubset
	if (V[i - 1][k] == 1)
	{
		vector<int> new_ss = aSubset;
		printSubset(arr, V, i - 1, k, new_ss);
	}

	// Xét phần tử thứ i, nếu tồn tại mảng con, thêm a[
	if (k >= arr[i - 1] &&
		V[i - 1][k - arr[i - 1]] == 1)
	{
		aSubset.push_back(arr[i - 1]);
		printSubset(arr, V, i - 1, k - arr[i - 1], aSubset);
	}
}


void SubsetSumsDP(vector<int> anArray, int k) {
	int n = anArray.size(), temp;
	vector<vector<int>> V(n + 1, vector<int>(k + 1, 0));

	for (int i = 0; i <= n; i++) {
		V[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			temp = 0;

			if (j >= anArray[i - 1]) {
				temp = V[i - 1][j - anArray[i - 1]];
			}

			V[i][j] = V[i - 1][j] || temp;
		}
	}

	// Xuất kết quả tìm được
	vector<int> p;
	printSubset(anArray, V, n, k, p);
}

void test6() {
	vector<int> array;
	int num, ele, k;

	ifstream is("input_6.txt");

	if (is.good()) {
		is >> num;

		for (int i = 0; i < num; i++) {
			is >> ele;

			array.push_back(ele);
		}

		is >> k;
	}
	else {
		cout << "Mo file khong thanh cong." << endl;
		return;
	}

	SubsetSumsDP(array, k);
}