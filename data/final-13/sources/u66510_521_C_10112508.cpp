#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const long long p = 1000000007;
long long f[100005];
long long rev[100005];
long long base[100005];
int n, k;
int a[100005];

void solve(long long i, long long pp, long long &a, long long &b)
{
	if (pp == 1)
	{
		a = 0;
		b = 1;
	}
	else
	{
		long long t1, t2;
		solve(pp % i, i, t1, t2);
		b = t1;
		a = (t2 - ((pp / i) * b) % p + p) % p;
	}
}

int main()
{
	cin >> n >> k;
	char c;
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		a[i] = c - '0';
	}
	
	long long tmp;
	for (long long i = 1; i <= n; ++i)
		solve(i, p, rev[i], tmp);
	
	f[k] = 1;
	for (int i = k + 1; i <= n; ++i)
		f[i] = (((f[i-1] * i) % p) * rev[i - k]) % p;
	base[0] = 1;
	for (int i = 1; i <= n; ++i)
		base[i] = (base[i-1] * 10) % p;
	
	long long res = 0;
	for (int i = n - 1; i >= k; --i)
		res = (res + (((f[i] * a[i]) % p) * base[n-i-1]) % p) % p;
	
	f[k-1] = 1;
	for (int i = k; i <= n; ++i)
		f[i] = (((f[i-1] * i) % p) * rev[i - k + 1]) % p;
	
	long long cum = 0;
	for (int i = n - 2; i >= 0; --i)
	{
		cum = (cum + (f[i] * base[n - i - 2]) % p) % p;
		res = (res + a[i] * cum) % p;
	}
	
	cout << res << endl;

	return 0;
}
