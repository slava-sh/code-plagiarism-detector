// A.cpp : Defines the entry point for the console application.
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
	long long int t, n, *mas, i;
	ifstream cin("abcd.in");
	ofstream cout("abcd.out");
	cin >> t;
	mas = new long long[t];
	for (i = 0; i < t; i++)
	{
		cin >> n;
		if (((n % 10 + (n % 100 - n % 10)) * (n % 10 + (n % 100 - n % 10)) +    (((n % 1000 - n % 100) / 100) + ((n - (n % 1000)) / 100))    *    (((n % 1000 - n % 100) / 100) + ((n - (n % 1000)) / 100))   )      % 7 == 1)
		{
			cout << "YES" << endl;
		}
		else 
		{
			cout << "NO" << endl;
		}
	}
	cin.close();
	cout.close();
	//_getch();
	return 0;
}