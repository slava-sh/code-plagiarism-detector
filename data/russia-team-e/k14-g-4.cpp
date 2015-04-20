#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "prizes."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long

const int MAXN = 100500;
const int INF = 1 << 30;

int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		ll n, m, ans = 0;
		cin >> n >> m;
		if (n > m)
			swap(n, m);
		if (n == 1) {
			if (m < 3)
				cout << 0;
			else
				cout << (m - 3) / 4 + 1;
		}
		else {
			if (n < 3)
				cout << 0;
			else	
				cout << 1;
		}
	return 0;
}
