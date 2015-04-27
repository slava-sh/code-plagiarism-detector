//Problem #C from Codeforces code_strike_2014_finals
#include <cmath>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define fi first
#define se second
#define int64 long long

const int kMaxN = 300005;

vector<int> vertex[kMaxN];
int sz[kMaxN];
int aib[kMaxN];

int n, p;

void aib_update(int ind, int val) {
	ind++;

	while (ind <= n + 5) {
		aib[ind] += val;
		ind += ind & (-ind);
	}
}
int aib_query(int ind) {
	int rez = 0;
	ind++;

	if (ind <= 0)
		return 0;

	while (ind) {
    	rez += aib[ind];
		ind -= ind & (-ind);
	}
	return rez;
}

int main() {
 	cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
		sz[a]++;
		sz[b]++;
	}
	for (int i = 1; i <= n; ++i)
		aib_update(sz[i], 1);
	int64 rez = 0;
	for (int i = 1; i <= n; ++i) {
		sort(vertex[i].begin(), vertex[i].end());
		int st = 0;
		rez += n - aib_query(p - sz[i] - 1);
		if (sz[i] > p - sz[i] - 1)
			--rez;
		while (st < int(vertex[i].size())) {
			int dr = st;
			while (dr < int(vertex[i].size()) and vertex[i][dr] == vertex[i][st])
				++dr;
			int a = i;
			int b = vertex[i][st];
			if (sz[a] + sz[b] - (dr - st) >= p)
				++rez;
			if (sz[b] > p - sz[i] - 1)
				--rez;
			st = dr;
		}

	}
	rez /= 2;
	cout << rez << '\n';
	return 0;
}

