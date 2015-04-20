#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

#define goo(i,k,n) for(int i=k;i<n;i++)
#define go(i,n) goo(i,0,n)
#define ll long long
#define f first
#define s second

using namespace std;
ll a[1000005], k ,x=0, n, m;
bool used[100008];
ll ans = 1000000000;

int main(){
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin>>n>>k;
	ll maxa=0, mina=1000000000ll;
	go(i,n)
		cin>>a[i];	
	sort(a, a + n);
	ll minnezakr = k / n;
	int e = 0;
	for (int i = 0; i < n; i++) {
		ll kolvo = 0;
		for (int j = e; j < a[i] + e; j++)
			if (used[j] == 0) {
				kolvo++;
				used[j] = 1;
			}
		int u = 0;
//
		while (kolvo < minnezakr - 1 && a[i] + u < k) {
				kolvo++;
				used[a[i] + u] = 1;
				u++;
				e++;

		}
//	cout << kolvo << " ";
		ans = min(kolvo, ans);
		if (i == n - 1)
			ans += kolvo / (minnezakr - 1);
	}
	if (ans < a[0])
		cout << ans;
	else
		cout << a[0];			
	return 0;
}




