#include <cstdio>
#include <algorithm>

using namespace std;
int a[int(1e5) + 10];

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	for ( int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 1;
	//!!!
	int r = a[0];
	int x = 1;
	int c1 = 0;
	for ( int i = 0; i < n; i++)
		c1 += max(c1 - a[i], x);	
 	if ( c1 > k)
 	{
 		printf("0");
 		return 0;
 	}
 	x = r;
	c1 = 0;
	for ( int i = 0; i < n; i++)
		c1 += max(c1 - a[i], x);	
 	if ( c1 <=  k)
 	{
 		printf("%d", r);
 		return 0;
 	}
 	while ( r - l > 1)
 	{
 		x = (r + l) / 2;
 		c1 = 0;
		for ( int i = 0; i < n; i++)
			c1 += max(c1 - a[i], x);	
 		if ( c1> k)
 			r = x;
	 	else
	 		l = x;
 	}
 	printf("%d", l);
	return 0; 
}