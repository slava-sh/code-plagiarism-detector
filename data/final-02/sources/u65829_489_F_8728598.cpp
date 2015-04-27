#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MaxN = 500;

int dp[2][MaxN + 1][MaxN + 1];
char s[MaxN + 1];
int a[MaxN];
int n, m, mod;

void add (int & a, int b) {
	a = (a + b) % mod;
}

int main () {
	scanf ("%d%d%d", &n, &m, &mod);
	for (int i = 0; i < n; i++)
		a[i] = 2;
	for (int i = 0; i < m; i++) {
		scanf ("%s", s);
		for (int j = 0; j < n; j++)
			a[j] = a[j] - (s[j] - '0');
	}
//	for (int i = 0; i < n; i++)
//		printf ("%d ", a[i]);
//	printf ("\n");
	dp[0][n - m][0] = 1;
	int cur = 0;
	int next = 1;
	for (int i = 0; i < n; i++) {
		for (int sum = 0; sum <= n - m; sum++)
			for (int two = sum; two >= 0; two--) {
				int one = sum - two;
				if (dp[cur][two][one] == 0) continue;
				if (a[i] == 0) {
					add(dp[next][two][one], dp[cur][two][one]);
				}
				if (a[i] == 1) {
					if (one != 0) 
						add(dp[next][two][one - 1], (dp[cur][two][one] * 1ll * one) % mod);
					if (two != 0)
						add(dp[next][two - 1][one + 1], (dp[cur][two][one] * 1ll * two) % mod);
				}
				if (a[i] == 2) {
					if (one > 1)
						add(dp[next][two][one - 2], (dp[cur][two][one] * 1ll * ((one * (one - 1)) / 2)) % mod);
					if (two > 1)
						add(dp[next][two - 2][one + 2], (dp[cur][two][one] * 1ll * ((two * (two - 1)) / 2)) % mod);
					if (one > 0 && two > 0) 
						add(dp[next][two - 1][one], (dp[cur][two][one] * 1ll * (one * two)) % mod);
				}
			}
		swap(cur, next);
		for (int sum = 0; sum <= n - m; sum++)
			for (int two = sum; two >= 0; two--)
				dp[next][two][sum - two] = 0;
	}
//	for (int i = 1; i <= 3; i++) {
//		printf ("%d:\n", i);
//		for (int j = 0; j <= n - m; j++)
//			for (int k = 0; k <= n - m && j + k <= n - m; k++)
//				printf ("%d %d %d\n", j, k, dp[i][j][k]);
//		printf ("\n\n\n");
//	}

	printf ("%d\n", dp[cur][0][0]);
}

