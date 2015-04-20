// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);


	int n, m;
	cin >> n >> m;
	long long int l[10001], r[10001], x[10001], h[10001];
	for (long long int i = 0; i < 10001; i++) { l[i] = 0; r[i] = 0; x[i] = 0; h[i] = 0; }
	for (long long int i = 0; i < n; i++) cin >> l[i] >> r[i] >> x[i];

	long long int q[10001];
	for (long long int i = 0; i < m; i++)
	{
		cin >> q[i];
	}

	for (long long int i = 0; i < n; i++)
	{
		for (long long int j = 0; j < m; j++)
		{
			if ((l[i] - 1 <= q[j] - 1) && (q[j] - 1 <= r[i] - 1))
			{
				if (((q[j] - (l[i])) % 2) == 0) h[j] += x[i];
				else h[j] -= x[i];
			}
		}
	}

	for (long long int i = 0; i < m; i++)
	{
		cout << h[i] << endl;
	}

}

