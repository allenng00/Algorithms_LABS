//// 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Giải thuật
//// Tham khảo: Tài liệu của giảng viên lý thuyết
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <numeric>
//#include <algorithm>
//
//
//using namespace std;
//// Định nghĩa hằng số thực pi
//const double pi = 3.14159265358979323846;
//
//// Định nghĩa cấu trúc dữ liệu điểm
//struct point {
//	double x;
//	double y;
//};
//
///// <summary>
///// Quá tải toán tử so sánh cho hai đối tượng point
///// </summary>
///// <param name="a">Điểm thứ nhất</param>
///// <param name="b">Điểm thứ hai</param>
///// <returns>Giá trị luận lý tương ứng sự giống nhau (True) và khác nhau (False)</returns>
//bool operator== (point a, point b) {
//	return (a.x == b.x && a.y == b.y);
//}
//
///// <summary>
///// Hàm so sánh hai điểm
///// </summary>
///// <param name="a">Điểm thứ nhất</param>
///// <param name="b">Điểm thứ hai</param>
///// <returns></returns>
//bool cmp(point a, point b) {
//	return (a.x < b.x || (a.x == b.x && a.y < b.y));
//}
//
///// <summary>
///// Hàm tính toán góc giữa đoạn thẳng nối 2 điểm so với chiều dương trục Ox
///// </summary>
///// <param name="src">Điểm thứ nhất</param>
///// <param name="dest">Điểm thứ hai</param>
///// <returns></returns>
//double computeAngle(point src, point dest) {
//	double angle = atan2(dest.y - src.y, dest.x - src.x);
//
//	if (angle < 0) {
//		angle += 2 * pi;
//	}
//
//	return angle;
//}
//
///// <summary>
///// Hàm tìm điểm tiếp theo mà thuật toán sẽ xét đến
///// </summary>
///// <param name="points">Tập hợp các điểm</param>
///// <param name="curPoint">Điểm hiện tại đang xét</param>
///// <param name="curAngle">Góc hiện tại</param>
///// <returns></returns>
//pair<point, double> findNextExtremePoint(vector<point> points, point curPoint, double curAngle) {
//	// Khai báo giá trị cần thiết
//	double minAngle = 2 * pi;	// Góc nhỏ nhất
//	double angle;			
//	point next;
//
//	// Duyệt các điểm trong tập điểm
//	for (point p : points) {
//
//		if (p == curPoint) {
//			continue;
//		}
//
//		angle = computeAngle(curPoint, p);	// Tính góc
//
//		if (angle < minAngle && angle >= curAngle) {
//			next = p;
//			minAngle = angle;
//		}
//	}
//
//	return make_pair(next, minAngle);
//}
//
///// <summary>
///// Hàm tìm tập điểm tạo thành đa giác lồi trong tập điểm ban đầu
///// </summary>
///// <param name="points">Tập hợp các điểm cần xét</param>
///// <returns>Tập hợp mới chứa các điểm tạo thành đa giác lồi</returns>
//vector<point> computeConvexHull(vector<point> points) {
//	// Khai báo các biến cần thiết
//	vector<point> convexHull;	// Tập hợp điểm thỏa bài toán
//	double curAngle = 0;		// Góc hiện tại
//	point first = points[0];	// Điểm đầu tiên xét
//	point cur = first;			// Điểm hiện tại đang xét
//	pair<point, double> temp;	// Biến lấy dữ liệu từ hàm findNextExtremePoint
//	convexHull.push_back(first);// Thêm điểm đầu vào chuỗi kết quả
//
//	// Duyệt các điểm
//	while (true) {
//		temp = findNextExtremePoint(points, cur, curAngle);
//		curAngle = temp.second;
//
//		// Nếu trùng với điểm đầu thi dừng
//		if (first == temp.first) {
//			break;
//		}
//
//		// Thêm điểm tiếp theo thỏa yêu cầu
//		convexHull.push_back(temp.first);
//		cur = temp.first;
//	}
//
//	return convexHull;
//}
//
//
//int main() {
//	int n;
//	vector<point> points;
//	vector<point> result;
//
//	// Đọc file
//	freopen("input_4.txt", "r", stdin);
//
//	while (!feof(stdin)) {
//		cin >> n;
//
//		points.resize(n);
//
//		for (int i = 0; i < n; i++) {
//			cin >> points[i].x >> points[i].y;
//		}
//	}
//
//	// Sắp xếp hệ điểm
//	sort(points.begin(), points.end(), cmp);
//
//	// Gán biến result bằng tập hợp con các điểm thỏa đề bài
//	result = computeConvexHull(points);
//
//	// Duyệt và xuất kết quả
//	for (point p : result) {
//		cout << "(" << p.x << "," << p.y << ") ";
//	}
//	cout << endl;
//
//	return 0;
//}