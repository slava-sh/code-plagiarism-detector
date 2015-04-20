#include <iostream>
#include <fstream>
#include "io.h"
#include "stdio.h"

using namespace std;



int max(int a, int b)
{ 
	return ((a > b) ? a : b); 
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

int NOD(int a, int b)
{
	int i;
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

int NOK(int x, int y)
{
	int a = min(x, y);
	int b = max(x, y);
	int i = 0;

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




	


int main()
{
	ifstream fin("gcm.in");
	ofstream fout("gcm.out");


	int x;
	int y;

	int a;
	int b;
	fin >> a >> b;
	bool g = false;


	for (x = 1; x < max(a, b); x++)
	{
		for (y = 1; y < max(a, b); y++)
		{ 
			

			if ((NOD(a, b) == NOD(x, y)) && (NOK(a, b) == NOK(x, y)))
			{
				g = true;
				fout << x << " " << y;
				
				
				fout.close();
				fin.close();
				exit(0);
				

			}
		}
	
	}


	

	fin.close();

	fout.close();
	return 0;

}