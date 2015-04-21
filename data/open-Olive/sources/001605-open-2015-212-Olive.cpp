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
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = -1, r = -1;
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j) {
			int nans = abs((a[i] - 1) - i) - abs((a[i] - 1) - j) + abs((a[j] - 1) - j) - abs((a[j] - 1) - i);
			if (nans > ans) {
				ans = nans;
				l = j + 1;
				r = i + 1;
			}
		}
	cout << l << " " << r;

	return 0;
}