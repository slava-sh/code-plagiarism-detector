#include <cstdio>


int a[int(3e5) + 10];

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n, r;
	scanf("%d%d", &n, &r);

	for ( int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int pos = 1;
	long long res = 0;
	for ( int i = 0; i < n; i++)
	{
		while (pos < n && a[i] + r >= a[pos] )
			pos++;
		if ( pos == n)
			break; 
		res += n - pos;
	}             
	printf("%I64d", res);

	return 0;
}

