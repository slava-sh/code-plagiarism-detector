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
int l, top;
string s, s2, s1[nmax];

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

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);
	while (b != 0)
	{
		a = a % b;
		swap(a, b);
	}
	return a;
}

int main()
{
	freopen("input.txt", "r", stdin);freopen(NAME"output.txt", "w", stdout);
	cin >> l;
	cin >> s;
	int n = s.length();
	if (n <= l)
	{
		cout << 1 << endl << s << endl;
		return 0;
	}
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
	for (int i = 1; i <= l; i++)
	{
		if (a[i] + i == n && n % i == 0)
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
	for (int i = 1; i <= l; i++)
	{
		top = 0;
		s1[0] = "";
		for (int j = i; j < n; j++)
		{
			if (a[j] < i)
				s1[top] += s[j];	
			else
			{
				j += i - 1;
				if (s1[top].length() != 0)
				{
					top++;
					s1[top] = "";
				}
			}	
		}
		if (s1[top].length() != 0)
			top++;
		int len = 0;
		for (int j = 0; j < top; j++)
		{
			if (len == 0)
				len = s1[j].length();
			else
				len = gcd(len, s1[j].length());
		}
		s2 = "";
		int rr = 0;
		for (int j = 0; j < top; j++)
		{
			for (int q = 0; q < (int)s1[j].length(); q++)
			{
				s2 += s1[j][q];
				rr++;
				if (rr % len == 0)
					s2 += '#';
			}
			assert(s2.back() == '#');
		}
		zfunc(s2, b);
		if (s2.length() > len + 1 && b[len + 1] + len + 1 != s2.length())
			continue;
		if (len <= l)
		{
			cout << 2 << endl;
			for (int j = 0; j < len; j++)
				cout << s2[j];
			cout << endl;
			for (int j = 0; j < i; j++)
				cout << s[j];
			return 0;	
		}
		s2 = "";
		for (int q = 0; q < len; q++)
			s2 += s1[0][q];
		zfunc(s2, b);
		for (int j = 1; j <= l; j++)
		{
			if (b[j] + j == (int)s2.length() && (int)s2.length() % j == 0)
			{                 
				cout << 2 << endl;
				for (int q = 0; q < i; q++)
					cout << s[q];
				cout << endl;
				for (int q = 0; q < j; q++)
					cout << s2[q];
				return 0;
			}
		}
	}
	cout << "3\na\nb\nc\n";
	return 0;
}