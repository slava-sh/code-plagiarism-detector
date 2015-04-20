#include <stdio.h>

#define MAX 100001L

typedef struct tagPALKA
{
	long long H;
	int P, V;
} PALKI;

static PALKI PALKA[MAX];
static long N, M, Petya = 0, Vasya = 0, Both = 0, l1, r1, l2, r2;
static int PetyaP = 1, VasyaP = 1;

void PetyasTrow()
{
	long i, FirstP = -1;

	if (M <= 0)
		return;

	for (i = 0; i < N; i++)
		if (PALKA[i].P)
		{
		FirstP = i;
			if (PALKA[i].V)
			{
			PALKA[i].P = 0;
			PALKA[i].V = 0;
			Petya++;
			M--;
			return;
			}
		}
	if (FirstP != -1)
	{
		i = FirstP;
		if (PALKA[i].P)
		{
			PALKA[i].P = 0;
			Petya++;
			M--;
			return;
		}
	}
	M--;
	return;
}

void VasyasTrow()
{
	long i, FirstV = -1;

	if (M <= 0)
		return;

	for (i = 0; i < N; i++)
		if (PALKA[i].V)
		{
		FirstV = i;
			if (PALKA[i].P)
			{
			PALKA[i].P = 0;
			PALKA[i].V = 0;
			Vasya++;
			M--;
			return;
			}
		}
	if (FirstV != -1)
	{
		i = FirstV;
		if (PALKA[i].V)
		{
			PALKA[i].V = 0;
			Vasya++;
			M--;
			return;
		}
	}
	M--;
	return;
}

int main(void)
{
	long long h, i;
	FILE *in = fopen("game.in", "rt"), *out = fopen("game.out", "wt");

	fscanf(in, "%ld %ld", &N, &M);
	fscanf(in, "%ld %ld", &l1, &r1);
	fscanf(in, "%ld %ld", &l2, &r2);

	for (i = 0; i < N; i++)
	{
		fscanf(in, "%I64d", &h);
		PALKA[i].H = h;
		if (h >= l1 && h <= r1)
			PALKA[i].P = 1;
		else
			PALKA[i].P = 0;
		if (h >= l2 && h <= r2)
			PALKA[i].V = 1;
		else
			PALKA[i].V = 0;
	}

	while (1)
	{
		if (M <= 0)
			break;
		PetyasTrow();
		if (M <= 0)
			break;
		VasyasTrow();
	}

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