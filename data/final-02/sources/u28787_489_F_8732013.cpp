#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 550

int N, M, MOD;
char L[MAXN];
int csum[MAXN];
queue<int> Q[2];
int dp[2][MAXN][MAXN];
bool v[MAXN][MAXN];

int main() {
//	freopen("date.in", "r", stdin);
//	freopen("date.out","w", stdout);
	
	scanf("%d %d %d\n", &N, &M, &MOD);
	for (int i = 0; i < M; i++) {
		fgets(L, sizeof(L), stdin);
		for (int j = 0; j < N; j++) {
			if (L[j] == '1') {
				csum[j]++;
			}
		}
	}
	
	int sc0 = 0, sc1 = 0;
	for (int j = 0; j < N; j++) {
		if (csum[j] == 0) {
			sc0++;
		}
		else if (csum[j] == 1) {
			sc1++;
		}
	}
	
	int c[3];
	int line = 1;
	dp[0][sc0][sc1] = 1;
	Q[0].push(sc0); Q[0].push(sc1);
	for (int i = M; i < N; i++) {
		memset(dp[line], 0, sizeof(dp[line]));
		memset(v, 0, sizeof(v));
		while (!Q[1 - line].empty()) {
			c[0] = Q[1 - line].front(); Q[1 - line].pop();
			c[1] = Q[1 - line].front(); Q[1 - line].pop();
			c[2] = N - c[0] - c[1];

			for (int j = 0; j < 2; j++) {
				for (int k = j; k < 2; k++) {
					int nc0 = c[0];
					int nc1 = c[1];
					if (j == 0) { nc0--; nc1++; }
					if (j == 1) { nc1--; }
					if (k == 0) { nc0--; nc1++; }
					if (k == 1) { nc1--; }
					if (nc0 < 0 || nc1 < 0) continue;
					if (nc0 + nc1 > N) continue;
					
					int ways = -1;
					if (j != k) {
						ways = c[j] * c[k];
					}
					else {
						ways = c[j] * (c[j] - 1) / 2;
					}
					
					dp[line][nc0][nc1] = (dp[line][nc0][nc1] + (long long) dp[1 - line][c[0]][c[1]] * ways) % MOD;
					if (dp[line][nc0][nc1] > 0 && !v[nc0][nc1]) {
						Q[line].push(nc0); Q[line].push(nc1);
						v[nc0][nc1] = true;
					}
				}
			}
		}
		
		line = 1 - line;
	}
	
	int ans = dp[1 - line][0][0];
	printf("%d\n", ans);
	
	return 0;
}
