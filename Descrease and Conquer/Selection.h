#pragma once
// input3.txt
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int Partition(vector<float>& array, int lower, int upper, int pos);
// Hàm chọn phần tử nhỏ thứ k trong khoảng từ lower --> upper của mảng array
float Selection(vector<float>& array, int lower, int upper, int k) {
	int h;
	h = upper > lower ?
		rand() % (upper - lower) + lower :
		lower;
	int pos = Partition(array, lower, upper, h); // array[pos] = pivot

	if (pos == k - 1) {
		return array[pos];
	}
	else if (pos > k - 1) {
		return Selection(array, lower, pos - 1, k);
	}
	else {
		return Selection(array, pos + 1, upper, k);
	}
}
// Hàm tìm vị trí tối ưu
int Partition(vector<float>& array, int lower, int upper, int pos) {

	float pivot = array[pos];
	swap(array[lower], array[pos]);
	pos = lower;

	for (int i = lower + 1; i <= upper; i++) {
		if (pivot > array[i]) {
			pos++;
			swap(array[i], array[pos]);
		}
	}

	swap(array[lower], array[pos]);
	return pos;
}

void test3() {

	vector<float> array;
	int num, k;
	float ele;
	ifstream is("input3.txt");
	// Đọc file
	if (is.good()) {
		is >> num;

		for (int i = 0; i < num; i++) {
			is >> ele;
			array.push_back(ele);
		}

		is >> k;
	}
	else {
		cout << "Mo file khong thanh cong" << endl;
		return;
	}
	// gọi hàm tìm phần tử nhỏ thứ k
	cout << Selection(array, 0, num - 1, k);
}