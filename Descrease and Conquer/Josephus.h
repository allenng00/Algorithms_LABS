#pragma once
// input2.txt
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Hàm Josephus
void Josephus(int num) {
	int step = 1; // giết người bên cạnh
	vector<int> people;
	for (int i = 0; i < num; i++) {
		people.push_back(i + 1);
	}
	int index = step; // Người đầu tiên được chết

	while (people.size() > 1) {
		cout << people[index] << " ";
		people.erase(people.begin() + index);	// xóa sổ người ở vị trí index, người vị trí index hiện tại sẽ là sát thủ tiếp theo
		index = (index + step) % people.size(); // tính vị trí người bị giết mới: index + step, lấy phần dư nếu vượt quá giới hạn mảng
																
	}

	cout << endl << people[0] << endl;
}

void test2() {
	int num;
	ifstream is("input2.txt");
	// Đọc file
	if (is.good()) {
		is >> num;
	}
	// Gọi Josephus
	Josephus(num);
}