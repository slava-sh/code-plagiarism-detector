#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define sqr(x) ((x) * (x))
#define forn(i, n) for (int i = 0; i < n; i++)

const int INF = (int)1e9;

int main()
{
	freopen("prizes.in", "rt", stdin);
	freopen("prizes.out", "wt", stdout);
	
	int n, m;
	cin >> n >> m;
	if (n > m)
		swap(n, m);
	if (n == 1)
		cout << abs(ceil(double(double((m - 2)) / 4)));
	else
		cout << abs(ceil(double(double((n - 2)) / 4)));
}