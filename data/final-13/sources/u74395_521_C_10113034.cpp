#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll power(ll b, int e)
{
	if(e == 0) return 1;
	ll res = power(b, e / 2);
	res = (res * res) % mod;
	if(e % 2) res = (res * b) % mod;
	return res;
}
ll inv(ll x)
{
	return power(x, mod - 2);
}

ll power10[100005];
ll fact[100005];
ll invfact[100005];

ll pre()
{
	power10[0] = 1;
	for(int i = 1; i < 100005; i++)
		power10[i] = (power10[i - 1] * 10) % mod;
	fact[0] = invfact[0] = 1;
	for(int i = 1; i < 100005; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		invfact[i] = inv(fact[i]);
	}
}
ll choose(int n, int k)
{
	if(n < k) return 0;
	return (fact[n] * ((invfact[n - k] * invfact[k]) % mod)) % mod;
}

int N, K;
ll S[100005];

ll L[100005], R[100005];
ll sum;

ll P[100005];
ll A[100005];

int main()
{
	pre();
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
	{
		char c;
		cin >> c;
		S[i] = (c - '0');
	}
	for(int i = 1; i <= N; i++)
	{
		L[i] = (L[i - 1] * 10 + S[i]) % mod;
		//cout << i << ' ' << L[i] << ' ' << choose(N - i - 1, K - 1) << endl;
		sum = (sum + L[i] * choose(N - i - 1, K - 1)) % mod;
	}
	for(int i = N; i >= 1; i--)
	{
		R[i] = (S[i] * power10[N - i] + R[i + 1]) % mod;
		//cout << i << ' ' << R[i] << ' ' << choose(i - 2, K - 1) << endl;
		sum = (sum + R[i] * choose(i - 2, K - 1)) % mod;
	}
	for(int i = 1; i <= N; i++) P[i] = P[i - 1] + S[i];
	for(int i = 1; i <= N - 2; i++)
	{
		A[i] = (A[i - 1] * 10 + (P[N] - P[i]) - R[N + 1 - i] + mod * 3) % mod;
		//cout << i << ' ' << (P[N] - P[i]) << ' ' << R[N + 1 - i] << ' ' << A[i] << endl;
		sum = (sum + A[i] * choose(N - i - 2, K - 2)) % mod;
	}
	if(K == 0) sum = (sum + L[N]) % mod;
	cout << sum;
}
