#pragma once
// input_4.txt
#include <iostream>		// std::cout
#include <vector>		// std::vector
#include <algorithm>    // std::sort
#include <fstream>		// std::ifstream
using namespace std;
// Khai báo cấu trúc điểm trong không gian Oxy
struct Point { 
	double x, y; // lần lượt là hoành độ và tung độ
};
// Khái báo cấu trúc 1 cặp điểm (gồm 2 điểm)
struct Pair { Point x, y; }; 
// Cấu trúc các cặp điểm có cùng khoảng cach
struct Pairs {
	vector<Pair> pairs;	// Danh sách các cặp
	double distance;	// Khoảng cách
};

using Points = vector<Point>;
// Hàm bool xác định phần tử p1.x có nhỏ hơn p2.x hay không --> dùng để sắp xếp tăng theo hoành độ
bool xNotDec(const Point& p1, const Point& p2) {
	return p1.x < p2.x;
}
// Hàm bool xác định phần tử p1.y có nhỏ hơn p2.y hay không --> dùng để sắp xếp tăng theo tung độ
bool yNotDec(const Point& p1, const Point& p2) {
	return p1.y < p2.y;
}
// Hàm tìm bộ cặp điểm có khoảng cách giữa các cặp gần hơn
Pairs Min(const Pairs& p1, const Pairs& p2) {
	return (p1.distance < p2.distance ? p1 : p2);
}
// Hàm quá tải toán tử nhập cho một điểm
istream& operator>>(istream& In, Point& aPoint) {
	In >> aPoint.x >> aPoint.y;
	return In;
}
// Hàm quá tải toán tử xuất cho một điểm
ostream& operator<<(ostream& Out, const Point aPoint) {
	Out << "(" << aPoint.x << "," << aPoint.y << ")";
	return Out;
}
// Hàm tìm phần tử nhỏ hơn
template<class T>
T Min(const T& ele1, const T& ele2) {
	return ele1 < ele2 ? ele1 : ele2;
}
// Hàm tính khoảng cách giữa hai điểm 
double Dist(const Point& p1, const Point& p2) {
	return sqrt(
		pow(p1.x - p2.x, 2) +
		pow(p1.y - p2.y, 2));
}

Pairs ClosestPairRec(Points pPoints, Points qPoints) {
	int size = pPoints.size();
	Pairs result;
	// Tìm cặp điểm gần nhất theo cách thủ công
	if (size == 2) {
		result = { {{pPoints[0], pPoints[1]}},
			Dist(pPoints[0], pPoints[1]) };

		return result;
	}
	else if (size == 3) {
		Pair pair1 = { pPoints[0], pPoints[1] },
			pair2 = { pPoints[1], pPoints[2] },
			pair3 = { pPoints[0], pPoints[2] };
		double dist1 = Dist(pPoints[0], pPoints[1]),
			dist2 = Dist(pPoints[2], pPoints[1]),
			dist3 = Dist(pPoints[0], pPoints[2]);

		result.distance = Min(dist1, Min(dist2, dist3));

		if (dist1 == result.distance) {
			result.pairs.push_back(pair1);
		}
		if (dist2 == result.distance) {
			result.pairs.push_back(pair2);
		}
		if (dist3 == result.distance) {
			result.pairs.push_back(pair3);
		}
	}

	// Ngược lại, chia để trị
	int numEleLeft = ceil(float(size) / 2);

	double l = pPoints[numEleLeft - 1].x;
	Points pPointsL(pPoints.begin(), pPoints.begin() + numEleLeft);
	Points qPointsL(qPoints.begin(), qPoints.begin() + numEleLeft);
	Points pPointsR(pPoints.begin() + numEleLeft, pPoints.end());
	Points qPointsR(qPoints.begin() + numEleLeft, qPoints.end());

	Pairs resultL = ClosestPairRec(pPointsL, qPointsL);
	Pairs resultR = ClosestPairRec(pPointsR, qPointsR);
	result = Min(resultL, resultR);

	Points S;
	// Duyệt các điểm tối ưu (đáng xét) cho vào S
	for (Point p : qPoints) {
		if (abs(p.x - l) < result.distance) {
			S.push_back(p);
		}
	}
	int j, k = S.size();
	double tempDist;
	// Lấy các điểm trong S và tính khoảng cách giữa hai cặp điểm khác nhau, từ đó tim khoảng cách ngắn nhất
	for (int i = 0; i < k; i++) {
		j = i + 1;

		while ((j < k) && (abs(S[i].y - S[j].y) < result.distance)) {
			tempDist = Dist(S[i], S[j]);
			// Tìm khoảng cách ngắn nhất
			if (tempDist < result.distance) {
				result.distance = tempDist;
			}

			j++;
		}
	}
	result.pairs.clear();
	// Duyệt lại và tìm cặp điểm thỏa đề bài
	for (int i = 0; i < size; i++) {
		for (j = i + i; j < size; j++) {
			tempDist = Dist(pPoints[i], pPoints[j]);

			if (tempDist == result.distance) {
				result.pairs.push_back({ pPoints[i], pPoints[j] });
			}

		}
	}


	return result;
}
// Hàm tìm các cặp điểm có khoảng cách gần nhất
Pairs ClosestPair(Points pPoints) {
	Points qPoints = pPoints;

	sort(pPoints.begin(), pPoints.end(), xNotDec);	// Sắp xếp Q tăng theo hoành độ (x)
	sort(qPoints.begin(), qPoints.end(), yNotDec);	// Sắp xếp Q tăng theo tung độ (y)

	Pairs result = ClosestPairRec(pPoints, qPoints);

	return result;
}
// Hàm xuất output như yêu cầu
void Output(const Pairs& aPairs) {
	for (Pair pair : aPairs.pairs) {
		cout << pair.x << " " << pair.y << endl;
	}
}

void test4() {
	Point tPoint;
	Points pPoints;
	int num;
	// Khai báo biến đọc file
	ifstream is("input_4.txt");
	// Đọc file
	if (is.good()) {
		is >> num;

		for (int i = 0; i < num; i++) {
			is >> tPoint;

			pPoints.push_back(tPoint);
		}
	}
	// Gọi hàm tìm những cặp có khoảng cách ngắn nhất
	Pairs result = ClosestPair(pPoints);
	// Xuất các cặp
	Output(result);
}