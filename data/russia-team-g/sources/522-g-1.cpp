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

int n, m;

int main()
{
	freopen("prizes.in", "rt", stdin);
	freopen("prizes.out", "wt", stdout);
	cin >> n >> m;
	if (n > m)
		swap(n, m);
	int h = (n - 2) / 4;
	if ((n - 2) % 4 != 0)
		h++;
	if (n == 2)
		 h = 0;
	
	if (n == 1) {
		h = (m - 2) / 4;
		if ((m - 2) % 4 != 0)
			h++;
		if (m == 2)
			h = 0;
		if (m == 1)
			h = 0;
	}
	cout << h;

}