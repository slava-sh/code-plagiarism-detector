#include <cstdio>
#include <algorithm>
using namespace std;



int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	
	scanf("%d%d", &n, &m);
	if ( m == 2 || n == 2)
	{
		printf("0");
		return 0;
	}
	if ( m == 1 || n == 1)
	{
		n += 1;
		m += 1;
		printf("%d", max(m/ 4, n / 4));
		return 0;
	}
	printf("1");






	return 0;
}