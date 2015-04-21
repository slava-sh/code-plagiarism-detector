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

vector<long long> p;

long long dfs(long long depth, long long k) {
	if (depth == k - 1) {
		long long ans = 1;
		for (int i = depth; i < p.size(); ++i) {
			ans *= p[i];
			//cout << ans << "#" << endl;
		}
		return (ans + 1) / 2;
	}
	//cout << (p[depth] + 1) / 2 << endl;
	return dfs(depth + 1, k) * ((p[depth] + 1) / 2);
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

	for (long long i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			n /= i;
			p.push_back(i);
		}
	if (n != 1)
		p.push_back(n);
	cout << dfs(0, k - 1);

	return 0;
}