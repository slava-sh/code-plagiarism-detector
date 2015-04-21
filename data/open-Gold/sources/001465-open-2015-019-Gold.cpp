#include <iostream>

using namespace std;

long long dp[200010][2];

int main () {
	long long n, k, c, d;
	cin >> n >> k >> c >> d;
	for (long long i = 0; i <= k; i++) {
		dp[i][1] = 1000000000000000000;
	}
	long long l, r;
	cin >> l >> r;
	dp[1][1] = (r - l) * d;
	for (long long i = 2; i <= n; i++) {
		long long ll, rr;
		cin >> ll >> rr;
		long long i1 = (i + 1) % 2, i2 = i % 2;
		dp[1][i2] = min(dp[1][i1] + d * (rr - r), dp[k][i1] + d * (rr - ll) + c);
		for (long long j = 2; j <= k; j++) {
			dp[j][i2] = min(dp[j][i1] + d * (rr - r), dp[j - 1][i1] + d * (rr - ll));
		}
		l = ll;
		r = rr;
	}
	long long mn = 1000000000000000000;
	for (long long i = 1; i <= k; i++) {
		mn = min(mn, dp[i][n % 2]);
	}
	cout << mn;
	return 0;
}