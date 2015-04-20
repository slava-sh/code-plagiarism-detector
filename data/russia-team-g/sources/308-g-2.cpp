#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define eps 1e-9
#define INF 1e+9
#define txt "prizes"

using namespace std;
long long n, m;
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> n >> m;
	if (n > m)
		swap (n, m);
	if (n == 1)
	{
		cout << (m+1)/4;
		return 0;
	}
	if (n > 4)
		cout << 1;
	else
		cout << (n+1)/4;
	return 0;
}