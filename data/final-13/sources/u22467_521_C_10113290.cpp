#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
const int MAXN = 110000;

int n,k;

long long power(long long a,long long b)
{
	long long ans = 1;
	a %= mod;
	while(b)
	{
		if (b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

long long jc[MAXN],f[MAXN],h[MAXN];
char s[MAXN];

long long C(long long N,long long M)
{
	if (N < 0 || M < 0 || (N < M)) return 0;
	return ((jc[N]*power(jc[N-M],mod-2)) % mod *power(jc[M],mod-2)) % mod;
}

long long ans;

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	jc[0] = 1;
	for(int i = 1;i <= n;i++) jc[i] = (jc[i-1] * i) % mod;
	f[0] = 0;
	long long g = 1;
	h[0] = 1;
	for(int i = 1;i <= n;i++)
	{
		f[i] = (f[i-1] + g * C(n-i-1,k-1)) % mod;
		g = (g * 10) % mod;
		h[i] = g;
	}
	ans = 0;
	for(int i = 0;i < n;i++)
	{
		long long tmp = f[n-i-1];
		tmp = (tmp + C(i,k)*h[n-i-1]) % mod;
		ans = (ans + tmp * (s[i]-'0')) % mod;
	}
	cout << ans << endl;
	return 0;
}