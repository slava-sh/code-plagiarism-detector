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

ll n, k;
multiset<ll> a;

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> n >> k;
	ll n1 = n;
	while (n % 2 == 0 && k > 1)
	{
		n /= 2;
		k--;
	}
	for (ll i = 2; i * i <= n1; i++)
	{
		while (n % i == 0)
		{
			n /= i;
			a.insert(i);
		}
	}
	a.insert(n);
	while (a.size() > k)
	{
		multiset<ll>::iterator it = a.begin();
		multiset<ll>::iterator it1 = a.begin();
		it1++;
		ll qq = (*it) * (*it1);
		a.erase(it);
		a.erase(it1);
		a.insert(qq);
	}
	ll answer = 1;
	for (multiset<ll>::iterator it = a.begin(); it != a.end(); it++)
		answer *= (*it + 1) / 2;
	cout << answer << endl;
}