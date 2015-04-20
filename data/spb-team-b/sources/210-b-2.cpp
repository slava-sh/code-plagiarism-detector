#include <stdio.h>
#include <math.h>
#include <algorithm>

int main(void)
{
	static int kal, n, Ch[1001][1001];
	
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		for (int j = 1; j <= a; j++)
			Ch[i][j] = 1;
	}

	int h = 1;

	while (Ch[n - h][h])
		h++, kal++;

	printf("%d\n", kal);
	h = 1;
	for (int j = 0; j < kal; j++)
	{
		printf("%d %d\n", h, h);
		h++;
	}

	return 0;
}