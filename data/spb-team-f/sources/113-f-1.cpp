// Задача F
#include <stdio.h>
#include <math.h>

typedef __int64 SWORD;

SWORD my_abs(SWORD a)
{
	if (a < 0)
		return -a;
	else
		return a;

}

SWORD max(SWORD a, SWORD b)
{
	if (a < b)
		return b;
	else
		return a;
}

SWORD min(SWORD a, SWORD b)
{
	if (a > b)
		return b;
	else
		return a;
}

SWORD NOD(SWORD a, SWORD b)
{
	SWORD i;
	for (i = 2; i <= min(a, b); i++)
	{
		if (((a % i) == 0) && ((b % i) == 0))
			return i * NOD(a / i, b / i);
	}
	return 1;
}

SWORD NOK(SWORD a, SWORD b)
{
	return a * b / NOD(a,b);
}

int main( void )
{
	SWORD a, b;
	SWORD a1, b1;
	SWORD mina = 0, minb = 0;
	FILE *IN, *OUT;
	int firsttime = 1;
	if ((IN = fopen("gcm.in", "rt")) == NULL)
		return 1;
	if ((OUT = fopen("gcm.out", "wt")) == NULL)
	{
		fclose(IN);
		return 1;
	}
	
	fscanf(IN, "%I64d", &a);
	fscanf(IN, "%I64d", &b);

	for (a1 = 1; a1 <= max(a, b); a1++ )
		for (b1 = 1; b1 <= max(a, b); b1++)
			if (NOD(a, b) == NOD(a1, b1) && NOK(a, b) == NOK(a1, b1))
				if ((my_abs(a1 - b1) < my_abs(mina - minb)) || firsttime)
				{
					mina = a1;
					minb = b1;
					firsttime = 0;
				}

	fprintf(OUT, "%I64d %I64d", mina, minb);
	fclose(IN);
	fclose(OUT);
	return 0;
}










