#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define lint long long int
#define inf 199999999999999999

lint S(lint x, int k)
{
	lint res = inf;
	if(k <= 1)
		return (x / 2 + x % 2);
	lint n = -1;


	lint sq = sqrt((double)x) + 1;
	sq = min(sq, x);
	for(lint i = 2; i <= sq; i++)
	{
		if(x % i == 0)
		{
			n = i;
			res = min(res, (i / 2 + i % 2) * S(x / i, k - 1));
			//break;
		}
	}
	if(n == -1)
		n = x;
	return res;//(n / 2 + n % 2) * S(x / n, k - 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, k;
	cin >> x >> k;
	cout << S(x, k);

	fclose(stdin);
	fclose(stdout);
	return 0;
}