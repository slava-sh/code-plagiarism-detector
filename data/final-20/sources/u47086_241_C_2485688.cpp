// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

bool intersects(int hl, int hr, int a, int b, int y) {
	LL ux = 100000;
	LL uy = hr - hl;
	LL ax = a;
	LL ay = y - hl;
	LL bx = b;
	LL by = y - hl;
	LL pa = ux * ay - uy * ax;
	LL pb = ux * by - uy * bx;
	return (pa <= 0 && pb >= 0) || (pa >= 0 && pb <= 0);
}

int main() {
	int hl, hr, n;
	scanf("%d%d%d", &hl, &hr, &n);
	VI V(n), A(n), B(n), H, D;
	REP(i, n) {
		char c;
		scanf("%d %c%d%d", &V[i], &c, &A[i], &B[i]);
		if (c == 'F') {
			D.push_back(i);
		} else {
			H.push_back(i);
		}
	}

	int res = 0;
	FOR(q, -n, n) {
		int h = q * 100 + ((q % 2) ? 100 - hr : hr);
		vector<bool> U(n, false);
		int score = 0;
		bool okok = true;
		FOR(w, 1, q) {
			const VI& M = (w % 2) ? H : D;
			bool ok = false;
			FORE(i, M)
				if (intersects(hl, h, A[*i], B[*i], w * 100)) {
					if (U[*i])
						break;
					U[*i] = true;
					score += V[*i];
					ok = true;
					break;
				}
			if (!ok) {
				okok = false;
				break;
			}
		}
		FORD(w, 0, q + 1) {
			const VI& M = (w % 2) ? H : D;
			bool ok = false;
			FORE(i, M)
				if (intersects(hl, h, A[*i], B[*i], w * 100)) {
					if (U[*i])
						break;
					U[*i] = true;
					score += V[*i];
					ok = true;
					break;
				}
			if (!ok) {
				okok = false;
				break;
			}
		}
		if (okok)
			res = max(res, score);
	}

	printf("%d\n", res);
}
