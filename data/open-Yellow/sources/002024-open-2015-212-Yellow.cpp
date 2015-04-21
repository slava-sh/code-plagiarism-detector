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

/*const int MAXN = 40001;

char a[MAXN];
int b[MAXN];
int p[MAXN];

void prefix(int n) {
	p[0] = 0;
	for (int i = 1, k = 0; i < n; ++i) {
		while (k > 0 && a[i] != a[k])
			k = p[k - 1];
		if (a[i] == a[k])
			++k;
		p[i] = k;
	}
}*/

/*vector<long long> p;
vector<long long> p2;

long long dfs(long long depth, long long k) {
	if (depth == k)
		return 1;
	return dfs(depth + 1, k) * ((p[depth] * p2[depth] + 1) / 2);
}*/

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//#define FILE_NAME ""
//	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	/*long long n, k;
	cin >> n >> k;

	for (long long i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			n /= i;
			if (i == 2)
				p2.push_back(i);
			else
				p.push_back(i);
		}
	if (n != 1) {
		if (n == 2)
			p2.push_back(n);
		else
			p.push_back(n);
	}
	while (p.size() > k) {
		p[k - 1] *= p.back();
		p.pop_back();
	}
	reverse(p.begin(), p.end());
	while (p.size() < k)
		p.push_back(1);
	while (p2.size() > k) {
		p2[k - 1] *= p2.back();
		p2.pop_back();
	}
	reverse(p2.begin(), p2.end());
	while (p2.size() < k)
		p2.push_back(1);
	cout << dfs(0, k);*/

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 1;
	for (int i = 1; i < n; ++i)
		if (a[i - 1] != a[i])
			++ans;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int p, b;
		cin >> p >> b;
		--p;
		int last = 0;
		if (p > 0 && a[p - 1] != a[p])
			++last;
		if (p < n - 1 && a[p] != a[p + 1])
			++last;
		a[p] = b;
		int next = 0;
		if (p > 0 && a[p - 1] != a[p])
			++next;
		if (p < n - 1 && a[p] != a[p + 1])
			++next;
		ans -= last;
		ans += next;
		cout << ans << "\n";
	}

	return 0;
}