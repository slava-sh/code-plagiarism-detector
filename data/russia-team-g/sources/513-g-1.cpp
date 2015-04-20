#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, l;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	scanf("%d%d", &n, &m);
	l = min(n, m) - 1;
	if (l % 4 <= 1)
	{
		printf("%d\n", l / 4);
	}              
	else
		printf("%d\n", l / 4 + 1);
	return 0;
}
