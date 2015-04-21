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

ll n, k, l[nmax], r[nmax];
ll c, d, dp[nmax][nmax];

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> n >> k >> c >> d;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			dp[i][j] = infll;
	dp[0][0] = (r[0] - l[0]) * d;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < k; j++)
			dp[i][j] = min(dp[i - 1][j] + d * (r[i] - r[i - 1]), dp[i - 1][(j == 0 ? k - 1 : j - 1)] + c * (j == 0) + d * (r[i] - l[i]));
	ll answer = infll;
	for (int i = 0; i < k; i++)
		answer = min(answer, dp[n - 1][i]);
	cout << answer << endl;
}