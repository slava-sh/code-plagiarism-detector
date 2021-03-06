#include <stdio.h>
#include <math.h>

typedef __int64  SWORD;
int cmp(SWORD vas, SWORD pet)
{
	if (vas > pet)
		return -1;
	if (vas < pet)
		return 1;
	return 0;
}

/*int WhoWon(SWORD vas, SWORD pet, SWORD m)
{
	
	if ((vas + pet) <= m)
		cmp(pet,vas)
	else
		if (pet < m / 2)
			return 1;
	    if (vas < m / 2)
		   return -1;	
	
	

}*/

int main(void)
{
	SWORD n, m;
	SWORD l1, l2, r1, r2;
	int i;
	int ind = 1;
	int win;
	SWORD pet = 0, vas = 0;
	FILE *IN, *OUT;

	SWORD pet1 = 0 , vas1 = 0;
	if ((IN = fopen("game.in", "rt")) == NULL)
		return 1;
	if ((OUT = fopen("game.out", "wt")) == NULL)
	{
		fclose(IN);
		return 1;
	}
	
	fscanf(IN, "%I64d", &n);
	fscanf(IN, "%I64d", &m);
	fscanf(IN, "%I64d", &l1);
	fscanf(IN, "%I64d", &r1);
	fscanf(IN, "%I64d", &l2);
	fscanf(IN, "%I64d", &r2);
	for (i = 1; i <= n; i++)
	{
		SWORD ls;
		fscanf(IN, "%I64d", &ls);
		if (l1 <= ls && r1 >= ls && l2 <= ls && r2 >= ls && (pet + vas) < m)
		{
			if (ind == 1)
				pet++;
			else
				vas++;
			ind = 0 - ind;
		}
		if (l1 <= ls && r1 >= ls && (l2 > ls || r2 < ls))
		{
			pet1++;
		}
		if (l2 <= ls && r2 >= ls && (l1 > ls || r1 < ls))
		{
			vas1++;
		}
	}
	while ((pet + vas) < m)
	{
		if (pet1)
			pet1--, pet++;
		if (vas1 && (pet + vas) < m)
			vas1--, vas++;

	}
	win = cmp(vas, pet);
	if (win == 1)
		fprintf(OUT, "Petya");
	if (win == 0)
		fprintf(OUT, "Draw");
	if (win == -1)
		fprintf(OUT, "Vasya");
	fclose(IN);
	fclose(OUT);
	return 0;
}

