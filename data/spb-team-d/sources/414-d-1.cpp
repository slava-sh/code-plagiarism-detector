#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Wind
{
	int Start, End, Ampl;
};

typedef struct Dune
{
	int Num, Height = 0;
};
int main(void)
{
	FILE *in, *out;
	Wind Winds[1000];
	Dune Dunes[1000];
	int n, m;
	if ((in = fopen("dunes.in", "r")) == NULL)
		return -1;
	if ((out = fopen("dunes.out", "w")) == NULL)
		return -1;
	fscanf(in, "%i%i", &n, &m);
	
	for (int i = 0; i < n; i++)
		fscanf(in, "%i %i %i\n", &Winds[i].Start, &Winds[i].End, &Winds[i].Ampl);
	for (int i = 0; i < m; i++)
	{
		fscanf(in, "%i\n", &Dunes[i].Num);
		for (int j = 0; j < n; j++)
			if (Winds[j].Start <= Dunes[i].Num && Winds[j].End >= Dunes[i].Num)
				if (Winds[j].Start % 2 == 0)
					if (Dunes[i].Num % 2 == 0)
						Dunes[i].Height += Winds[j].Ampl;
					else
						Dunes[i].Height -= Winds[j].Ampl;
				else
					if (Dunes[i].Num % 2 == 0)
						Dunes[i].Height -= Winds[j].Ampl;
					else
						Dunes[i].Height += Winds[j].Ampl;
		fprintf(out, "%i\n", Dunes[i].Height);
	}

	fclose(in);
	fclose(out);
	return 0;
}