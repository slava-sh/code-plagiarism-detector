#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAX = 100005;
long long a[MAX], p10[MAX], f[MAX], rev[MAX], sum[MAX];
long long bpow(long long a, long long b)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans *= a;
		b >>= 1;
		a *= a;
		ans %= MOD;
		a %= MOD;
	}
	return ans;
}
long long c(long long n, long long r)
{
	if (r < 0 || n < r)
		return 0;
	return f[n] * rev[r] % MOD * rev[n - r] % MOD;
}
int main()
{
	ios::sync_with_stdio(false);
	f[0] = rev[0] = p10[0] = 1;
	for (int i = 1; i < MAX; i++)
	{
		f[i] = f[i - 1] * i % MOD;
		p10[i] = p10[i - 1] * 10 % MOD;
		rev[i] = bpow(f[i], MOD - 2);
	}
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	if (k == 0)
	{
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans = (ans * 10 + a[i]) % MOD;
		cout << ans << endl;
		return 0;
	}
	sum[k - 1] = 1;
	for (int i = k; i < MAX; i++)
		sum[i] = (c(i, k - 1) + 10 * sum[i - 1]) % MOD;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = (ans + c(i, k) * p10[n - i - 1] % MOD * a[i]) % MOD;
		long long res = sum[n - 2];
		if (i)
			res -= sum[i - 1] * p10[n - 2 - (i - 1)];
		res %= MOD;
		res += MOD;
		res %= MOD;
		ans = (ans + res * a[i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
