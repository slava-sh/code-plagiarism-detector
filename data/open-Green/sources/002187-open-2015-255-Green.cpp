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

lint Sold(lint x, int k)
{
	lint res = inf;
	if(k <= 1)
		return (x / 2 + x % 2);
	
	for(lint i = 1; i <= x; i++)
	{
		if(x % i == 0)
		{
			res = min(res, (i / 2 + i % 2) * Sold(x / i, k - 1));
			//break;
		}
	}
	return res;//(n / 2 + n % 2) * S(x / n, k - 1);
}

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
	/*
	map<lint, int> del;
	del[1]++;
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
				del[i]++;
				x /= i;
				have = 1;
				break;
			}
	}
	if(x != 1)
		del[x]++;
	x = x0;
	for(map<lint, int>::iterator it = del.begin(); it != del.end(); it++)
	{
		lint c = it->first;
		lint p = it->second;
		lint d0 = c;
		for(int j = 1; j <= p; j++)
		{
			res = min(res, (d0 / 2 + d0 % 2) * S(x / d0, k - 1));
			d0 *= c;
		}
		
	}*/
	lint sq = sqrt((double)x) + 1;
		sq = min(sq, x);
	for(lint i = 1; i <= sq; i++)
	{
		if(x % i == 0)
		{
			n = i;
			res = min(res, (i / 2 + i % 2) * S(x / i, k - 1));
			//break;
		}
	}
	res = min(res, (x / 2 + x % 2) * S(1, k - 1));
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
	/*
	for(lint i = 100; i <= 10000; i++)
		for(int j = 3; j <= 3; j++)
		{
			lint a = Sold(i, j);
			lint b = S(i, j);
			if(a != b)
			cout << i << " " << j << " " << Sold(i, j) << " " << S(i, j) << endl;
		}*/

	fclose(stdin);
	fclose(stdout);
	return 0;
}