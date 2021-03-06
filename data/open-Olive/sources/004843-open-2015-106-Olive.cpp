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

int change(int ind1, int ind2)
{
	return lass[ind2][ind2] - lass[ind2][ind1 + 1] - mare[ind2][ind2] + mare[ind2][ind1 + 1] - lass[ind1][ind2] + lass[ind1][ind1 + 1] + mare[ind1][ind2] - mare[ind1][ind1 + 1] + (a[ind1] < a[ind2] ? 1 : -1);
}

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
		for (int j = 0; j < n; j++)
		{
			lass[i][j + 1] = lass[i][j];
			mare[i][j + 1] = mare[i][j];
			if (a[j] < a[i])
				lass[i][j + 1]++;
			else if (a[j] > a[i])
				mare[i][j + 1]++;
		}
	}
	ll ind1 = 0, ind2 = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (change(ind1, ind2) > change(i, j))
				ind1 = i, ind2 = j;
		}
	if (change(ind1, ind2) > 0)
		cout << -1 << " " << -1 << endl;
	else
		cout << ind1 + 1 << " " << ind2 + 1 << endl;
}