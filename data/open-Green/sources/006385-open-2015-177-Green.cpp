#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 1000500;
typedef long long ll;

ll ans = MAXN;
ll mas[MAXN];
ll d[MAXN];
ll dp[MAXN][13];
ll res[15];
void rec(int n, int k)
{
	if (n == 1)
	{
		ll res = 1;
		for (int i = 0; i < k; i++)
			res *= (mas[i] + 1) / 2;
		ans = min(res, ans);
		return;
	}
	for (int j = 0; j < k; j++)
	{
		mas[j] *= d[n];
		rec(n / d[n], k);
		mas[j] /= d[n];				
	}
	
}

int brute(int n, int k)
{
	for (ll i = 2; i < MAXN; i++)
	{
		if (d[i] == 0)
		{
			d[i] = i;
			for (ll j = d[i] * d[i]; j < MAXN; j += d[i])
				if (d[j] == 0)
					d[j] = d[i];
		}
	}
	for (int i = 0; i < 100; i++)
		cout << i << ' ' << d[i] << '\n';
	fill(mas, mas + MAXN, 1);
	rec(n, k);
	return ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int n, k;
	cin >> n >> k;
	
//	cout << brute(n, k);
	while (n % 2 == 0 && k > 0)
	{
		k--;
		n /= 2;
	}
	if (k == 0)
	{
		cout << n; 
		return 0;
	}
	for (ll i = 2; i < MAXN; i++)
	{
		if (d[i] == 0)
		{
			d[i] = i;
			for (ll j = d[i] * d[i]; j < MAXN; j += d[i])
				if (d[j] == 0)
					d[j] = d[i];
		}
	}
	for (int i = 0; i < 15; i++)
		res[i] = 1;
	res[0] = n;
	bool flag = true;

	while (flag)
	{
		flag = false;
		for (int i = 0; i < k; i++)
			for (int j = i + 1; j < k; j++)
			{
				if (res[i] < res[j])
					swap(res[i], res[j]);
				if ((res[i] + 1) / 2 * (res[j] + 1) / 2 > (res[i] / d[res[i]] + 1) / 2 * (res[j] * d[res[i]] + 1) / 2)
				{
					res[j] *= d[res[i]];
					res[i] /= d[res[i]];
					flag = true;
				}
			}
	}

	int ans = 1;
	for (int i = 0; i < k; i++)
		ans *= (res[i] + 1) / 2;

	cout << ans;
	return 0;
}