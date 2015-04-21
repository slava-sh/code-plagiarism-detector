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
const ll p1 = 37;
const ll p2 = 31;
const ll mod2 = (ll)1e9 + 9;


string ar;
pll hash1[100500];
pll st[100500];
pll gethash(int l, int r) {
	pll ans = hash1[r];
	if (l) {
		ans.first -= hash1[l - 1].first;
		ans.second -= hash1[l - 1].second;
		ans.second += mod2;
		ans.second %= mod2;
	}
	return ans;
}
pll norm(pll a, int l) {
	a.first *= st[l].first;
	a.second *= st[l].second;
	a.second %= mod2;
	return a;
}
int check(int l1, int r1, int l2, int r2) {
	if (r1 - l1 != r2 - l2) {
		return 0;
	}
	pll a = gethash(l1, r1), b = gethash(l2, r2);
	a = norm(a, max(l1, l2) - l1);
	b = norm(b, max(l1, l2) - l2);
	return a == b;
}
int check1(int l1, int r1, int l2, int r2) {
	if (r1 - l1 != r2 - l2) {
		return 0;
	}
	for (int i = 0; l1 + i <= r1; ++i) {
		if (ar[i + l1] != ar[i + l2]) {
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int l;
	cin >> l >> ar;
	int a, b, c;
	a =b = c = 0;
	int n = (int)ar.size();
	if (l >= n) {
		cout << 1 << endl << ar;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (ar[i] == 'a') {
			a = 1;
		}
		if (ar[i] == 'b') {
			b = 1;
		}
		if (ar[i] == 'c') {
			c = 1;
		}
	}
	int d = a + b + c;
	if (d == 1) {
		cout << 1 << endl;
		if (a) {
			cout << 'a' << endl;
		}
		if (b) {
			cout << 'b' << endl;
		}
		if (c) {
			cout << 'c' << endl;
		}
		return 0;
	}
	pll p = mp(1, 1);
	for (int i = 0; i < n; ++i) {
		if (i) {
			hash1[i] = hash1[i - 1];
		}
		hash1[i].first += p.first * (ll)(ar[i] - 'a' + 1);
		hash1[i].second += p.second * (ll)(ar[i] - 'a' + 1);
		hash1[i].second %= mod2;
		p.first *= p1;
		p.second *= p2;
		p.second %= mod2;
	}
	p = mp(1, 1);
	for (int i = 0; i < 100000; ++i) {
		st[i] = p;
		p.first *= p1;
		p.second *= p2;
		p.second %= mod2;
	}
	for (int i = 1; i <= l; ++i) {
		int j = 0;
		while (j < n) {
			if (j + i <= n && check1(0, i - 1, j, j + i - 1)) {
				j += i;
			}
			else {
				break;
			}
		}
		if (j == n) {
			cout << 1 << endl;
			for (int j = 0; j < i; ++j) {
				cout << ar[j];
			}
			return 0;
		}
	}
	if (d == 2) {
		cout << 2 << endl;
		if (a) {
			cout << 'a' << endl;
		}
		if (b) {
			cout << 'b' << endl;
		}
		if (c) {
			cout << 'c' << endl;
		}
		return 0;
	}
	for (int i = 1; i <= l; ++i) {
		int j = 0;
		while (j < n) {
			if (j + i <= n && check1(0, i - 1, j, j + i - 1)) {
				j += i;
			}
			else {
				for (int k = j, r1 = 1; k + r1 <= n && r1 <= l; ++r1) {
					j += r1;
					while (j < n) {
						if (j + i <= n && check1(0, i - 1, j, j + i - 1)) {
							j += i;
						}
						else {
							if (j + r1 <= n && check1(k, k + r1 - 1, j, j + r1 - 1)) {
								j += r1;
							}
							else {
								break;
							}
						}
					}
					if (j == n) {
						cout << 2 << endl;
						for (int j = 0; j < i; ++j) {
							cout << ar[j];
						}
						cout << endl;
						for (int j = 0; j < r1; ++j) {
							cout << ar[k + j];
						}
						return 0;
					}
				}
			}
		}
	}
	cout << "3\na\nb\nc";

	return 0;
}