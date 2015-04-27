#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_f"
const ldb pi = acos(-1.0);
const int N = (int) 1e6;
char s[N], t[N];
int a[N], b[N], tmp[N], p[N], sum[N], good[N];

void calc_p(int * s, int n, int * p) {
	p[0] = 0;
	for (int i = 1; i < n; ++i) {
		p[i] = p[i - 1];
		while ((p[i] > 0) && (s[p[i]] != s[i]))
			p[i] = p[p[i] - 1];
		if (s[p[i]] == s[i])
			++p[i];
	}
}

void build(char *s, char c1, char c2, int n, int *a) {
	for (int i = 0; i < n; ++i)
		if (s[i] == c1)
			a[i] = 1;
		else if (s[i] == c2)
			a[i] = 2;
		else
			a[i] = 0;
}

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	int n, m;
	scanf("%d%d%s%s", &n, &m, s, t);
	for (char c1 = 'a'; c1 <= 'z'; ++c1)
		for (char c2 = c1; c2 <= 'z'; ++c2) {
			build(s, c1, c2, n, a);
			build(t, c2, c1, m, b);
			int l = 0;
			for (int i = 0; i < m; ++i)
				tmp[l++] = b[i];
			tmp[l++] = 3;
			for (int i = 0; i < n; ++i)
				tmp[l++] = a[i];
			calc_p(tmp, n + m + 1, p);
			int sum = 0;
			for (int i = 0; i < m; ++i)
				sum += (int) ((tmp[i] == 1) || (tmp[i] == 2));
			for (int i = 0; i < n; ++i)
				if (p[i + m + 1] == m) {
					//printf("ok %c %c -> %d (+%d)\n", c1, c2, i, sum);
					good[i - m + 1] += sum;
				}
		}
	vector<int> res;
	for (int i = 0; i + m <= n; ++i)
		if (good[i] == m)
			res.pb(i);
	printf("%d\n", sz(res));
	for (int i = 0; i < sz(res); ++i)
		printf("%d%c", res[i] + 1, " \n"[i == sz(res) - 1]);
	return 0;
}
