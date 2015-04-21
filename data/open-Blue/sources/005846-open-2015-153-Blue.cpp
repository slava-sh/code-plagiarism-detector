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

const ll maxn = 1000;
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
		ans.push_back(0);
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

bool ttry(string s, string a, string b)
{
	vector<int> kmp1 = kmp(a + '$' + s);
	vector<int> kmp2 = kmp(b + '$' + s);
	ll a1 = a.length();
	ll b1 = b.length();
	bool pos[maxn];
	for (int i = 0; i < maxn; ++i)
		pos[i] = false;
	pos[s.length()] = true;
	for (int i = s.length(); i > 0; --i)
	{
		if (!pos[i])
			continue;
		if (kmp1[i + a1] == a1)
			pos[i - a1] = true;
		if (kmp2[i + b1] == b1)
			pos[i - b1] = true;
	}
	return pos[0];
}

int main()
{
	ll l, ans = 0;
	string em;
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
				if ((a.length() % (i + 1)) != 0)
					break;
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
				if ((a.length() % (i + 1)) != 0)
					break;
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
		string s;
		s += a[0];
		for (int i = 1; i < l; ++i)
		{
			s += a[i];

			vector<int> kmpp = kmp(s + '$' + a);
			ll j = i;
			while ((j + 2 * s.length() + 1 < kmpp.size()) && (kmpp[j + 2 * s.length() + 1] == s.length()))
				j += s.length();
			string s2;
			s2 = em;
			++j;
			for (;j < i + 2 + a.length(); ++j)
			{
				s2 += a[j];
				if (ttry(a, s, s2))
				{
					cout << 2 << endl;
					cout << s << endl;
					cout << s2 << endl;
					return 0;
				}
			if (s2.length() == l)
					break;
			}
		}
		cout << 3 << endl;
		for (int i = 0; i < 3; ++i)
			cout << (char)('a' + i) << endl;
	}
	return 0;
}
/*
7
acabacabacaacab
3
abcabca
*/