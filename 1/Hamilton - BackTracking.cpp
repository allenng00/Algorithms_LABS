// 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Giải thuật tìm đường đi ngắn nhất qua tất cả các điểm và trở về điểm xuất phát
// Tham khảo:  https://www.bugs.vn/io/PnEiB
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

/// <summary>
/// hàm kiểm tra điểm v có khả thi trong lộ trình hay không
/// </summary>
/// <param name="graph"></param>
/// <param name="path"></param>
/// <param name="pos"></param>
/// <param name="v"></param>
/// <returns></returns>
bool promising(vector<vector<int>> graph, vector<int> path, int pos, int v) {

	if (pos == (graph.size() - 1) && graph[v][path[0]] == 0) {
		return false;
	}
	else {

		if (graph[path[pos - 1]][v] == 0) {
			return false;
		}
		else {

			// Kiểm tra trong quá khứ đã đi qua v chưa
			for (int i = 0; i < pos; i++) {
				if (path[i] == v) {
					return false;
				}
			}

		}
	}
	return true;
}

/// <summary>
/// Hàm tim đường đi Haminton tốt nhất
/// </summary>
/// <param name="graph"></param>
/// <param name="bestPath"></param>
/// <param name="bestWeight"></param>
/// <param name="path"></param>
/// <param name="pos"></param>
void Hamiltonian(
	vector<vector<int>> graph,
	vector<int>& bestPath, int& bestWeight,
	vector<int>& path, int pos) {
	int n = graph.size();

	if (pos == n) {
		int tempWeight = 0;

		for (int i = 0; i < n - 1; i++) {
			tempWeight += graph[path[i]][path[i + 1]]; // Tăng trọng số
		}

		tempWeight += graph[path[n - 1]][path[0]];	// Tăng trọng số của quảng đường từ đỉnh thứ n - 1 về đỉnh thứ 0

		if (tempWeight < bestWeight) {
			bestWeight = tempWeight;

			for (int i = 0; i < n; i++) {
				bestPath[i] = path[i];
			}

			bestPath[n] = path[0];
		}
	}
	else {
		for (int v = 0; v < graph.size(); v++) {
			if (promising(graph, path, pos, v)) {
				path[pos] = v;
				// Gọi đệ quy tìm đường đi cho vị trí thứ pos + 1
				Hamiltonian(graph, bestPath, bestWeight, path, pos + 1);
			}
		}
	}
}

int main() {
	int n;
	int i, j, w;
	int bestWeight = INT_MAX;
	char ch;
	string line;
	string ele;
	stringstream ss;

	// Mo file de doc
	freopen("input_5.txt", "r", stdin);

	getline(cin, line);
	n = stoi(line);
	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<int> path(n, 0);
	vector<int> bestPath(n + 1, 0);
	vector<string> temp;

	while (!feof(stdin)) {
		getline(cin, line);

		if (line != "-1") {
			ss << line;
			temp.clear();

			while (!ss.eof()) {
				ss >> ele;
				temp.push_back(ele);
			}

			i = stoi(temp[0]);
			j = stoi(temp[1]);
			w = stoi(temp[2]);
			graph[i - 1][j - 1] = w;
			graph[j - 1][i - 1] = w;

			ss.clear();
		}
	}

	// Gọi hàm tìm đường đi Hamilton ngắn nhất
	Hamiltonian(graph, bestPath, bestWeight, path, 1);

	for (int i = 0; i < n; i++) {
		cout << bestPath[i] + 1 << " ";
	}

	cout << endl << bestWeight << endl;

	return 0;
}