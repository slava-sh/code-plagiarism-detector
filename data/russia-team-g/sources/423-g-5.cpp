#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>


using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	long long h, w;
	scanf("%lld %lld", &h, &w);
	if (h == 1 && w == 1)
	{
		printf("0");
		return 0;
	}
	if (h == 1 && w != 1)
	{
		printf("%lld", (w + 1) / 4);
		return 0;
	}
	if (w == 1 && h != 1)
	{
		printf("%lld", (h + 1) / 4);
		return 0;
	}
	if (w == 2 || h == 2)
	{
		printf("%d", 0);
		return 0;
	}
	
	printf("1");
	return 0;
}


