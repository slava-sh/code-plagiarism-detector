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


int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
	}
	bool flag = 1;
	for (int i = 1; i < n; ++i) {
		if (ar[i] < ar[i - 1]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << -1 << ' ' << -1;
		return 0;
	}
	pii ans;
	int res = 0;
	for (int i=  0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (ar[i] < ar[j]) {
				continue;
			}
			int a = 1;
			for (int q = i + 1; q < j; ++q) {
				if (ar[q] > ar[j] && ar[q] < ar[i]) {
					++++a;
				}
			}
			if (a > res) {
				res = a;
				ans = mp(i, j);
			}
		}
	}
	cout << ans.first + 1 << ' ' << ans.second + 1;
	return 0;
}