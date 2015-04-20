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

	long long int nodab = evcl(a, b);

	long long int nod = evcl(a, b);
	long long int nok = a * b / nod;

	int minim = 100000000000000, minim_a = -1;
	for (int i = 1; i*i < a * b; i++)
	{
		if (((a*b - i*i) % i) == 0)
		{
			int x = (a*b - i*i) / i;
			//cout << i << endl;
			if (x < minim)
			{
				if (evcl(x, a*b / nodab) == nodab)
				{
					minim = x;
					minim_a = i;
				}
			}
		}
	}

	cout << minim_a << ' ' << a*b / minim_a;
	return 0;
}

