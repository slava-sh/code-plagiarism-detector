// D.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "conio.h"
#include "algorithm"
#include <vector>

using namespace std;

int main()
{
	long long int a, b;
	int i, j,n,m;

	ifstream cin("dunes.in");
	cin >> n;
	cin >> m;
	long long int* tot = new long long int[m];
	long long int* Vtr0= new long long int[n];
	long long int* Vtr1 = new long long int[n];
	int* Vtr2 = new int[n];
	
	for (i = 0; i < n;i++)
	{
		cin >> Vtr0[i];
		cin >> Vtr1[i];
		cin >> Vtr2[i];
	}
	for (j = 0; j < m; j++)
	{
		cin >> a;
		tot[j] = 0;
		for (i = 0; i < n; i++)
		{
			if ((a >= Vtr0[i]) && (a <= Vtr1[i]))
			{
				if (((a - Vtr0[0]) % 2) == 0)
				{
					tot[j] += Vtr2[i];
				}
				else
				{
					tot[j] -= Vtr2[i];
				}
			}
		}
	}
	cin.close();
	ofstream cout("dunes.out");
	for (j = 0; j < m;j++)
	{
		cout << tot[j]<<endl;
	}
	cout.close();
	//_getch();
	return 0;
}