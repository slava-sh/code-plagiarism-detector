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

	if(n == 1)
	{
		ans = (m + 1) / 4;
		
		cout << ans;
		return 0;
	}

	if(m == 1)
	{
		ans = (n + 1) / 4;
		
		cout << ans;
		return 0;
	}

	ans = (min(n, m) + 1) / 4;
	cout << ans;

//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
