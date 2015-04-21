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

const int MAXN = 15001;
int A[MAXN][MAXN];
int B[MAXN][MAXN];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//#define FILE_NAME ""
	//	freopen(FILE_NAME ".in", "r", stdin);
	//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		A[i][i] = 0;
		for (int j = i + 1; j < n; ++j) {
			A[i][j] = A[i][j - 1] + (a[i] > a[j] ? 1 : -1);
		}
	}
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		B[i][i] = 0;
		for (int j = i - 1; j >= 0; --j) {
			B[i][j] = B[i][j + 1] + (a[j] > a[i] ? 1 : -1);
		}
	}
	int ans = 0;
	int l = -1, r = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j) {
			if (a[j] > a[i]) {
				int nans = A[j][i] + B[i][j];
				if (nans > ans) {
					ans = nans;
					l = j + 1;
					r = i + 1;
				}
			}
		}
	cout << l << " " << r;

	return 0;
}