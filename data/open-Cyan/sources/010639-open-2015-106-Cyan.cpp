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

const int nmax = 5002;
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

ll a[nmax], n, lass[nmax][nmax], mare[nmax][nmax];
pair<ll, ll> b[nmax];

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = mp(a[i] - i, i);
	}
	sort(b, b + n);
	if (b[0].first == 0 && b[n - 1].first == 0)
		cout << "-1 -1" << endl;
	else
		cout << b[0].second << " " << b[n - 1].second << endl;	
}