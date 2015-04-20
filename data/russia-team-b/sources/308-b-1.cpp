#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define eps 1e-9
#define INF 1e+9
#define txt "che"

using namespace std;
int a[300500];
long long n, r, ans;
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> n >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[j] - a[i] > r)
			{
				ans += n-j;
				break;
			}
	}
	cout << ans;
	return 0;
}