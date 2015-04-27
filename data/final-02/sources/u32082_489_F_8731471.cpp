#include <cstdio>
char s[510][510];
int k[3];
int comb[1010][1010];
int dp[510][510];
int mod, t;
int mul(int a, int b) {
	return (long long)a * b % mod;
}
int go(int r, int o) {
	if (r == 0) {
		return o == 0;
	}
	if (dp[r][o] != -1) {
		return dp[r][o];
	}
	int &res = dp[r][o];
	int p = r-o/2;
	res = 0;
	if (o >= 2) {
		res += mul(comb[o][2], go(r-1, o-2));
		if (res >= mod) res -= mod;
	}
	if (o >= 1 && p >= 1) {
		res += mul(mul(comb[o][1], comb[p][1]), go(r-1, o));
		if (res >= mod) res -= mod;
	}
	if (p >= 2) {
		res += mul(comb[p][2], go(r-1, o+2));
		if (res >= mod) res -= mod;
	}
	return res;
}
int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &mod);
	for (int i = 0; i < m; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < m; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			c += s[i][j] == '1';
		}
		if (c != 2) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < m; j++) {
			c += s[j][i] == '1';
		}
		if (c > 2) {
			printf("0\n");
			return 0;
		}
		k[c]++;
	}
	comb[0][0] = 1;
	for (int i = 1; i < 1010; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
			if (comb[i][j] >= mod) {
				comb[i][j] -= mod;
			}
		}
	}
	if (k[0] * 2 + k[1] != 2 * (n-m)) {
		printf("0\n");
		return 0;
	}
	t = k[0] + k[1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	printf("%d\n", go(n-m, k[1]));
	return 0;
}
