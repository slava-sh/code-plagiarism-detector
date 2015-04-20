// Задача A
#include <stdio.h>
#include <math.h>

int main( void )
{
	int t;
	int i;
	FILE *IN, *OUT;

	if ((IN = fopen("abcd.in", "rt")) == NULL)
		return 1;
	if ((OUT = fopen("abcd.out", "wt")) == NULL)
	{
		fclose(IN);
		return 1;
	}

	fscanf(IN, "%i", &t);
	for (i = 1; i <= t; i++)
	{
		char tmp1, tmp2, tmp3, tmp4;
		int chislo1, chislo2;

		fscanf(IN, "\n");
		fscanf(IN, "%c", &tmp1);
		fscanf(IN, "%c", &tmp2);
		fscanf(IN, "%c", &tmp3);
		fscanf(IN, "%c", &tmp4);
		chislo1 = (int)((tmp1 - '0') * 10 + tmp2 - '0');
		chislo2 = (int)((tmp3 - '0') * 10 + tmp4 - '0');
		if ((chislo1*chislo1 + chislo2*chislo2) % 7 == 1)
			fprintf(OUT, "YES\n");
		else
			fprintf(OUT, "NO\n");

	}
	fclose(IN);
	fclose(OUT);
	return 0;
}