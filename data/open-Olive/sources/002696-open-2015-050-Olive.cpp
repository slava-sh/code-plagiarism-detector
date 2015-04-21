//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

const int maxN = 100;
int a[maxN];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
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
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			swap(a[i], a[j]);
			int cnt = 0;
				for(int i = 1; i <= n; i++)
				{
					for(int j = i + 1; j <= n; j++)
					{
						if(a[i] > a[j])
						{
							cnt++;
						}
					}
				}
				if(cnt < pp)
				{
					pp = cnt;
					l = i;
					r = j;
				}
			swap(a[i], a[j]);
		}
	}
	cout << l << " " << r << endl;
	return 0;
}