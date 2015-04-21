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

const int S = 301;

char c;
int r, u, r1, u1;

int main()
{
//	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	r = 1;
	u = 1;
	r1 = 1;
	u1 = 1;
	int f = 1;
	while (true)
	{
		if (f == 1 && r1 == 0)
		{
       		f = 2;
       		r++;
       		r1 = r;
		}
		if (f == 2 && u1 == 0)
		{
			f = 3;
			u++;
			u1 = u;
		}
		if (f == 3 && r1 == 0)
		{
			f = 4;
			r++;
			r1 = r;
		}
		if (f == 4 && u1 == 0)
		{
			f = 1;
			u++;
			u1 = u;
		}
		if (f == 1)
		{
			cout << "R" << endl;
			r1--;
		}
		if (f == 2)
		{
			cout << "U" << endl;
			u1--;
		}
		if (f == 3)
		{
			cout << "L" << endl;
			r1--;
		}
		if (f == 4)
		{
			cout << "D" << endl;
			u1--;
		}
		cin >> c;
		if (c == 'Y' || c == 'E')
			return 0;
	}
	return 0;
}