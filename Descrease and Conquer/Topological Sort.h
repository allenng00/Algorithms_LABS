#pragma once
// input1.txt
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;

using List = list<int>;
using Iter = list<int>::iterator;

// Hàm sắp xếp Tôp các công việc có sự phụ thuộc
void TopologicalSort(vector<List> aGraph) {
	int num = aGraph.size();
	vector<int> inDegree(num, 0);

	Iter pos;
	queue<int> Q;

	for (int i = 0; i < num; i++) {
		inDegree[i] = aGraph[i].size();
	}

	for (int i = 0; i < num; i++) {
		if (inDegree[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		cout << u + 1 << " ";

		int v;
		for (int v = 0; v < num; v++) {
			List ii = aGraph[v];
			pos = find(ii.begin(), ii.end(), u);

			if (pos != ii.end()) {
				if (--inDegree[v] == 0) {
					Q.push(v);
				}
			}

		}
	}
}

void test1() {
	vector<List> graph;
	int num, ele, start;
	string line;
	stringstream ss;
	ifstream is("input1.txt");
	List temp;
	// Đọc file
	if (is.good()) {
		is >> num;
		graph.resize(num);

		do {
			is >> start;

			if (start == 0) {
				break;

			}
			else {

				getline(is, line);
				ss << line;

				while (!ss.eof()) {
					ss >> ele;
					temp.push_back(ele - 1);
				}
				graph[start - 1] = temp;
				temp.clear();
				ss.clear();
			}

		} while (true);
	}
	else {
		cout << "Mo file khong thanh cong." << endl;
		return;
	}
	// Gọi hàm sắp xếp
	TopologicalSort(graph);
	cout << endl;
}