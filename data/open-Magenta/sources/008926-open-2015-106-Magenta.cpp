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
	while (true)
	{
		int qq = rand() % 5;
		for (int i = 0; i < 20 + qq; i++)
		{
			cout << "U" << endl;
			cin >> c;
			if (c == 'Y' || c == 'E')
				return 0;
		}
		qq = rand() % 7;
		for (int i = 0; i < 15 + qq; i++)
		{
			cout << "R" << endl;
			cin >> c;
			if (c == 'Y' || c == 'E')
				return 0;
		}
	}
	return 0;
}