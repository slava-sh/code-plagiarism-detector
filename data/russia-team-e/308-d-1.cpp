#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define eps 1e-9
#define INF 1e+9
#define txt "fence"

using namespace std;

int n, a[10500], k;

int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	
	cin >>n >>k;

	for(int i  = 0; i < n; i++)
	{
		cin >>a[i];
	}

	sort(a, a + n);
	int x = min(a[0], (k - a[0]) / (n - 1));
	int s = a[0];
	
	for(int i = 1; i < n; i++)
	{
		int m = a[i] - s;
		if(m <= x)
			m = x;
		else
		{
			if(i < n - 1)
				x = min(a[0], (k - s - m)/(n - i));
		}
		s += m;
	}
	cout <<x;
	return 0;
}