
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int sum, n, a, b, x;
	ifstream file; int j = 0;
	x = 0; a = 0; sum = 0;
	file.open("conquest.in", ifstream::in);
	file >> n;
	int kol[1000];
	int cen[1000];
	for (int i = 0; i < n; i++)
	{
		file >> b; kol[i] = b; x = x + b;
		file >> b; cen[i] = b;
	}
	
	file.close();

	
	while( a < x)  
	{
		int old = a;
		
		for (int i = 0; i < n; i++) 
		{
			if (a > kol[i]) {
				a = a + kol[i]; kol[i] = 0;
			}
			
		}
		

		if (a = old)
		{
			int z = 10000; int q = 0;
			for (j = 0; j < n; j++)
			{
				if (z >= cen[j]) { z = cen[j]; q = j; }

			}

			sum = sum + z; kol[q] = kol[q] - 1;
		}
		
	} 
	
	ofstream ofile;
	ofile.open("conquest.out", ofstream::out);
	ofile << sum;
	ofile.close();
}