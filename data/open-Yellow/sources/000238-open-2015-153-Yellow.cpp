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



ll n, t[maxn], q, cur = 1, a, b;

void mod(int c, int d)
{
	if (t[c] == d)
		return;
	if (c == 0)
	{
		if (t[c] == t[c + 1])
			++cur;
		if (d == t[c + 1])
			--cur;
		t[0] = d;
		return;
	}
	if (c == n - 1)
	{
		if (t[c] == t[c - 1])
			++cur;
		if (d == t[c - 1])
			--cur;
		t[c] = d;
		return;
	}
	if (t[c - 1] == t[c])
		++cur;
	if (t[c + 1] == t[c])
		++cur;
	if (t[c - 1] == d)
		--cur;
	if (t[c + 1] == d)
		--cur;
	t[c] = d;
	return;
}


int main()
{
	cin.sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	if (n == 1)
	{
		cin >> t[0];
		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			cin >> a >> b;
			cout << 1 << '\n';
		}
		return 0;	
	}
	for (int i = 0; i < n; ++i)
		t[i] = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		mod(i, a);
	}
	cin >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		--a;
		mod(a, b);
		cout << cur << '\n';
	}
	return 0;
}