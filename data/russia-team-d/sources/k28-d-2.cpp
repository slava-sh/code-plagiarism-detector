#ifdef WIN_32
	#define I "%I64d"
		#else
	#define I "%lld"
#endif
#include<map>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

#define y1 google
#define INF 2147483647
#define fname "fence"

using namespace std;

const int N = 100500;
long long n, m, a[N], i, k, l, r, mid, ans;

bool go(int x)	{
	long long m = 0, d = 0;
	for (i = 1; i <= n; i++)	{
		if (a[i] > m)	{
			if (a[i] - m >= x)
				m = a[i];
			else
				m += x;
		}
		else
			m += x;
	}
	if (m <= k)
		return true;
	return false;
}

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	scanf(I I, &n, &k);
	for (i = 1; i <= n; i++)
		scanf(I, &a[i]);
	sort(a + 1, a + n + 1);
	l = 1;
	r = k;
	while(l <= r)	{
		mid = (l + r) / 2;
		if (go(mid))	{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout<<min(ans, a[1]);
	return 0;
}

