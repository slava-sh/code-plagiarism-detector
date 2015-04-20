// B.cpp : Defines the entry point for the console application.
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
	int n,a,i,j;
	ifstream cin("chess.in");
	cin >> n;
	cin >> a;
	int** table = new int*[a];
	for (i = 0; i < a; i++)
	{
		table[i] = new int[a];
		
	}

	for (j = 0; j < a; j++)
	{
		table[j][j] = 0;
	}
	table[0][0] = 1;

	for (i = 1; i < n;i++)
	{
		cin >> a;
		for (j = 1; j < a; j++)
		{
			table[i][j] = 1;
		}
	}
	cin.close();
	i = 0;

	while (table[i][i]==1)
	{
		i++;
	}
	ofstream cout("chess.out");
	cout << i << endl;
	for (j = 1; j <= i;j++)
	{
		cout << j << " " << j << endl;
	}
	cout.close();
	//_getch();
	return 0;
}