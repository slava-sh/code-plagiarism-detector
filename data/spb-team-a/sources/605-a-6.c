//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void )
{
	int a, b, c, n, i;
	FILE *F1 = fopen("abcd.in", "rt");
	FILE *F2 = fopen("abcd.out", "wt");
	/*freopen("abcd.in", "rt", stdin);
	freopen("abcd.out", "wt", stdout); */
	fscanf(F1, "%i", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(F1, "%i", &c);
		b = c % 100;
		a = c / 100;
		if ((a * a + b * b) % 7 == 1)
			fprintf(F2, "YES\n");
		else
			fprintf(F2, "NO\n");
	}
	return 0;
}