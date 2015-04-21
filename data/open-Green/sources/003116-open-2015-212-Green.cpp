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

vector<long long> p;
vector<long long> p2;

long long dfs(long long depth, long long k) {
	if (depth == k)
		return 1;
	return dfs(depth + 1, k) * ((p[depth] * p2[depth] + 1) / 2);
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

	long long n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << (n + 1) / 2;
		return 0;
	}

	if (k == 2) {
		for (long long i = 2; i * i <= n; ++i)
			while (n % i == 0) {
				n /= i;
				p.push_back(i);
			}
		if (n != 1) {
			p.push_back(n);
		}
		long long ans = -1;
		for (int i = 0; i < (1 << p.size()); ++i) {
			long long a = 1, b = 1;
			for (int j = 0; j < p.size(); ++j)
				if ((1 << j) & i)
					a *= p[j];
				else
					b *= p[j];
			long long cur = ((a + 1) / 2) * ((b + 1) / 2);
			if (ans == -1 || cur < ans)
				ans = cur;
		}
		cout << ans;
		return 0;
	}

	cout << 2;

	/*while (p.size() > k) {
		p[k - 1] *= p.back();
		p.pop_back();
	}
	reverse(p.begin(), p.end());
	while (p.size() < k)
		p.push_back(1);
	cout << dfs(0, k);*/

	return 0;
}