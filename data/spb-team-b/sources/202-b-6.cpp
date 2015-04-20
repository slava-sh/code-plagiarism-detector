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
	long int n,a,i,j, sch=0;
	ifstream cin("chess.in");
	ofstream cout("chess.out");
	cin >> n;
	
	bool table[1000][1000];

	for (j = 0; j < n; j++)
	{
		table[j][j] = false;
	}
	table[0][0] = true;
	for (i = 0; i < n;i++)
	{
		cin >> a;
		for (j = 0; j < a; j++)
		{
			table[i][j] = true;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (table[i][i]) { sch++; }
	}
	cout << sch << endl;

	for (i = 0; i < n; i++)
	{
		if (table[i][i]) { cout << i+1 << " " << i+1; }
		cout << endl;
	}
	
	return 0;
}




/*for (i = 1; i < n;i++)
{
cin >> a;
for (j = 1; j < a; j++)
{
table[i][j] = true;
}
}
cin.close();
i = 0;

while (table[i][i]==true)
{
i++;
}

cout << i << endl;
for (j = 1; j <= i;j++)
{
cout << j << " " << j << endl;
}
cout.close();
//_getch();*/