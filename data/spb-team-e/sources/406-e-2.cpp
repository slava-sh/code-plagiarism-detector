#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

__int64 abc(__int64 n)
{
	if (n < 0)
		return -n;
	if (n >= 0)
		return n;
}


int main()
{
	__int64 n, m, l1, r1, r2, l2, P1 = 0, V1 = 0, PV = 0, p, v, i, P, V, k;
	int a[100000];
	FILE *in, *out;
	in = fopen("game.in", "r");
	out = fopen("game.out", "w");
	fscanf(in,"%I64d %I64d", &n, &m);
	fscanf(in,"%I64d %I64d", &l1, &r1);
	fscanf(in,"%I64d %I64d", &l2, &r2);
	for (i = 0; i < n; i++)
	{
		fscanf(in,"%I64d", &a[i]);
		if (a[i] >= l1 && a[i] <= r1 && a[i] >= l2 && a[i] <= r2)
			PV++;
		if (a[i] >= l1 && a[i] <= r1)
			P1++;
		if (a[i] >= l2 && a[i] <= r2)
			V1++;
	}
	P = P1 - PV;
	V = V1 - PV;
	if (m <= PV)
	{
		if (m % 2 == 0)
			fprintf(out,"Draw");
		if (m % 2 != 0)
			fprintf(out,"Petya");
	}
	else
	{
		k = m - PV;
		if (PV % 2 == 0)
		{
			p = abc(P - (k - k / 2));
			v = abc(V - k / 2);
		}
		else
		{
			p = abc(P - k / 2);
			v = abc(V - (k - k / 2));
		}
		if (p < v)
			fprintf(out,"Petya");
		if (p > v)
			fprintf(out,"Vasya");
		if (p == v)
			fprintf(out,"Draw");
	}
	return 0;
}
