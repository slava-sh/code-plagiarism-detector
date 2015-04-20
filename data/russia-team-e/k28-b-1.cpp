#include<cstdlib>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>

#define y1 google
#define INF 2147483647
#define fname "che"

using namespace std;

int n, a[300100], p = 1, i, k;
long long ans;

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
	for (i = 2; i <= n; i++)
		while(a[i] - a[p] > k && i > p)	{
			ans += 1ll * (n - i + 1);
			p++;
		}
	cout<<ans;
	return 0;
}

