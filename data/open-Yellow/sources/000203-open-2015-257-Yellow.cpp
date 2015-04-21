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

struct uch{
	int l, r;
	uch() : l(-1), r(-1){}
};
int c[100500];
uch ar[100500];
int ans = 1, n;
void upd(int d, int t) {
	int cl, cr;
	if (c[t] == d) {
		return;
	}
	if (ar[t].l == -1) {
		if (ar[t].r == -1) {
			c[t] = d;
			return;
		}
		cr = c[ar[t].r];
		if (cr == c[t]) {
			++ans;
		}
		else {
			if (d == cr) {
				--ans;
			}
		}
		c[t] = d;
		return;
	}
	if (ar[t].r == -1) {
		cl = c[ar[t].l];
		if (cl == c[t]) {
			++ans;
		}
		else if(d == cl) {
			--ans;
		}
		c[t] = d;
		return;
	}
	cl = c[ar[t].l];
	cr = c[ar[t].r];
	if (cl == cr) {
		if (c[t] == cl) {
			++++ans;
		}
		else if (cl == d) {
			----ans;
		}
		c[t] = d;
		return;
	}
	if (c[t] == cl || c[t] == cr) {
		++ans;
	}
	if (d == cl || d == cr) {
		--ans;
	}
	c[t] = d;
	return;
}

int main(){
	freopen("input.txt", " r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i=  0; i < n; ++i) {
		if (i != n - 1) {
			ar[i].r = i + 1;
		}
		if (i) {
			ar[i].l = i -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		upd(a, i);
	}
	int m;
	cin >> m;
	for (;m; --m) {
		int t, d;
		cin >> t >> d;
		upd(d, t - 1);
		cout << ans << endl;
	}

	return 0;
}