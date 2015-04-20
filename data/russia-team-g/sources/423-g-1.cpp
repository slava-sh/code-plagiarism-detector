#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>


using namespace std;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int h, w;
	scanf("%d %d", &h, &w);
	if (h == 1 && w != 1)
	{
		printf("%d", (h + 1) / 4);
		return 0;
	}
	if (w == 1 && h != 1)
	{
		printf("%d", (w + 1) / 4);
		return 0;
	}
	if (h < 3 && w < 3)
	{
		printf("0");
		return 0;
	}
	if (h < 3)
	{
		printf("%d", (w + 1) / 4);
		return 0;
	}
	if (w < 3)
	{
		printf("%d", (h + 1) / 4);
		return 0;
	}
	printf("%d", min((w + 1) / 4, (h + 1) / 4));
	return 0;
}


