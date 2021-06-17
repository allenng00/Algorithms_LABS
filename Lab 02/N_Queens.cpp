///*
//1.cpp
//Giải thụật giải quyết bài toán đặt N quân hậu trên bàn cờ để chúng không ăn được nhau
//Tham khảo: Tài liệu lý thuyết
//Input: n kích thước bàn cờ
//Output:
//	+ Dòng đầu: số k thể hiện k giải pháp (có thế có)
//	+ K dòng tiếp theo: mỗi dòng biểu diễn một cách đặt quân hậu
//*/
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//vector<vector<int>> result;
//
///// <summary>
///// Hàm xuất dãy gồm num vị trí của num quân hậu, cách nhau bởi dấu phẩy. Các quân hậu nàm được đánh số từ 0 đến num - 1 tương ứng là num quân hậu
///// </summary>
///// <param name="num">số nguyên - số quân hậu/kích thước bàn cờ</param>
//void PrintfResult(int num) {
//	int size = result.size();
//	cout << size << endl;
//
//	if (size > 0) {
//		for (vector<int> ele : result) {
//
//			cout << ele[0];
//			// Dãy vị trí này cách biểu thị cho cột của num quân hậu từ (0) đến (num - 1) chứ không phải tọa độ
//			for (int pos = 1; pos < num; pos++) {
//				cout << "," << ele[pos];
//			}
//
//			cout << endl;
//		}
//	}
//}
//
///// <summary>
///// Hàm kiểm tra tính khả thi khi đặt quân hậu i tại vị trí hiện tại
///// </summary>
///// <param name="i">số nguyên - vị trí đang xét</param>
///// <param name="col">vector nguyên - bảng vị trí</param>
///// <returns>Kết quả tính triển vọng của vị trí i</returns>
//bool promising(int i, vector<int> col) {
//
//	bool flag = true;
//	int ii = 0;
//
//	while (ii < i && flag) {
//		if (col[i] == col[ii]	// Nếu chia trùng cho một hàng trước đó
//			|| abs(col[i] - col[ii]) == i - ii) { // Hoặc nếu 2 quân i và ii cùng nằm trên đường chéo
//			flag = false;
//		}
//		ii++;
//	}
//
//	return flag;
//}
//
///// <summary>
///// Giải thuật n quân hậu, tiến hành đặt num quân hậu vào num dòng
///// </summary>
///// <param name="i">số nguyên - quân hậu thứ i</param>
///// <param name="num">số nguyên - số quân hậu</param>
///// <param name="col">vector nguyên - cột mà quân hậu chiếm giữ</param>
//void n_Queens(int i, int num, vector<int>& col) {
//	// Duyệt hết mảng các vị trí từ 0 đến num - 1, đặt thử cho quân hậu i
//	for (int pos = 0; pos < num; pos++) {
//		col[i] = pos;
//
//		if (promising(i, col)) {
//
//			if (i == num - 1) { // Nếu đặt thành công num quân hậu
//				result.push_back(col); // thêm vào danh sách kết quả
//			}
//			else
//				n_Queens(i + 1, num, col);
//		}
//	}
//}
//
//
//
//int main() {
//	int num;
//
//	// Doc File
//	ifstream is("input_1.txt");
//
//	if (is.good()) {
//		is >> num;
//	}
//	else {
//		return -1;
//	}
//	is.close();
//
//	vector<int> col(num, 0);
//	// Gọi hàm xử lý
//	n_Queens(0, num, col);
//	// Xuất kết quả
//	PrintfResult(num);
//
//	return 0;
//}