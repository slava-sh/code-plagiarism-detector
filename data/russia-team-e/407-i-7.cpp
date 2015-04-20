#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>

using namespace std;

int a[110000];

int main()
{
	FILE *in, *out;
	in = freopen("sochi.in", "r", stdin);
	out = freopen("sochi.out", "w", stdout);
//-------------------------------------------------------------------
	
	int n, d, i, k = 0;
	long long res = 0;

	cin >> n >> d;

	for(i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	i = n - 1;
	while(i >= 0 && a[i] >= 3 * d)
	{
		k++;
		res += a[i];
		i--;
	}

	if(i >= 0 && a[i] >= 2 * d)
	{
		res += a[i];
		k++;
		i--;
	}

	if(i >= 0 && a[i] >= 2 * d)
	{
		res += a[i];
		k++;
		i--;
	}

	if(res == 0)
	{
		cout << a[n - 1];
		return 0;
	}

	cout << res - 2 * (k - 1) * d;

//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
