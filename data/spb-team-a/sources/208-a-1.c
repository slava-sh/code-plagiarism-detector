#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *in, *out;
	int t, n, l, r;
	in = fopen("abcd.in", "r");
	out = fopen("abcd.out", "w");
	fscanf(in, "%d", &t);
	while (t-- > 0)
	{
		fscanf(in, "\n%d", &n);
		l = n / 100;
		r = n % 100;
		fputs((((l * l + r * r) % 7) == 1) ? "YES\n" : "NO\n", out);
	}
	fclose(out);
	return 0;
}
