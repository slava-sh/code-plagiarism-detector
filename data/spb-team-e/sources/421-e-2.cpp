// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	long long int l1, l2, r1, r2, n, m, l;
	cin >> n >> m
		>> l1 >> r1
		>> l2 >> r2;
	long long int p = 0, v = 0, o = 0;
	for (int i = 0; i < n; i++) {
		cin >> l;
		if (((l1 <= l) && (l <= r1)) && ((l2 <= l) && (l <= r2)))	o++;
		else if ((l1 <= l) && (l <= r1))							p++;
		else if ((l2 <= l) && (l <= r2))							v++;
	}


	//cout << p << endl << o << endl << v << endl;


	long long int m1 = m;
	long long int pet = 0, vas = 0;
	for (int i = 0; (m1 > 0); i++)
	{
		if (i % 2 == 0) //petya
		{
			if (o > 0){ o--; pet++; m1--; }
			else if (p > 0){ p--; m1--; pet++; }
		}
		else //vasya
		{
			if (o > 0){ o--; vas++; m1--; }
			else if (v > 0){ v--; m1--; vas++; }
		}
	}

			if (pet == vas) cout << "Draw"; 
	else	if (pet > vas)  cout << "Petya"; 
	else	if (pet < vas)  cout << "Vasya";

	//cin >> n;
	return 0;
}

