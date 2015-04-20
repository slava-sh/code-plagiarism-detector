#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define LLD "%I64d"

#define FILENAME "fence"

int n, k, l, r, mid, i;
int a[100100];

bool Check(int x)
{
	if (x > a[0])
		return 0;
	int i, curl = 0;
	for (i = 0; i < n; i++)
	{
		if (curl + x < a[i])
			curl = a[i];
		else
			curl += x;
		if (curl > k)
			return 0;
	}
	return (curl <= k);
}

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);

	l = 0;
	r = k + 1;
	while (r - l > 1)
	{
		mid = (r + l) / 2;
		if (Check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", l);

	return 0;
}