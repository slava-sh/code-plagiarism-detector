#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	FILE *F;
	FILE *F1;
	int t, i, num;
	if ((F = fopen("abcd.in", "r")) == NULL)
		return 0;
	F1 = fopen("abcd.out", "w");
	fscanf(F, "%d", &t);
	for (i = 1; i <= t; i++)
	{
		fscanf(F, "%d", &num);
		if ((((num / 100) * (num / 100)) + ((num % 100)*(num % 100))) % 7 == 1)
			fprintf(F1, "YES\n");
		else
			fprintf(F1, "NO\n");
	}
	fclose(F);
	fclose(F1);
	return 1;
}