#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define MAXN int(1e3 + 10)
#define INF int(1e9)
using namespace std;
long long n, m, l[MAXN], r[MAXN], x2[MAXN], q;

int main(){
	freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i] >> x2[i];
	for(int i = 0; i < m; i++){
		cin >> q;
		long long ans = 0;
		for(int j = 0; j < n; j++)
			if(l[j] <= q && q <= r[j]){
				if(q - l[j] % 2 == 1)
					ans -= x2[j];
				else
					ans += x2[j];
			}
	  cout << ans << "\n";
	}
  return 0;
}