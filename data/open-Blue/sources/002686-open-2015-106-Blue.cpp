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
const ll mod = 1000 * 1000 * 1000 + 7;

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

string s;
int l;

int main()
{
	freopen(NAME"input.txt", "r", stdin);freopen(NAME"output.txt", "w", stdout);
	cin >> l;
	getline(cin, s);
	getline(cin, s);
	int n = s.length();
	if (n <= l)
	{
		cout << "1\n" << s << "\n";
		return 0;
	}
	int fa = 0, fb = 0, fc = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'a')
			fa = 1;
		else if (s[i] == 'b')
			fb = 1;
		else if (s[i] == 'c')
			fc = 1;
		else
			assert(false);
	if (fa + fb + fc == 1)
	{
		cout << "1\n";
		if (fa)
			cout << "a\n";
		if (fb)
			cout << "b\n";
		if (fc)
			cout << "c\n";
		return 0;	
	}	
	for (int len = 1; len <= l; len++)
	{
		bool f = true;
		for (int j = 0; j < n; j++)
			if (s[j] != s[j % len])
			{
				f = false;
				break;
			}
		if (f)
		{
			cout << "1\n";
			for (int j = 0; j < len; j++)
				cout << s[j];
			cout << "\n";
			return 0;
		}	
	}
	if (fa + fb + fc == 2)
	{
		cout << "2\n";
		if (fa)
			cout << "a\n";
		if (fb)
			cout << "b\n";
		if (fc)
			cout << "c\n";
		return 0;
	}
	assert(false);
}