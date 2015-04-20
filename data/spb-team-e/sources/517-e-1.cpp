#include <stdio.h>

#define MAX 10001L

typedef struct tagPALKA
{
	long long H;
	int P, V;
} PALKA; 

int main(void)
{
	long N, M, Petya = 0, Vasya = 0, Both = 0, l1, r1, l2, r2;
	long long h, i;
	FILE *in = fopen("game.in", "rt"), *out = fopen("game.out", "wt");
	PALKA Palki[MAX];

	fscanf(in, "%ld %ld", &N, &N);
	fscanf(in, "%ld %ld", &l1, &r1);
	fscanf(in, "%ld %ld", &l2, &r2);

	for (i = 0; i < N; i++)
	{
		fscanf(in, "%I64d", &h);
		Palki[i].H = h;
		if (h >= l1 && h <= r1)
			Palki[i].P = 1;
		else
			Palki[i].P = 0;
		if (h >= l2 && h <= r2)
			Palki[i].V = 1;
		else
			Palki[i].V = 0;
	}

	for (i = 0; i < N; i++)
	{
		if (Palki[i].P == 1)
			if (Palki[i].V == 1)
				Both++;
			else
				Petya++;
		else
			if (Palki[i].V == 1)
				Vasya++;
	}

	if (Both % 2 == 1)
		Petya++;

	if (Petya == Vasya)
	{
		fprintf(out, "Draw\n");
		return 0;
	}
	if (Petya > Vasya)
	{
		fprintf(out, "Petya\n");
		return 0;
	}
	fprintf(out, "Vasya\n");

	return 0;
}