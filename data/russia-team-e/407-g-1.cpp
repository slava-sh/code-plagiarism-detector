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

	if(n == 1 && m == 1)
	{
		cout << 0;
		return 0;
	}

	if(n == 1)
	{
		if(m > 2)
		{
			ans = (m - 3) / 4 + 1;
		}
		else
			ans = (m - 3) / 4;
		
		cout << ans;
		return 0;
	}

	if(m == 1)
	{
		if(n > 2)
		{
			ans = (n - 3) / 4 + 1;
		}
		else
			ans = (n - 3) / 4;
		
		cout << ans;
		return 0;
	}

	if(min(n, m) > 2)
		ans = (min(n, m) - 3) / 4 + 1;
	else
		ans = (min(n, m) - 3) / 4;

	cout << ans;

//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
