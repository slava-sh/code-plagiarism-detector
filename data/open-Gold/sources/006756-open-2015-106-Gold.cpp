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

const int nmax = 4000;
const int inf = 1000 * 1000 * 1000;
const ll infll = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
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

ll n, k, l[nmax], r[nmax], c, d;
vector<ll> a;

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> n >> k >> c >> d;
	ll t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
		t += r[i] - l[i];
	}
	ll answer = t * d;
	for (int i = 1; i < n; i++)
		a.pb(l[i] - r[i - 1]);
	sort(a.begin(), a.end());
	ll answera = (n / k - 1 + (n % k != 0)) * c + t * d, sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		sum += a[i];
		answera = min(answera, answer + sum * d + ((n - i - 1) / k - 1 + ((n - i - 1) % k != 0)) * c);
	}	
	cout << answera << endl;
}