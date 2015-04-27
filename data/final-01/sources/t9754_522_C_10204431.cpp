#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 100010
#define mmax 100010
#define eps 1e-6

int iterations, n, k, m;
int a[nmax], b[nmax], c[nmax];
int t[nmax], x[nmax];
int df[nmax];

void calc(int &cnt, int &ind) {
	int val = inf;
	for(int i = 1; i <= k; ++i) {
		if(val > df[i]) {
			val = df[i];
		}
	}
	for(int i = 1; i <= k; ++i) {
		if(df[i] <= cnt) {
			b[i] = 0;
		}
	}
	cnt -= val;
	ind = 1;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
	scanf("%d", &iterations);
	while(iterations --> 0) {
		scanf("%d%d", &m, &k);
		for(int i = 1; i <= k; ++i) {
			scanf("%d", &a[i]);
			c[i] = b[i] = a[i];
			df[i] = inf;
		}
		for(int i = 1; i < m; ++i) {
			scanf("%d%d", &t[i], &x[i]);
			if(t[i] > 0) {
				--b[t[i]];
			}
		}
		for(int i = 1; i <= k; ++i) {
			if(a[i] == b[i]) {
				df[i] = b[i];
			}
		}
		int c0 = 0, c1 = 0, ind = 0;
		for(int i = 1; i < m; ++i) {
			if(t[i] == 0) {
				if(x[i] == 0) {
					++c0;
				} else {
					++c1;
					if(ind == 0) {
						calc(c0, ind);
					}
				}
			} else {
				if(x[i] == 1) {
					if(ind == 0) {
						calc(c0, ind);
					}
				}
				if(--c[t[i]] == b[t[i]]) {
					df[t[i]] = b[t[i]];
				}
			}
		}
		for(int i = 1; i <= k; ++i) {
			if(b[i] <= c0 + c1) {
				putchar('Y');
			} else {
				putchar('N');
			}
		}
		puts("");
	}
	getchar(); getchar();
	return 0;
}  