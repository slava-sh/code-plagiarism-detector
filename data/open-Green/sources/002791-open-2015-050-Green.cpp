//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

const int maxN = 2000;

long long d[11][maxN];
vector <int> del;
int id[2000000];

int main()
{
	long long n, k;
	cin >> n >> k;

	for(long long i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			id[i] = (int)del.size();
			del.push_back(i);
			if(i != n / i)
			{
				id[n / i] = (int)del.size();
				del.push_back(n / i);
			}
		}
	}
	d[k][id[1]] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(n % i == 0)
		{
			d[k][id[i]] = 1e9;
		}
	}
	for(int i = k - 1; i >= 0; i--)
	{
		for(int pp = 0; pp < (int)del.size(); pp++)
		{
			d[i][pp] = 1e9;
			for(int pp1 = 0; pp1 < (int)del.size(); pp1++)
			{
				if(del[pp] % del[pp1] == 0)
				{
					int tt = del[pp1];
					int cnt = (tt + 1) / 2;
					d[i][pp] = min(d[i][pp], cnt * d[i + 1][id[del[pp] / del[pp1]]]);
				}
			}
		}
	}
	cout << d[0][id[n]] << endl;
	return 0;
}