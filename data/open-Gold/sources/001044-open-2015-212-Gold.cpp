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

	long long n, k, c, d;
	cin >> n >> k >> c >> d;
	vector<long long> L(n);
	vector<long long> R(n);
	long long len = 0;
	for (int i = 0; i < n; ++i) {
		cin >> L[i] >> R[i];
		len += R[i] - L[i];
	}
	long long m = n;
	long long ans = len * d + (m - 1) / k * c;
	priority_queue<pair<int, int> > Q;
	for (int i = 1; i < n; ++i) {
		Q.push(make_pair(-(L[i] - R[i - 1]), i));
	}
	while (!Q.empty()) {
		int l = -Q.top().first;
		int id = Q.top().second;
		Q.pop();
		len += l;
		--m;
		ans = min(ans, len * d + (m - 1) / k * c);
	}
	cout << ans;

	return 0;
}