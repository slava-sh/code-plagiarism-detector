#include <cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int a[100000 + 7];

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);

	int n, d;
    long long res = 0;
	scanf("%d%d", &n, &d);
	for ( int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}	
	sort(a, a + n);
	int fl = 0;
    res = a[n - 1];
    if (a[n - 1] < 3*d) fl++;
	for ( int i = n - 2; i > -1; i--)
	{	
		if ( a[i] >= 3 * d)
        	res = res + a[i] - 2 * d;
        if (a[i] < 3*d && a[i] >= 2*d && fl < 2)
           res = res + a[i] - 2*d;	
	}
	printf("%I64d", res);


	return 0;	
}