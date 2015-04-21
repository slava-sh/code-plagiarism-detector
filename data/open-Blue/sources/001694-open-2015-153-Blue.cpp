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

vector<int> kmp(string s)
{
	int j;
	vector<int> ans;
	for (int i = 0; i < s.length(); ++i)
		ans[i] = 0;
	for (int i = 1; i < s.length(); ++i)
	{
		j = ans[i - 1];
		while ((s[i] != s[j]) && (j > 0))
			j = ans[j - 1];
		if (s[i] == s[j])
			++j;
		ans[i] = j;
	}
	return ans;
}

int main()
{
	ll l, ans = 0;
	string a;
	bool c[3];
	cin.sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> l;
	cin >> a;
	for (int i = 0; i < 3; ++i)
		c[i] = false;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == 'a')
			c[0] = true;
		if (a[i] == 'b')
			c[1] = true;
		if (a[i] == 'c')
			c[2] = true;
	}
	for (int i = 0; i < 3; ++i)
	{
		if (c[i] == true)
			++ans;
	}
	if (ans == 1)
	{
		cout << 1 << endl;
		for (int i = 0; i < 3; ++i)
			if (c[i])
				cout << (char)('a' + i);
		return 0;
	}
	if (ans == 2)
	{
		for (int i = 1; i < l; ++i)
			for (int j = 0; j < a.length(); ++j)
			{
				if (a[j] != (a[j % (i + 1)]))
				{
					break;
				}
				if (j == a.length() - 1)
				{
					cout << 1 << endl;
					for (int k = 0; k <= i; ++k)
						cout << a[k];
					return 0;
				}
			}
		cout << 2 << endl;
		for (int i = 0; i < 3; ++i)
			if (c[i])
				cout << (char)('a' + i) << endl;
		return 0;
	}
	if (ans == 3)
	{
		for (int i = 1; i < l; ++i)
			for (int j = 0; j < a.length(); ++j)
			{
				if (a[j] != (a[j % (i + 1)]))
				{
					break;
				}
				if (j == a.length() - 1)
				{
					cout << 1 << endl;
					for (int k = 0; k <= i; ++k)
						cout << a[k];
					return 0;
				}
			}
		if (l >= a.length() / 2 + a.length() % 2)
		{
			cout << 2 << endl;
			for (int i = 0; i < a.length() / 2 + a.length() % 2; ++i)
				cout << a[i];
			cout << endl;
			for (int i = a.length() / 2 + a.length() % 2; i < a.length(); ++i)
				cout << a[i];
			return 0;
		}
		cout << 3 << endl;
		for (int i = 0; i < 3; ++i)
			cout << (char)('a' + i) << endl;
	}
	return 0;
}