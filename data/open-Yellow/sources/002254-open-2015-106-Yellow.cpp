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

int a[nmax], n, q, x, ind;


int main()
{
	freopen(NAME"input.txt", "r", stdin);freopen(NAME"output.txt", "w", stdout);
	scanf("%d", &n);
	int dif = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (i != 0 && a[i] != a[i - 1])
			dif++;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &ind, &x);
		ind--;
		if (ind != 0 && a[ind] == a[ind - 1])
			dif++;
		if (ind != n - 1 && a[ind] == a[ind + 1])
			dif++;	
		if (ind != 0 && x == a[ind - 1])
			dif--;
		if (ind != n - 1 && x == a[ind + 1])
			dif--;
		a[ind] = x;
		printf("%d\n", dif);
	}
}