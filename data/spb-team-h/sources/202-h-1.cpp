//#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "conio.h"
#include "algorithm"
#include <vector>
#include "string"

using namespace std;
/*bool smp(string a, string b)
{
	return 
}*/

int main()
{
	string mas1[1000], mas2[1000], mas3[1000], masg[1000];
	bool bl[1000];
	int n, i, j;
	for (i = 0; i < 1000;i++)
	{
		bl[i] = false;
	}
	
	ifstream cin("names.in");
	ofstream cout("names.out");
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> mas1[i] >> mas2[i] >> mas3[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (bl[j] == false)
			{
				if (mas2[i] == mas2[j])
				{
					bl[i] = true;
					bl[j] = true;
				}
				if (mas2[i] == mas1[j])
				{
					bl[i] = true;
					bl[j] = true;
					swap(mas1[j], mas3[j]);
					swap(mas2[j], mas3[j]);

				}
			}
		}
		if (bl[i] == false)
		{
			swap(mas1[i], mas3[i]);
			swap(mas2[i], mas3[i]);
			i--;
		}
	}

	for (i = 0; i < n;i++)
	{
		masg[i] = mas1[i] + " " + mas2[i] + " " + mas3[i];
	}

	sort(masg, masg + n);
	for (i = 0; i < n;i++)
	{
		cout << masg[i] << endl;
	}

	cin.close();
	cout.close();
	//_getch();
	return 0;
}