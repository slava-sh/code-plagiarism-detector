#include <stdio.h>
#define lli long long int

int n, m, mod;

char grid[501][501];

lli dp[501][501];
int magic;

lli solve(int pos, int need1) {
	lli aux;
	int need2 = magic - need1;

	if (need1 == 0 && need2 == 0) {
		return 1;
	}

	if (pos == n - m) {
		return 0;
	}

	if (dp[pos][need1] != -1) {
		return dp[pos][need1];
	}

	aux = 0;
	if (need1 >= 2) {
		magic -= 2;
		aux += ((((need1 - 1) * need1) / 2) % mod) * solve(pos + 1, need1 - 2);
		magic += 2;
		aux %= mod;
	}
	if (need2 >= 2) {
		aux += ((((need2 - 1) * need2) / 2) % mod) * solve(pos + 1, need1 + 2);
		aux %= mod;
	}
	if (need1 >= 1 && need2 >= 1) {
		magic -= 1;
		aux += ((need1 * need2) % mod) * solve(pos + 1, need1);
		magic += 1;
		aux %= mod;
	}

	dp[pos][need1] = aux;
	return aux;
}	

int main(void) {
	int ok = 1;
	int need1, need2;
	lli r;
	int aux;

	scanf(" %d %d %d", &n, &m, &mod);

	for (int i = 0; i < m; i++) {
		scanf(" %s", grid[i]);
	}

	need1 = need2 = 0;
	for (int j = 0; j < n; j++) {
		aux = 0;
		for (int i = 0; i < m; i++) {
			if (grid[i][j] == '1') {
				aux++;
			}
		}
		if (aux == 0) {
			need2++;
		} else if (aux == 1) {
			need1++;
		} else if (aux > 2) {
			ok = 0;
		}
	}

	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= 500; j++) {
			dp[i][j] = -1;
		}
	}
	magic = need1 + need2;

	if (ok) {
		r = solve(0, need1);
		printf("%lld\n", r % mod);
	} else {
		printf("0\n");
	}
	return 0;
}

	
