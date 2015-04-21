#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cassert>	

using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;

const int Q= 1e9 + 8;
const int M = 1e3 + 10;
int a[100000];
int inv[M][M], inv1[M][M];
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i, j, ans = -1, cnt, t;
	int p1 = -1;
	int p2 = -1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (a[i] < a[j])
				continue;
			cnt = 0;
			for (t = i + 1; t < j; t++)
				if (a[i] > a[t] && a[t] > a[j])
					cnt++;
			if (cnt > ans){
				ans = cnt;
				p1 = i + 1;
				p2 = j + 1;
			}	
		//	cerr << i << " " << j << " " << cnt << endl;
			inv[i][j] = - 2 * cnt - 1;
		}
	}

	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (a[i] < a[j])
				continue;
			for (t = i + 1; t < j; t++){
				if (a[i] < a[t])
					inv1[i][j]++;
				else
					inv1[i][j]--;
				if (a[t] < a[j])
					inv1[i][j]++;
				else
					inv1[i][j]--;	
			}
			inv1[i][j]--;
			if (inv[i][j] != inv1[i][j]){
				cerr << i << " " << j <<  " " << inv[i][j] << " " << inv1[i][j] << endl;
			}
		}
	}
	cout << p1 << " " << p2 << endl;
	return 0;
}