#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

#define FNAME "fence"
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int n, l, r, m, boo, k, a[100001];
LL x, sum;

int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d%d", &n ,&k);
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	l = 0, r = a[0] + 1;
	while (r - l > 1)
	{
		m = (l + r) / 2;
		x = a[0];
		sum = a[0];
		boo = 1;
		for (int i = 1; i < n; i++)
		{
			if (k - x < m)
				boo = 0;
			x = max(a[i] * 1ll, x + m);
		}
		if (boo)
			l = m;
		else
			r = m;
//		printf("%d %d %d\n", l, r, m);
	}
		
	printf("%d\n", l);
	return 0;
}