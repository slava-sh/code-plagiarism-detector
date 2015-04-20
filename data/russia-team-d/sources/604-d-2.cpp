#include <cstdio>
#include <algorithm>

using namespace std;
long long a[int(1e5) + 10];

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	long long n, k;
	scanf("%I64d%I64d", &n, &k);
	for ( int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	long long l = 1;
	long long r = a[0] + 1;
	long long x = 1;
	long long c1 = 0;
	for ( int i = 0; i < n; i++)
		c1 += max(a[i] - c1, x);	
 	if ( c1 > k)
 	{
 		printf("0");
 		return 0;
 	}
 	while ( r - l > 1)
 	{
 		x = (r + l) / 2;
 		c1 = 0;
		for ( int i = 0; i < n; i++)
			c1 += max(a[i] - c1, x);	
 		if ( c1> k)
 			r = x;
	 	else
	 		l = x;
 	}
 	printf("%I64d", l);
	return 0; 
}