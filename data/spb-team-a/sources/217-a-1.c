#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int t, i, j, a[4], ab, cd;
	char s[5];
	freopen("abcd.in", "rt", stdin);
	freopen("abcd.out", "wt", stdout);
	scanf("%i", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%s", &s);
		for (j = 0; j < 4; j++)
			a[j] = s[j] - 48;
		cd = a[3] + a[2] * 10;
		ab = a[1] + a[0] * 10;
		if ((ab * ab + cd * cd) % 7 == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
