#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 100500;
typedef long long ll;

ll ans = MAXN;
ll mas[MAXN];
ll d[MAXN];

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
				d[j] = d[i];
		}
	}
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
	cout << brute(n, k);
	return 0;
}