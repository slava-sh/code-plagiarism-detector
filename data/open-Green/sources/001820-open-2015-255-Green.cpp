#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define lint long long int
#define inf 199999999999999999

map<pair<lint, int>, lint> m;

lint S(lint x, int k)
{
	if(m[make_pair(x, k)] != 0)
		return m[make_pair(x, k)];
	//if(k > 1 && x == 1)
	//	return inf;
	lint res = inf;
	if(k <= 1)
		return (x / 2 + x % 2);
	lint n = -1;

	lint x0 = x;

	vector<lint> del;
	del.push_back(1);
	bool have = 1;
	while(have)
	{
		have = 0;
		lint sq = sqrt((double)x) + 1;
		sq = min(sq, x);

		have = 0;
		for(lint i = 2; i <= sq; i++)
			if(x % i == 0)
			{
				del.push_back(i);
				x /= i;
				have = 1;
				break;
			}
	}
	x = x0;
	for(int i = 0; i < del.size(); i++)
	{
		lint d0 = del[i];
		res = min(res, (d0 / 2 + d0 % 2) * S(x / d0, k - 1));
	}
	/*
	for(lint i = 1; i <= x; i++)
	{
		if(x % i == 0)
		{
			n = i;
			res = min(res, (i / 2 + i % 2) * S(x / i, k - 1));
			//break;
		}
	}*/
	if(n == -1)
		n = x;
	m[make_pair(x, k)] = res;
	return res;//(n / 2 + n % 2) * S(x / n, k - 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	lint x, k;
	cin >> x >> k;
	cout << S(x, k);

	fclose(stdin);
	fclose(stdout);
	return 0;
}