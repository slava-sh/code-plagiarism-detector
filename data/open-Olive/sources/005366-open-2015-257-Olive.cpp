#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <cstdio>
#include <memory.h>
#include <iostream>
#include <cmath>
#include <queue>

#pragma comment(linker, "/STACK:64000000")

using namespace std;

#define mp make_pair
#define pi M_PI

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pldld;

const int infi = (int)1e9 + 7;
const ll infl = (ll)1e18 + 7;
const ld eps = (ld)(1e-8);
const int it = 1000000;

int ar[100500];
int tree[17000];
void upd(int i, int l, int r, int t, int d) {
	if (d) {
		tree[i]++;
	}
	else {
		tree[i]--;
	}
	if (l == r) {
		return;
	}
	if (t <= ((l + r) >> 1)) {
		upd(i << 1, l, (l + r) >> 1, t, d);
	}
	else {
		upd((i << 1) + 1, ((l + r) >> 1) + 1, r, t, d);
	}
	return;
}
int getsum(int i, int tl, int tr, int l, int r) {
	if (l > r){
		return 0;
	}
	if (l == tl && r == tr) {
		return tree[i];
	}
	return getsum(i << 1, tl, (tl + tr) >> 1, l, min((tl + tr) >> 1, r)) + getsum((i << 1) + 1, ((tl + tr) >> 1) + 1, tr, max(l, ((tl + tr) >> 1) + 1), r);
}

int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i =0 ; i < n; ++i) {
		cin >> ar[i];
	}
	int flag = 1;
	for (int i = 1; i < n; ++i) {
		if (ar[i] < ar[i - 1]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << "-1 -1";
		return 0;
	}
	int res = 0;
	pii ans;
	upd(1, 1, n, ar[0], 1);
	for (int i = 0; i < n; ++i) {
		upd(1, 1, n, ar[i], 0);
		int k = 0;
		if (i & 1) {
			for (int j = n- 1; j >= i + res / 2 + res % 2 + 1; --j) {
				upd(1, 1, n, ar[j], 0);
				--k;
				if (ar[i] < ar[j] || j < i + res / 2 + res % 2 + 1) {
					continue;
				}
				int s = getsum(1, 1, n, ar[j] + 1, ar[i] - 1) * 2 + 1;
				if (s > res) {
					res = s;
					ans = mp(i, j);
				}
			}
		}
		else {
			for (int j = k + 1; j < n; ++j) {
				++k;
				upd(1, 1, n, ar[j], 1);
				if (ar[i] < ar[j] || j < i + res / 2 + res % 2 + 1) {
					continue;
				}
				int s = getsum(1, 1, n, ar[j] + 1, ar[i] - 1) * 2 + 1;
				if (s > res) {
					res = s;
					ans = mp(i, j);
				}
			}
		}
	}
	cout << ans.first + 1 << ' ' << ans.second + 1;

	return 0;
}