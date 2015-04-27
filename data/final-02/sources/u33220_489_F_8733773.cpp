#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <deque>
#include <iomanip>

using namespace std;

int c[505][505];
int n,m,mod;
int dp[505][505];
void calc() {
	for (int i = 0; i <= 500; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
		}
	}
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m >> mod;
	calc();
	
	string s;
	vector<int> cnt(n);
	for (int i = 0; i < m; ++i) {
		cin >> s;
		for (int j = 0; j < n; ++j) {
			if (s[j] == '1') {
				cnt[j]++;
			}
		}
	}

	int ones = 0, twos = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] == 1) ++ones;
		else if (cnt[i] == 0) ++twos;
	}

	dp[0][ones] = 1;
	int left = (n - m) * 2;
	for (int r = 1; r <= n - m; ++r, left-=2) {
		for (int i = 0; i <= left; ++i) {
			if ((left - i) % 2 != 0 || !dp[r-1][i]) {
				continue;
			}
			int ones = i;
			int twos = (left - i) / 2;

			dp[r][i] = (dp[r][i] + (((1LL * dp[r-1][i] * twos) % mod) * ones) % mod) % mod;
			if (ones >= 2) {
				dp[r][i-2] = (dp[r][i-2] + (1LL * dp[r-1][i] * c[ones][2]) % mod) % mod;
			}
			if (twos >= 2) {
				dp[r][i+2] = (dp[r][i+2] + (1LL * dp[r-1][i] * c[twos][2]) % mod) % mod;
			}
		}

	}


	cout << dp[n-m][0];

    return 0;
}