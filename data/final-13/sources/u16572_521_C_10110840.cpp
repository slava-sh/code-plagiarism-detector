#include <iostream>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 100010;

int fact[MAXN], invFact[MAXN], p10[MAXN], dp[MAXN];
char a[MAXN];

inline long long add(long long a, long long b)
{
	return (a + b) % MOD;
}

inline long long mul(long long a, long long b)
{
	return (a * b) % MOD;
}

int logPow(int a, int b)
{
	if (b == 0)
		return 1;
	int x = logPow(a, b / 2);
	x = mul(x, x);
	if (b % 2)
		return mul(a, x);
	else
		return x;
}

inline int C(int n, int r)
{
	return mul(mul(fact[n], invFact[r]), invFact[n - r]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] -= '0';
	}
	if (k == 0)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = add(mul(ans, 10), a[i]);
		cout << ans << endl;
		return 0;
	}
	fact[0] = 1;
	invFact[0] = 1;
	p10[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = mul(fact[i - 1], i);
		invFact[i] = logPow(fact[i], MOD - 2);
		p10[i] = mul(p10[i - 1], 10);
	}
	for (int i = 0; i <= n - 2; i++)
	{
		if (i > 0)
			dp[i] = dp[i - 1];
		if (n - i - 2 >= k - 1)
			dp[i] = add(dp[i], mul(C(n - i - 2, k - 1), p10[i]));
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			ans = add(ans, mul(dp[n - 2 - i], a[i]));
		if (i >= k)
			ans = add(ans, mul(C(i, k), mul(a[i], p10[n - 1 - i])));
	}
	cout << ans << endl;
}
