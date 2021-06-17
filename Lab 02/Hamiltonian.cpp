///*
//5.cpp
//Giải thuật đường đi Hamminton
//*/
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
///// <summary>
///// Hàm kiểm tra tính triển vọng của một đỉnh trong đường đi tại vị trí pos
///// </summary>
///// <param name="pos">số nguyên - vị trí hiện tại của đường đi</param>
///// <param name="v">số nguyên - đỉnh muốn xét</param>
///// <param name="num">số nguyên - số loại đỉnh</param>
///// <param name="path">vector số nguyên - giải pháp đang xét</param>
///// <param name="graph">vector 2 chiều nguyên - ma trận kề biểu diện đồ thị</param>
///// <returns></returns>
//bool promissing(
//	long pos, long v, long num,
//	vector<long> path, vector<vector<long>> graph) {
//	// Nếu không có đường đi từ vị trí pos - 1 đến vị trí v (trừ 1 là do đỉnh đánh số từ 1)
//	if (graph[path[pos - 1] - 1][v - 1] == 0) {
//		return false;
//	}
//	else {
//		for (long i = 0; i < pos; i++) {
//			if (path[i] == v) {
//				return false;
//			}
//		}
//	}
//
//	if (pos == num - 1 && graph[v - 1][path[0] - 1] == 0) {
//		return false;
//	}
//	return true;
//
//}
//
///// <summary>
///// Hàm tìm kím đường đi Haminton ngắn nhất cho người đi bán hàn
///// </summary>
///// <param name="pos">số nguyên - đanh số vị trí đang đi</param>
///// <param name="num">số nguyên - số lượng thành phố</param>
///// <param name="graph">vector chứa vector nguyên - ma trận kề các điểm</param>
///// <param name="bestPath">vector nguyên - chứa đường đi tốt nhất</param>
///// <param name="bestWeight">số nguyên - độ dài tốt nhất</param>
///// <param name="path">vector nguyên - chứa đường đi hiện tại</param>
//void Hamiltonian(
//	long pos, long num,
//	vector<vector<long>>graph,
//	vector<long>& bestPath, long& bestWeight,
//	vector<long>& path) {
//
//	if (pos == num) {
//		long tmpWeight = 0;
//
//		for (long i = 0; i < num - 1; i++) {
//			tmpWeight += graph[path[i] - 1]
//								[path[i + 1] - 1]; // Tăng trọng số
//		}
//
//		tmpWeight += graph[path[num - 1] - 1]
//							[path[0] - 1];	// Tăng trọng số của quảng đường từ đỉnh thứ n - 1 về đỉnh thứ 0
//
//		if (tmpWeight < bestWeight) {
//			bestWeight = tmpWeight;
//
//			for (int i = 0; i < num; i++) {	// Sao chécp đường đi
//				bestPath[i] = path[i];
//			}
//
//			bestPath[num] = path[0];
//		}
//	}
//	else {
//		// Duyệt hết các đỉnh
//		for (long v = 1; v <= num; v++) {
//
//			if (promissing(pos, v, num, path, graph)) { // Nếu có triển vọng 
//				path[pos] = v;	// Thêm v vào đường đi
//				Hamiltonian(pos + 1, num, graph, bestPath, bestWeight, path); // Gọi đệ quy cho vị trí tiếp theo
//			}
//		}
//	}
//}
//
//int main() {
//	long num;
//	long i, j, w;
//	long bestWeight = LONG_MAX;
//	char ch;
//
//	// Mo file de doc
//	ifstream is("input_5.txt");
//
//	is >> num;
//	vector<vector<long>> graph(num, vector<long>(num, 0));
//	vector<long> path(num, -1);
//	vector<long> bestPath(num + 1, 0);
//	vector<string> temp;
//
//	do {
//		is >> i;
//		if (i == -1) {
//			break;
//		}
//
//		is >> j >> w;
//		graph[i - 1][j - 1] = w;
//		graph[j - 1][i - 1] = w;
//
//	} while (true);
//
//	path[0] = 1;	// Điểm khởi đầu
//	Hamiltonian(1, num, graph, bestPath, bestWeight, path);
//	// Xuất đường đi cầnn tìm
//	for (int i = 0; i <= num; i++) {
//		cout << bestPath[i] << " ";
//	}
//	// Xuất ra chi phí tốt nhất
//	cout << endl << bestWeight << endl;
//
//	return 0;
//}