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
vector<pair<float, float> > A[MAXN];

const float EPS = 1e-6;

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
	scanf("%d%d", &a, &b);
	//cin >> a >> b;
	int n;
	scanf("%d", &n);
	//cin >> n;
	//vector<vector<pair<double, double> > > A(n);
	for (int i = 0; i < n; ++i) {
		int l;
		scanf("%d", &l);
		//cin >> l;
		A[i].resize(l + 1);
		for (int j = 0; j < l + 1; ++j) {
			scanf("%f%f", &A[i][j].first, &A[i][j].second);
			//cin >> A[i][j].first >> A[i][j].second;
		}
		A[i].push_back(make_pair(b + 10, A[i].back().second));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				for (int k = 0; k < A[i].size(); ++k) {
					int l = 1, r = A[j].size() - 1;
					while (l < r) {
						int m = (l + r) / 2;
						if (A[j][m].first > A[i][k].first) {
							r = m;
						} else {
							l = m + 1;
						}
					}
					int w = r;
					if (A[j][w].first > A[i][k].first) {
						float val = (A[i][k].first - A[j][w - 1].first) / (A[j][w].first - A[j][w - 1].first);
						float y = A[j][w - 1].second + val * (A[j][w].second - A[j][w - 1].second);
						//cout << y << endl;
						if (abs(y - A[i][k].second) >= EPS) {
							if (y > A[i][k].second) {
								g[j][i] = 1;
							}
							else {
								g[i][j] = 1;
							}
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