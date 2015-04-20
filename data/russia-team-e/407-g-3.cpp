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


int main()
{
	FILE *in, *out;
	in = freopen("prizes.in", "r", stdin);
	out = freopen("prizes.out", "w", stdout);
//-------------------------------------------------------------------

	long long m, n, ans;

	cin >> n >> m;

	if(n == 1 || m == 1)
	{
		ans = (max(n, m) + 1) / 4;
		cout << ans;
		return 0;
	}

	if(min(n, m) == 2)
	{
		cout << 0;
		return 0;
	}

	cout << 1;
//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
