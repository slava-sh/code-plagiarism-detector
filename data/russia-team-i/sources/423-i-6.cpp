#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

const int N = 100000;

long long ropes[N];

bool my_greater(long long a, long long b)
{
	return a > b;
}

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);

	long long n, d;
	cin >> n >> d;

	long long ans;

	for ( int i = 0; i < n; ++i )
		cin >> ropes[i];

	sort(ropes, ropes + n, my_greater);

	ans = ropes[0];

	int i = 1;

	while ( i < n && ropes[i] >= 3 * d )
	{
		ans += ropes[i] - 2 * d;
		++i;
	}

	if ( ropes[0] < 3 * d )
	{
		if ( n > 1 )
		{
			if ( ropes[1] > 2 * d )
				cout << ropes[0] + ropes[1] - 2 * d;
			else
				cout << ropes[0];

			return 0;
		}
	}

	if ( i < n && ropes[i] > 2 * d )
	{
		ans += ropes[i] - 2 * d;
		++i;
	}

	if ( i < n && ropes[i] > 2 * d )
	{
		ans += ropes[i] - 2 * d;
		++i;
	}

	cout << ans << '\n';

	return 0;
}