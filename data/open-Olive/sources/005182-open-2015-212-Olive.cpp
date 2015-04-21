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

int test(vector<int> &a) {
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 1; j < a.size(); ++j) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				++ans;
			}
		}
	}
	return ans;
}

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
	vector<int> b = a;
	int ans = test(b);
	int l = -1, r = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j) {
			b = a;
			swap(b[i], b[j]);
			int nans = test(b);
			if (nans < ans) {
				ans = nans;
				l = j + 1;
				r = i + 1;
			}
		}
	cout << l << " " << r;

	return 0;
}