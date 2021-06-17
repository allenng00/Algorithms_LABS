#pragma once
// input_3.txt
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
// Khai báo cấu trúc đối tượng để lưu mảng con
struct subArray {
	int start;	// vị trí bắt đầu
	int end;	// vị trí kết thúc
	long sum = 0;	// tổng các phần tử của mảng con này
};
// Hàm tim ra dãy con có tổng lớn hơn
subArray GetMax(const subArray& a, const subArray& b) {
	return (a.sum > b.sum ? a : b);
}
// Hàm tìm tổng dãy con có tổng lớn nhất, trả về đối tượng subArray
subArray SumSubArrayMax(vector<int> array, int l, int r) {
	if (l == r) {
		return 	GetMax(
			{ l, r, array[l] },
			{ l, r, 0 }
		);
	}

	int mid = (l + r) / 2;
	subArray tmp,
		maxLpartS = { mid, mid, 0 },
		maxRpartS = { mid + 1, mid + 1, 0 };
	subArray result;

	subArray maxLS = SumSubArrayMax(array, l, mid);		// Tổng lớn nhất của dãy con từ nữa mảng bên trái
	subArray maxRS = SumSubArrayMax(array, mid + 1, r);	// Tổng lớn nhất của dãy con từ nữa mảng bên phải

	tmp = maxLpartS;
	// Tính tổng lớn nhất của dãy con bên trái tính từ phẩn tử mid về trước
	for (int i = mid; i >= l; i--) {
		tmp.sum += array[i];
		tmp.start = i;

		if (tmp.sum > maxLpartS.sum) {
			maxLpartS = tmp;
		}
	}
	tmp = maxRpartS;
	// Tính tổng lớn nhất của dãy con bên phải tính từ phẩn tử mid + 1 về sau
	for (int i = mid + 1; i <= r; i++) {
		tmp.sum += array[i];
		tmp.end = i;

		if (tmp.sum > maxRpartS.sum) {
			maxRpartS = tmp;
		}
	}
	// Gán tmp là dãy con có tổng lớn nhất ghép từ L-part và R-part
	tmp = { maxLpartS.start, maxRpartS.end, maxLpartS.sum + maxRpartS.sum };
	// Tìm dãy con có tổng lớn nhất
	result = GetMax(tmp, GetMax(maxLS, maxLS));

	return result;
}
// Hàm xuất output theo yêu cầu
void Output(vector<int> array, subArray result) {
	for (int pos = result.start; pos <= result.end; pos++) {
		cout << array[pos] << " ";
	}
	cout << endl << result.start << " " << result.end << endl
		<< result.sum << endl;
}

void test3() {
	vector<int> array;
	int num = 0, ele = 0;
	ifstream is("input_3.txt");
	// Đọc file
	if (is.good()) {
		is >> num;

		if (num > 0) {

			for (int i = 0; i < num; i++) {
				is >> ele;
				array.push_back(ele);
			}
		}
		else {
			cout << "So luong phan tu can khac 0." << endl;
			return;
		}
	}
	// Gọi hàm tìm 
	subArray result = SumSubArrayMax(array, 0, num - 1);
	// Xuất output
	Output(array, result);
}