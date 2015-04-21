#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > countB;
vector<int> in;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int c = 0;
	int n;
	cin >> n;
	in.resize(n);
	countB.resize(n + 1);
	for (int i = 0; i < n; ++i) {
		countB[i + 1].resize(n, 0);
		cin >> in[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = n - 2; j >= 0; --j) {
			countB[i][j] = countB[i][j + 1];
			if (in[j] < i) countB[i][j]++;
		}
	}

	pair<int, int> pos = make_pair(-1, -1);
	int ans = 0;
	int minAns = 0;
	for (int i = 0; i < (int)in.size(); ++i) {
		ans += countB[in[i]][i];
	}
	minAns = ans;

	for (int i = 0; i < (int)in.size(); ++i) {
		for (int j = i + 1; j < (int) in.size(); ++j) {
			int cminAns = ans - (countB[in[i]][i] + countB[in[j]][j]);
			cminAns += countB[in[j]][i];
			cminAns += countB[in[i]][j];
			if (in[j] > in[i]) cminAns++;

			if (cminAns < minAns) {
				minAns = cminAns;
				pos = make_pair(i + 1, j + 1);
			}
		}
	}

	cout << pos.first << " " << pos.second << endl;

	return 0;
}