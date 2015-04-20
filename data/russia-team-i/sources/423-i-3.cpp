#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

const int N = 100000;

int ropes[N];

bool my_greater(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);

	int n, d;
	cin >> n >> d;

	int ans = 0, k = 0;

	int m1 = -1, m2 = -1;

	for ( int i = 0; i < n; ++i )
		cin >> ropes[i];

	sort(ropes, ropes + n, my_greater);

	ans = ropes[0];

	for ( int i = 1; i < n; ++i )
	{
		if ( ropes[i] >= 3 * d )
		{
			ans += ropes[i] - 2 * d;
		}
		else if ( ropes[i] > d )
		{
			if ( ropes[i] > m1 )
			{
				m2 = m1;
				m1 = ropes[i];
			}
			else
			{
				m2 = max(m2, ropes[i]);
			}
		}
	}

	if ( m1 != -1 )
		ans += m1 - 2 * d;

	if ( m2 != -1 )
		ans += m2 - 2 * d;

	cout << ans << '\n';

	return 0;
}