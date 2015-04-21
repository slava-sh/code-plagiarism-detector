//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

const int maxN = 2e5;

int a[maxN];



int main()
{
	int n;
	cin >> n;
	int cur = 0;
	a[0] = 2e9;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != a[i - 1])
		{
			cur++;
		}
	}
	int Q;
	cin >> Q;
	for(int i = 1; i <= Q; i++)
	{
		int x, y;
		cin >> x >> y;
		int tt = 0;
		if(a[x] != a[x - 1])
		{
			tt++;
		}
		if(a[x] != a[x + 1] && x < n)
		{
			tt++;
		}
		cur -= tt;
		tt = 0;
		a[x] = y;
		if(a[x] != a[x - 1])
		{
			tt++;
		}
		if(a[x] != a[x + 1] && x < n)
		{
			tt++;
		}
		cur += tt;
		cout << cur << "\n";
	}
	return 0;
}