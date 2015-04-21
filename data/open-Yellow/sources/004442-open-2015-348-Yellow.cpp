#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define localn
#define task "paul"
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 100010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



int p[N];

int main(){
#ifdef local
	freopen(task ".in", "r", stdin);
	freopen(task ".out", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	int n, tt, i;
	cin >> n;
	p[0] = p[n + 1] = inf;
	for (i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	int val = 0;
	for (i = 1; i <= n; i++){
		if (p[i] != p[i - 1]){
			val++;
		}
	}

	cin >> tt;
	int k, v;
	for (i = 0; i < tt; i++){
		scanf("%d %d", &k, &v);
		int l = k - 1, r = k + 1;
		if (p[l] == p[r] && p[l] == p[k]){
			if (p[k] != v){
				val += 2;
			}
		}
		else if (p[l] == p[k] || p[r] == p[k]){
			if (v != p[r] && v != p[l]){
				val++;
			}
		}
		else if (p[l] == v && p[r] == v){
			val -= 2;
		}
		else if (p[l] == v || p[r] == v){
			val--;
		}
		p[k] = v;
		printf("%d\n", val);
	}
	
	return 0;
}