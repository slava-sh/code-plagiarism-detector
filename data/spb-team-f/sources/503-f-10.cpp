#include <iostream>
#include <fstream>
#include "io.h"
#include "stdio.h"

using namespace std;



long long max(long long a, long long b)
{ 
	return ((a > b) ? a : b); 
}

long long min(long long a, long long b)
{
	return ((a < b) ? a : b);
}

long long NOD(long long a, long long b)
{
	long long i;
	for (i = min(a, b); i > 0; i--)
	{

		if ((a%i == 0) && (b%i == 0))
		{
			return i;
			break;
		}
	}
	return i;
}

long long NOK(long long x, long long y)
{
	long long a = min(x, y);
	long long b = max(x, y);
	long long i = 0;

	for (i = b; i < a*b + 1; i++)
	{
		if ((i%b == 0) && (i%a == 0))
		{
			return i;
			break; 
		}
	}

	return a*b;
}




	


long long main()
{
	ifstream fin("gcm.in");
	ofstream fout("gcm.out");


	long long x;
	long long y;

	long long a;
	long long b;
	fin >> a >> b;
	


	for (x = 1; x < max(a, b); x++)
	{
		for (y = 1; y < max(a, b); y++)
		{ 
			

			if ((NOD(a, b) == NOD(x, y)) && (NOK(a, b) == NOK(x, y)))
			{
				
				fout << x << " " << y;
				
				
				fout.close();
				fin.close();
				exit(0);
				

			}
		}
	
	}

	fout << a << " " << b;
	

	fin.close();

	fout.close();
	return 0;

}