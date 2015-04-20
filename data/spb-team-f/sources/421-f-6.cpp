// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

long long int max(long long int a, long long int b)
{
	if (a > b) return a;
	else return b;
}

long long int min(long long int a, long long int b)
{
	if (a > b) return b;
	else return a;
}

long long int evcl(long long int a, long long int b)
{
	while ((a != 0) && (b != 0))
	{
		a = a % b;
		if (a != 0){
			b = b % a;
		}
	}
	return max(a, b);
}

int main()
{
	freopen("gcm.in", "r", stdin);
	freopen("gcm.out", "w", stdout);

	long long int a, b;
	cin >> a >> b;

	long long int nod = evcl(a, b);

	long long int nok = a * b / nod;

	long long int x = 1;
	long long int y = nok;

	long long int mina = a / nod;
	long long int minb = b / nod;
	long long int min_dif = abs(minb - mina);

	for (long long int x = min(a / nod, b / nod); x < nok; x++)
	{
		if (nok % x == 0){
			if (abs(nok / x - x) < min_dif)
			{
				if (evcl(x, nok / x) == 1)
				{
					mina = x;
					minb = nok / x;
					min_dif = (abs(nok / x - x));
				}
			}
		}
	}
	cout << min(mina, minb) * nod << ' ' << max(mina, minb) * nod;

	return 0;
}

