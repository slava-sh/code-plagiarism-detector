#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
	int t = 0;
	int abcd, ab, cd;
	FILE *Fin;
	FILE *Fout;
	Fin = fopen("", "r");
	Fout = fopen("", "w");
	fscanf(Fin, "%i", &t)
	while (t != 0)
	{
		fscanf(Fin, "%i", &abcd)
	    cd = abcd % 100;
		ab = (abcd - cd) / 100;
		if (((ab ^ 2) + (bc ^ 2)) % 7 == 1)
			fprintf(Fout, "YES");
		else
			fprintf(Fout, "NO");
		t--;
	}
	fclose(Fin);
	fclose(Fout)
	return 0;
}