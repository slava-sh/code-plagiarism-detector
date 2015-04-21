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


int n;
int res[1000500];
int a[1000500];
int fw[1000500];
int fww[1000500];
int fwww[1000500];

void update1(int i) {
	while (i <= n) {
		fw[i]++;
		i |= (i + 1);
	}
}

int getSum1(int r) {
	int res = 0;
	while (r > 0) {
		res += fw[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}

void update2(int i, int d) {
	while (i <= n) {
		fww[i] += d;
		i |= (i + 1);
	}
}

int getSum2(int r) {
	int res = 0;
	while (r > 0) {
		res += fww[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}

void update3(int i) {
	while (i <= n) {
		fwww[i]++;
		i |= (i + 1);
	}
}

int getSum3(int r) {
	int res = 0;
	while (r > 0) {
		res += fwww[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d", &n);
	memset(fw, 0, sizeof(fw));
	memset(fww, 0, sizeof(fww));
	memset(fwww, 0, sizeof(fwww));
	int best = 1;
	ll cur = 0LL;
	for (int i = 1; i <= n; i++) {
		scf("%d", &a[i]);
		res[i] = getSum1(n) - getSum1(a[i]);
		update1(a[i]);
		if (res[i] >= res[best]) best = i;
		cur += (1LL * res[i]);
	}
	ll temp = cur;
	ll ans = cur;
	bool f = false;
	int num = -1;
	for (int i = best - 1; i >= 1; --i) update2(a[i], 1);
	for (int i = 1; i < best; i++) {
		if (i == best) continue;
		cur = temp;
		cur -= (1LL * (getSum2(n) - getSum2(a[best])));
		cur += (1LL * (getSum2(n) - getSum2(a[i])));
		if (cur < ans) {
			f = true;
			ans = cur;
			num = i;
		}
		update2(a[i], -1);
	}
	if (!f) puts("-1 -1"); else cout << min(num, best) << " " << max(num, best) << endl;
	return 0;
}