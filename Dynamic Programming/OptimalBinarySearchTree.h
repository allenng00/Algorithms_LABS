#pragma once
// input_5.txt 5.cpp
// Giải thuật cây nhị phân tìm kiếm tối ưu
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
typedef struct Node* NODE;
struct Node {
	int key;
	NODE left;
	NODE right;
};
bool check(int i, int low, int high) {
	return (i >= low && i <= high);
}

NODE tree(vector<int> keys, vector<vector<int>> R, int i, int j) {
	if (!check(i, 0, keys.size() - 1) ||
		!check(j, 0, keys.size() - 1) || !(i <= j))
		return NULL;

	int t = R[i][j];

	NODE p = new Node();
	p->key = keys[t];
	p->left = tree(keys, R, i, t - 1);
	p->right = tree(keys, R, t + 1, j);

	return p;
}

void LNR(NODE root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		LNR(root->left);
		LNR(root->right);
	}
}

float sum(vector<float>props, int i, int j) {
	float sum = 0;

	if (i <= i && i >= 0 && j <= props.size() - 1) {
		for (int pos = i; pos <= j; pos++) {
			sum += props[pos];
		}
	}

	return sum;
}

vector<vector<int>> OptimalBST(vector<float> props) {
	int n = props.size();

	vector<vector<float>> cost(n, vector<float>(n, 0));
	vector<vector<int>> root(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		cost[i][i] = props[i];
		root[i][i] = i;
	}
	int j, value, pos;
	float minVal;
	for (int diag = 1; diag <= n; diag++) {
		for (int i = 0; i < n - diag + 1; i++) {
			j = i + diag - 1;
			minVal = INT_MAX;

			for (int t = i; t <= j; t++) {
				value =
					(t > i ? cost[i][t - 1] : 0) +
					(t < j ? cost[t + 1][j] : 0);

				if (value < minVal) {
					minVal = value;
					pos = t;
				}
			}

			root[i][j] = pos;
			cost[i][j] = minVal + sum(props, i, j);
		}
	}
	return root;
}

void test5() {
	int num, key, prop;
	vector<int> keys;
	vector<float> props;

	ifstream is("input_5.txt");

	if (is.good()) {
		is >> num;

		keys.resize(num);
		props.resize(num);

		for (int i = 0; i < num; i++) {
			is >> keys[i] >> props[i];
		}
	}
	vector<vector<int>> R(num, vector<int>(num));
	R = OptimalBST(props);
	NODE root = tree(keys, R, 0, num - 1);
	LNR(root);
	cout << endl << root->key << endl;
}