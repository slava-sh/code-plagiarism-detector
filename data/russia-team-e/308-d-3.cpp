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

long long n, a[10500], k, x, col;

int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	
	cin >> n >> k;
	for(int i  = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if(n == 1)
	{
		cout << min(a[0], k);
		return 0;
	}
	if (k <= a[0])
	{
		cout << 0;
		return 0;
	}
	x = a[0];
	col = a[0];
	for (int i = 1; i < n-1; i++)
	{
		x = min(x, (k-col)/(n-i));
		col += max(x, a[i]-col);
	}
	if (col < x)
		x = a[0];
	cout << x;
	return 0;
}