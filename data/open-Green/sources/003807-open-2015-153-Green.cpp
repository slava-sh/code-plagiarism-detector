#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define ss second
#define ff first

const ll maxn = 100000;
const ll maxseg = 131072;
const ll inf = 4611686018427387904;
const double pi = 3.141592653589793238462643383279502884;
const double eps = 1e-9;
const double inff = 1e100;

int main()
{
	cin.sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll step[25];
	ll n, k, numb2 = 0, n2, ans, abc;
	ll per[15], per2[15];
	vector<ll> fact;
	cin >> n >> k;
	n2 = n;
	while (n % 2 == 0)
	{
		n /= 2;
		++numb2;
	}
	for (int i = 3; i <= ceil(sqrt((double)n)); ++i)
	{
		while (n % i == 0)
		{
			n /= i;
			fact.push_back(i);
		}
	}
	if (n != 1)
		fact.push_back(n);
	n = n2;
	if (numb2 >= k)
	{
		for (int i = 0; i < k; ++i)
			n /= 2;
		cout << n;
		return 0;
	}
	for (int i = 0; i < numb2; ++i)
		n /= 2;
	k -= numb2;
	if (fact.size() <= k)
	{
		for (int i = 0; i < fact.size(); ++i)
			n = n / fact[i] * (fact[i] / 2 + 1);
		cout << n;
		return 0;
	}
	else
	{
		if (k == 1)
		{
			ll p = 1;
			for (int i = 0; i < fact.size(); ++i)
				p *= fact[i];
			cout << p / 2 + 1;
			return 0;
		}
		ans = inf;
		step[0] = 1;
		abc = 1;
		while (step[abc - 1] < 100000)
		{
			step[abc] = step[abc - 1] * k;
			++abc;
		}
		for (int i = 0; i < 100000; ++i)
		{
			for (int j = 0; j < k; ++j)
				per2[j] = 1;
			for (int j = 0; j < fact.size(); ++j)
			{
				per[j] = (i % step[j + 1]) / step[j];
				per2[per[j]] *= fact[j];
			}
			ll curans = 1;
			for (int j = 0; j < k; ++j)
				curans *= per2[j] / 2 + 1;
			if (curans < ans)
				ans = curans;
		}
		cout << ans;
		return 0;
	}
	return 0;
}