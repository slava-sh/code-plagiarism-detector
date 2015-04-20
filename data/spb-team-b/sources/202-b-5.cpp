// b2.cpp : Defines the entry point for the console application.
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
	int n, a, i, j;
	ifstream cin("chess.in");
	cin >> n;
	for (i = 1; i < n; i++)
	{
		cin >> a;
		if (a<=i)
		{
			break;
		}
	}
	
	cin.close();
	
	ofstream cout("chess.out");
	cout << i << endl;
	for (j = 1; j <= i; j++)
	{
		cout << j << " " << j << endl;
	}
	cout.close();
	//_getch();
	return 0;
}