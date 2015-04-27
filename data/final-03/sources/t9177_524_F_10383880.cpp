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
const int N = (int) 2e6 + 10;
const int M = (int) 1e9 + 9;
const int H = 2;
const int64 P[2] = {17239, 23917};
int64 h[2][N], ppow[2][N];
int n, prefsum[N], minprefsum[N], sufsum[N], minsufsum[N];
char s[N];

bool equal(int i, int j, int len) {
	for (int t = 0; t < H; ++t)
		if (((h[t][i + len] - h[t][i] * ppow[t][len]) - (h[t][j + len] - h[t][j] * ppow[t][len])) % M != 0)
			return false;
	return true;
}

bool is_less(int i, int j) {
	int l = 0, r = n;
	while (l < r) {
		int q = (l + r + 1) / 2;
		if (equal(i, j, q))
			l = q;
		else
			r = q - 1;
	}
	return (s[i + l] < s[j + l]);
}

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		s[i + n] = s[i];
	for (int j = 0; j < 2; ++j) {
		h[j][0] = 0, ppow[j][0] = 1;
		for (int i = 0; i < 2 * n; ++i) {
			h[j][i + 1] = (h[j][i] * P[j] + s[i]) % M;
			ppow[j][i + 1] = (ppow[j][i] * P[j]) % M;
		}
	}
	prefsum[0] = 0;
	for (int i = 0; i < n; ++i)
		prefsum[i + 1] = prefsum[i] + ((s[i] == '(') ? 1 : -1);
	minprefsum[0] = prefsum[0];
	for (int i = 0; i < n; ++i)
		minprefsum[i + 1] = min(minprefsum[i], prefsum[i + 1]);
	minsufsum[n] = prefsum[n];
	for (int i = n - 1; i >= 0; --i)
		minsufsum[i] = min(minsufsum[i + 1], prefsum[i]);
	int total = prefsum[n], bound = min(total, 0);
	vector<int> a;
	for (int i = 0; i < n; ++i)
		if ((minsufsum[i + 1] >= bound + prefsum[i]) && (minprefsum[i] >= bound - total + prefsum[i]))
			a.pb(i);
	int best = a[0];
	for (int i = 1; i < sz(a); ++i)
		if (is_less(a[i], best))
			best = a[i];
	for (int i = 0; i < -total; ++i)
		printf("(");
	for (int i = 0; i < n; ++i)
		printf("%c", s[best + i]);
	for (int i = 0; i < total; ++i)
		printf(")");
	printf("\n");
	return 0;
}
