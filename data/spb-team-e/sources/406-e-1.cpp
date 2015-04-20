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
	//FILE *in, *out;
	//in = fopen("game.in", "r");
	//out = fopen("game.out", "w");
	scanf("%I64d %I64d", &n, &m);
	scanf("%I64d %I64d", &l1, &r1);
	scanf("%I64d %I64d", &l2, &r2);
	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
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
			printf("Draw");
		if (m % 2 != 0)
			printf("Petya");
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
			printf("Petya");
		if (p > v)
			printf("Vasya");
		if (p == v)
			printf("Draw");
	}
	return 0;
}
