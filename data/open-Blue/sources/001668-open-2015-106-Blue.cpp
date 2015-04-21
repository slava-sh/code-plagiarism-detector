#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <string>
#include <cstring>
#define NAME ""
#define mp make_pair
#define mt make_tuple
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int nmax = 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const ll infll = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const ld pi = acos(-1.0);
const ll mod = 528943543;
const ll p1 = 237;

template<typename T, typename T1>
ostream& operator <<  (ostream& cout, const pair<T, T1> &a)
{
	return (cout << "(" << a.first << "; " << a.second << ")");
}

template<typename T>
ostream& operator << (ostream& cout, const vector<T> &a)
{
	if (a.size() == 0)
		return (cout << "()");
	cout << "(";
	for (int i = 0; i < (int)a.size() - 1; i++)
		cout << a[i] << "; ";
	cout << a.back() << ")";
	return cout;
}

vector<int> a, b;
int l;
string s, s1;

void zfunc(string &s, vector<int> &a)
{
	int l = 0, r = 0, n = s.length();
	a.assign(s.length(), 0);
	for (int i = 1; i < n; i++)
	{
		if (i <= r)
			a[i] = min(r - i + 1, a[i - l]);
		while (i + a[i] < n && s[i + a[i]] == s[a[i]])
			a[i]++;
        if (i + a[i] - 1 > r)
        	l = i, r = i + a[i] - 1;
    }
}

int main()
{
	freopen("input.txt", "r", stdin);freopen(NAME"output.txt", "w", stdout);
	cin >> l;
	getline(cin, s);
	getline(cin, s);
	int n = s.length();
	int fa = 0, fb = 0, fc = 0;
	for (int i = 0; i < (int)s.length(); i++)
		if (s[i] == 'a')
			fa = 1;
		else if (s[i] == 'b')
			fb = 1;
		else if (s[i] == 'c')
			fc = 1;	
	if (fa + fb + fc == 1)
	{
		cout << 1 << endl;
		if (fa)
			cout << 'a';
		else if (fb)
			cout << 'b';
		else if (fc)
			cout << 'c';
		return 0;	
	}
	zfunc(s, a);
	for (int i = 0; i <= l; i++)
	{
		if (a[i] + i == n && a[i] % (i + 1) == 0)
		{                 
			cout << 1 << endl;
			for (int j = 0; j < i; j++)
				cout << s[j];
			return 0;
		}
	}
	if (fa + fb + fc == 2)
	{
		cout << 2 << endl;
		if (fa)
			cout << "a\n";
		if (fb)
			cout << "b\n";
		if (fc)
			cout << "c\n";
		return 0;	
	}
	for (int i = 0; i < l; i++)
	{
		s1 = "";
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < i + 1)
				s1 += s[j];
			else
			{
				j += i;
				if (s1.length() != 0)
					s1 += '#';
			}	
		}
		zfunc(s1, b);
		b[0] = s1.length();
		int len = s1.length();
		for (int j = 0; j < (int)s1.length(); j++)
			if (s1[j + b[j]] == '#')
			{
				len = j + 1;
				break;
			}
		cerr << len << endl;
		cerr << s1 << endl;
		bool found = true;
		if (len > l)
			found = false;
		for (int j = len - 1; j < (int)s1.length(); j++)
		{
			if (s1[j] == '#')
				continue;
			if (b[j] < len)
			{
				found = false;
				break;
			}
			j += len - 1;
		}
		if (found)
		{
			cout << 2 << endl;
			for (int j = 0; j <= i; j++)
				cout << s[j];
			cout << endl;
			for (int j = 0; j < len; j++)
				cout << s1[j];
			cout << endl;
			return 0;
		}	
	}
	cout << "3\na\nb\nc\n";
	return 0;
}