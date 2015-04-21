//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>
#define hash skfdsjldfjkldjrfl


using namespace std;

const long long mod1 = 2147483647;
const long long mod2 = 1000000009;

const long long p1 = 5;
const long long p2 = 7;

long long p_pow1[20001];
long long p_pow2[20001];

struct hash
{
	long long first;
	long long second;

	hash(long long first, long long second) : first(first), second(second) {}
	hash() {}

	void operator-=(hash x)
	{
		first -= x.first;
		second -= x.second;
		first = (first % mod1 + mod1) % mod1;
		second = (second % mod2 + mod2) % mod2;
	}

	void operator*=(int x)
	{
		first *= p_pow1[x];
		first %= mod1;
		second *= p_pow2[x];
		second %= mod2;
	}

	bool operator==(hash x)
	{
		return (first == x.first && second == x.second);
	}

	void operator=(hash x)
	{
		first = x.first;
		second = x.second;
	}
};

void init_hash()
{
	p_pow1[0] = 1;
	p_pow2[0] = 1;

	for (int i = 1; i <= 20000; i++)
	{
		p_pow1[i] = (p_pow1[i - 1] * p1) % mod1;
		p_pow2[i] = (p_pow2[i - 1] * p2) % mod2;
	}
}

hash get_hash(const string& s)
{
	hash ans = hash(0, 0);

	for (int i = 0; i < s.length(); i++)
	{
		ans.first += ((s[i] - 'a' + 1) * p_pow1[i]) % mod1;
		ans.first %= mod1;
		ans.second += ((s[i] - 'a' + 1) * p_pow2[i]) % mod2;
		ans.second %= mod2;
	}

	return ans;
}

int l;

string get_period1(const string& s)
{
	int n = s.length();
	int bound = min(l, n / 2);

	hash pref_hash[20001];
	pref_hash[0] = hash(0, 0);
	pref_hash[0].first += ((s[0] - 'a' + 1) * p_pow1[0]) % mod1;
	pref_hash[0].first %= mod1;
	pref_hash[0].second += ((s[0] - 'a' + 1) * p_pow2[0]) % mod2;
	pref_hash[0].second %= mod2;

	string pref = "";

	for (int i = 1; i < n; i++)
	{
		pref_hash[i] = pref_hash[i - 1];
		pref_hash[i].first += ((s[i] - 'a' + 1) * p_pow1[i]) % mod1;
		pref_hash[i].first %= mod1;
		pref_hash[i].second += ((s[i] - 'a' + 1) * p_pow2[i]) % mod2;
		pref_hash[i].second %= mod2;
	}

	for (int x = 2; x <= bound && x * x <= n; x++)
	{
		if (n % x != 0) continue;
		hash p = pref_hash[x - 1];
		bool ok = true;

		for (int i = x; i + x - 1 < n; i += x)
		{
			hash h = pref_hash[i + x - 1];
			h -= pref_hash[i - 1];
			p *= x;

			if (h == p) continue;
			ok = false;
			break;
		}

		if (ok)
			return s.substr(0, x);

		int x2 = n / x;
		if (x2 > bound) continue;

		p = pref_hash[x2 - 1];
		ok = true;

		for (int i = x2; i + x2 - 1 < n; i += x2)
		{
			hash h = pref_hash[i + x2 - 1];
			h -= pref_hash[i - 1];
			p *= x2;

			if (h == p) continue;
			ok = false;
			break;
		}

		if (ok)
			return s.substr(0, x2);
	}

	return " ";
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	init_hash();

	string s;
	bool a = false, b = false, c = false;

	cin >> l >> s;
	int n = s.length();

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a')
			a = true;
		else if (s[i] == 'b')
			b = true;
		else if (s[i] == 'c')
			c = true;
	}

	int count = 0;
	if (a) count++;
	if (b) count++;
	if (c) count++;

	if (n <= l)
	{
		cout << "1\n";
		cout << s;
		return 0;
	}

	if (count <= 1)
	{
		cout << "1\n";
		if (a) cout << 'a';
		if (b) cout << 'b';
		if (c) cout << 'c';
		return 0;
	}

	string s1 = get_period1(s);

	if (s1 != " ")
	{
		cout << "1\n";
		cout << s1;
		return 0;
	}

	if (n <= l * 2)
	{
		cout << "2\n";
		cout << s.substr(0, l) << '\n';
		cout << s.substr(l, n - l);
		return 0;
	}

	if (count == 2)
	{
		cout << "2\n";
		if (a) cout << "a\n";
		if (b) cout << "b\n";
		if (c) cout << "c\n";
		return 0;
	}

	/*pair<string, string> s2 = get_period2(s);

	if (s2.first != " ")
	{
		cout << "2\n";
		cout << s2.first << '\n' << s2.second;
		return 0;
	}*/

	cout << "3\na\nb\nc";

	return 0;
}