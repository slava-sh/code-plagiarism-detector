//#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "conio.h"
#include "algorithm"
#include <vector>

using namespace std;
unsigned long long int NoD(unsigned long long int a, unsigned long long int b)
{
	unsigned long long c, d;
	c = a;
	d = b;
	while (d&&c)
	{
		if (c>d)
		{
			swap(c, d);
		}
		d = d%c;
	}
	return c + d;
}

int main()
{
	unsigned long long int a, b,c,i,z;
	ifstream cin("gcm.in");
	cin >> a;
	cin >> b;
	cin.close();
	c = NoD(a, b);
	a = a*b;
	for (i = 1; i <=ceil(sqrt(a));i++)
	{
		if (a%i==0)
		{
			if ((NoD(i, a / i) == c))
			{
				z = i;
			}
		}
	}

	ofstream cout("gcm.out");
	if (z>a/z)
	{
		z = a / z;
	}
	cout <<z << " " << a/z;
	cout.close();
	//_getch();
	return 0;
}