#pragma comment(linker, "/STACK:16777216")

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1000;
int g[MAXN][MAXN];

const double EPS = 1e-6;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//#define FILE_NAME ""
	//	freopen(FILE_NAME ".in", "r", stdin);
	//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	vector<vector<pair<double, double> > > A(n);
	for (int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		A[i].resize(l + 1);
		for (int j = 0; j < l + 1; ++j) {
			cin >> A[i][j].first >> A[i][j].second;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				for (int k = 0; k < A[i].size(); ++k) {
					for (int w = 1; w < A[j].size(); ++w) {
						if (A[j][w].first > A[i][k].first) {
							double val = (A[i][k].first - A[j][w - 1].first) / (A[j][w].first - A[j][w - 1].first);
							double y = A[j][w - 1].second + val * (A[j][w].second - A[j][w - 1].second);
							if (abs(y - A[i][k].second) >= EPS) {
								if (y > A[i][k].second) {
									g[j][i] = 1;
								}
								else {
									g[i][j] = 1;
								}
							}
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (g[i][j] && g[j][i]) {
				cout << "No\n";
				cout << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
	cout << "Yes";

	return 0;
}