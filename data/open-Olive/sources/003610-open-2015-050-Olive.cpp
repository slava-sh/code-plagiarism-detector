//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

const int maxN = 6000;
int a[maxN];
int sumpref[maxN][maxN];
int tmp[maxN];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			sumpref[i][a[j]]++;
		}
		for(int j = 1; j <= n; j++)
		{
			sumpref[i][j] += sumpref[i][j - 1];
		}
	}
	int pp = 0;
	int l, r;
	l = -1;
	r = -1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(a[i] > a[j])
			{
				pp++;
			}
		}
	}
	int cur1 = pp;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int cur = cur1;
			int t1 = sumpref[j][a[i]] - sumpref[i][a[i]];
			int t2 = sumpref[j - 1][a[j]] - sumpref[i][a[j]];
			cur -= t1;
			cur += (j - i) - t1;
			cur += t2;
			cur -= (j - i - 1) - t2;
			if(cur < pp)
			{
				pp = cur;
				l = i;
				r = j;
			}
		}
	}
	cout << l << " " << r << endl;
	return 0;
}