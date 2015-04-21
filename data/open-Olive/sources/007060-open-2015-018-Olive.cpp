#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/*vector<int> fen;

int get(int i) {
	int ans;
	while (i < n) {
		ans += fen[i];
		i = i | (i + 1);
	}
	return ans;
}

int add(int i, int x) {
	while (i >= 0) {
		fen[i] += x;
		i = i & (i + 1);
	}
}*/

vector<int> in;
vector<int> countT;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int c = 0;
	int n;
	cin >> n;
	in.resize(n);
	countT.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> in[i];
	}

	pair<int, int> pos = make_pair(-1, -1);
	int ans = 0;
	int minAns = 0;
	for (int i = 0; i < (int)in.size(); ++i) {
		for (int j = i + 1; j < (int)in.size(); ++j) {
			if (in[j] < in[i]) countT[i]++;
		}
		ans += countT[i];
	}
	minAns = ans;

	for (int i = 0; i < (int)in.size(); ++i) {
		for (int j = i + 1; j < (int) in.size(); ++j) {
			swap(in[i], in[j]);
			int cminAns = ans - (countT[i] + countT[j]);
			for (int k = i + 1; k < (int) in.size(); ++k) {
				if (in[k] < in[i]) cminAns++;
			}
			for (int k = j + 1; k < (int) in.size(); ++k) {
				if (in[k] < in[j]) cminAns++;
			}
			swap(in[i], in[j]);

			if (cminAns < minAns) {
				minAns = cminAns;
				pos = make_pair(i + 1, j + 1);
			}
		}
	}

	cout << pos.first << " " << pos.second << endl;

	return 0;
}