#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	long long n, d;
	long long i, ans = 0;
	cin >> n >> d;
	vector<long long> a(n);
	sort(a.begin(), a.end());
	int z  = 0;
	int cnt = 0;
	for(i = 0; i < n; i++)
		cin >> a[i];
		
	for(i = n - 1; i >= 0; i--) {
		if(a[i] >= d * 3 || (a[i] > d * 2 && z < 2)) {
			ans += a[i];
			cnt++;
			if(a[i] < d * 3) {
				z++;
			}
		}
	}
	ans = ans - (d * (2 * (cnt - 1)));
	cout << ans;
}