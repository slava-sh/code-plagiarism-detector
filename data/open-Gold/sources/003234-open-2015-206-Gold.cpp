#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

typedef long long ll;

int n, k, c, d;
int a[200500], b[200500];

ll solve(int dist) {
	ll cost = 1LL * d * (b[1] - a[1]);
	int ost = k - 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] - b[i - 1] <= dist) cost += (1LL * d * (b[i] - b[i - 1]));
			else {
				if (ost == 0) {
					ost = k;
					cost += (1LL * c);
				}
				cost += (1LL * d * (b[i] - a[i]));
				--ost;
			}
	} 
	return cost;
}
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d%d%d%d", &n, &k, &c, &d);
	for (int i = 1; i <= n; i++) scf("%d%d", &a[i], &b[i]);
	int l = 0;
	int r = (int)1e9 + 2;
	while (r - l > 2) {
		int d = (r - l) / 3;
		int m1 = l + d;
		int m2 = r - d;
		if (solve(m1) < solve(m2)) 
			r = m2;
		else l = m1;
	}
	ll res = (ll)1e18;
	for (int i = max(0, l - 10); i <= r + 10; i++) res = min(res, solve(i));
	cout << res << endl;	
	return 0;
}