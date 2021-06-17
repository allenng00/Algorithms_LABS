#pragma once
// input4.txt
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
// Tìm kiếm nội suy phần tử k trong khoảng lower -> upper của array 
int InterpolationSearch(vector<float> array, int lower, int upper, float k)
{
	int pos;

	if (lower <= upper &&
		k >= array[lower] &&
		k <= array[upper]) {
		// Tím toán vị trí tối ưu
		pos = lower
			+ (((double)(upper - lower) / (array[upper] - array[lower]))
				* (k - array[lower]));

		if (array[pos] == k) {
			return pos;
		}
		else if (array[pos] < k) {	
			return InterpolationSearch(array, pos + 1, upper, k); // Tìm bên trái
		}
		else {
			return InterpolationSearch(array, lower, pos - 1, k);	// Tìm bên phải
		}
	}

	return -1;	// Không tìm thấy
}

void test4() {
	vector<float> array;
	int num;
	float ele, k;
	ifstream is("input4.txt");
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

	cout << InterpolationSearch(array, 0, num - 1, k);
}