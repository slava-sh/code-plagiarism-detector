#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <ctime>

#define oo 1000000005
#define eps 1e-11

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

using namespace std;

const double PI = 2.0 * acos (0.0);

typedef long long LL;
typedef pair <int, int> PII;

inline int getInt () { int x; scanf ("%d", &x); return x; }
inline LL getLL () { LL x; scanf ("%lld", &x); return x; };
inline int NUM (char c) { return (int)c - 48; }
inline char CHR (int n) { return (char)(n + 48); }
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

// ptrrsn_1's template

#define MAXN 100000

int N;
int R[MAXN + 5];
int A[MAXN + 5];
int B[MAXN + 5];
int C[MAXN + 5];

inline bool assigns(int x, bool print) {
	if (x > N) return false;
	int ctr = 0;
	int i = 0;
	while (i < N && ctr < x) {
		A[ctr++] = R[i];
		i++;
	}
	if (ctr != x) return false;
	ctr = 0;
	while (i < N && ctr < x) {
		B[ctr] = R[i];
		if (B[ctr] > A[ctr]) ctr++;
		i++;
	}
	if (ctr != x) return false;
	ctr = 0;
	while (i < N && ctr < x) {
		C[ctr] = R[i];
		if (C[ctr] > B[ctr]) ctr++;
		i++;
	}
	if (ctr != x) return false;
	if (print) {
		REP (i, x) {
			printf("%d %d %d\n", C[i], B[i], A[i]);
		}
	}
	return true;
}

inline int binary_search() {
	int lo = 0, hi = N;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		bool f = assigns(mid, false), f1 = assigns(mid + 1, false);
		if (f && !f1) {
			return mid;
		} else if (f) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		} 
	}
	return 0;
}

int main () {
	// OPEN("C");
	
	scanf("%d", &N);
	REP (i, N) {
		scanf("%d", &R[i]);
	}
	sort(R, R + N);
	
	int ret = binary_search();
	printf("%d\n", ret);
	assigns(ret, true);
	
    return 0;
}
