///*
//2.cpp
//Bài toàn mã đi tuần
//Input: n, r0, c0 là kích thước bàn cờ và vị trí đầu tiên của quân mã
//Output:
//	+ Dòng đầu: số k thể hiện k giải pháp (có thế có)
//	+ K dòng tiếp theo: mỗi dòng biểu diễn một cách đi của quân hậu
//*/
//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
///// <summary>
///// Định nghĩa cấu trúc tọa độ trong bàn cờ
///// Gồm 2 thuộc tính x, y tương ứng là số hiệu dòng và cột của một
///// </summary>
//struct coord {
//	long x, y;
//};
//
//int COUNT = 0;
//// Mảng lưu 8 tọa độ dòng và cột mà quân mã có thể đi
//vector<long> rows = { 2, 1, -1, -2, -2, -1, 1, 2 };
//vector<long> cols = { 1, 2, 2, 1, -1, -2, -2, -1 };
//// Mảng lưu kết quả đi khả thi
//vector<vector<coord>> result;
//
//
///// <summary>
///// Kiểm tra tọa độ nằm trong bảng
///// </summary>
///// <param name="u">số nguyên - tọa độ dòng</param>
///// <param name="v">số nguyên - tọa độ cột</param>
///// <param name="num">kích thước</param>
///// <returns>luận lí - kết quả kiểm tra</returns>
//bool checkPosition(long u, long v, long num) {
//	return (0 <= u && 0 <= v) && (u < num&& v < num);
//}
//
///// <summary>
///// Hàm xuất các kết quả khả thi
///// </summary>
///// <param name="num"></param>
//void PrintPaths(long num) {
//	long size = result.size();
//	cout << size << endl;
//
//	if (size > 0) {
//		long end = num * num;
//
//		for (vector<coord>path : result) {	// Duyệt trong bảng kết quả
//
//			// Xuất đường đi hợp lệ theo dòng, với các tọa độ cách nhau bởi dấu ", "
//			cout << "(" << path[0].x << "," << path[0].y << ")";
//
//			for (long pos = 1; pos < end; pos++)
//			{
//				cout << ", (" << path[pos].x << "," << path[pos].y << ")";
//			}
//
//			cout << endl;
//		}
//	}
//}
//
///// <summary>
///// Hàm thực hiện mã đi tuần, đi tìm các cách đi hết bàn cờ kích thước num, từ vị trí bắt đầu có tọa độ {r, c}
///// </summary>
///// <param name="i">số nguyên - bước đi thứ i</param>
///// <param name="r">số nguyên - tọa độ dòng</param>
///// <param name="c">số nguyên - tọa độ cột</param>
///// <param name="num">số nguyên - kích thước bàn cờ</param>
///// <param name="board">vector 2 chiều nguyên - bàn cờ</param>
///// <param name="curPath">vector tọa độ - đường đi hiện tại</param>
//void KnightTour(
//	long i, long r, long c, long num,
//	vector<vector<long>> board,
//	vector<coord> curPath) {
//	long u = 0, v = 0;
//	long end = num * num - 1;
//	// Thử từng bước đi trong 8 ô xung quanh ô hiện tại
//	for (int k = 0; k < 8; k++) { 
//		u = r + rows[k];
//		v = c + cols[k];
//
//		if (checkPosition(u, v, num)	// Nếu vị trí nằm trong bàn cờ
//			&& (board[u][v] == -1)) {	// và chưa được đi
//
//			board[u][v] = i;			// Đánh dấu ô này được đi
//			curPath[i] = { u, v };		// Thêm {u, v} vào quy trình
//
//			if (i == end) {				// Nếu đi đủ hết các ô trên bàn cờ
//				result.push_back(curPath);	// Thêm đường đi hiện tại vào danh sách lời giải
//			}
//			else
//				KnightTour(i + 1, u, v, num, board, curPath); // Gọi đệ quy bước thứ i + 1
//			board[u][v] = -1;	// Nếu đi không thành, trả trạng thái ô {u, v} về chưa đi
//		}
//	}
//}
//
//
//
//int main() {
//	// Khai báo biến
//	long num, r, c;
//	char ch;
//
//
//	// Doc File
//	ifstream is("input_2.txt");
//
//	if (is.good()) {
//		is >> num >> r >> ch >> c;
//
//		if (num > 0 && checkPosition(r, c, num)) {
//
//		}
//		else {
//			return -1;
//		}
//	}
//	else {
//		return -1;
//	}
//
//	vector<vector<long>> board(num, vector<long>(num, -1));
//	vector<coord> path(num * num);
//
//	board[r][c] = 0;	// Đánh dấu {r, c} đã đi trên bàn cờ
//	path[0] = { r, c };	// Điểm bắt đầu là {r, c}
//
//	// Gọi hàm mã đi tuần
//	KnightTour(1, r, c, num, board, path);
//	// Xuất những đường đi khả thi
//	PrintPaths(num);
//
//	return 0;
//}