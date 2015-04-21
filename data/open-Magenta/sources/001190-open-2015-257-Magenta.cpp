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

void hod(int w, int h) {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << 'L' << endl;
			cout.flush();
			char a;
			cin >> a;
			if (a == 'E' || a == 'Y') {
				exit(0);
			}
		}
		cout << 'D' << endl;
			cout.flush();
			char a;
			cin >> a;
			if (a == 'E' || a == 'Y') {
				exit(0);
			}
	}
	return;
}

int main(){
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	for (int i = 1; i * i <= 2000; ++i) {
		int j = i;
		for (; j * i < 2000; ++j);
		hod(i, j);
		hod(j, i);
	}

	return 0;
}