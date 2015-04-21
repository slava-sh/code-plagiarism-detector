#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

#define int unsigned long long int

using namespace std;

main()
{
	ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");

	int n, k, c, d;
	cin >> n >> k >> c >> d;
	
	int answer = 1000ULL * 1000 * 1000 * 1000 * 1000 * 1000;

	vector<pair<int, int> > A(n);

	for (int i = 0; i < n; ++i)
		cin >> A[i].first >> A[i].second;

	vector<vector<int> > DP(n + 1, vector<int>(k + 1, 1000ULL * 1000 * 1000 * 1000 * 1000 * 1000));
	DP[0][1] = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < k + 1; ++j)
		{
			DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + d * (A[i + 1].first - A[i].second));
			if (j < k)
				DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j]);
			else
				DP[i + 1][1] = min(DP[i + 1][1], DP[i][j] + c);
		}
	}

	for (int i = 1; i < k + 1; ++i)
		answer = min(answer, DP[n - 1][i]);

	for (int i = 0; i < n; ++i)
		answer += (A[i].second - A[i].first) * d;

	cout << answer << endl;

	// vector<int> F(n - 1);
	// for (int i = 1; i < n; ++i)
	// 	F[i - 1] = A[i].first - A[i - 1].second;

	// sort(F.begin(), F.end());
	// reverse(F.begin(), F.end());

	// if (k == 1)
	// {
	// 	for (int i = 0; i < n - 1; ++i)
	// 		answer += min(c, d * F[i]);
	// 	cout << answer << endl;
	// }
	// else
	// {
	// 	int current = 0;
	// 	for (int i = 0; i < n - 1; ++i)
	// 	{
	// 		current += F[i];
	// 		if ((i + 1) % (k - 1) == 0)
	// 		{
	// 			answer += min(c, current * d);
	// 			current = 0;
	// 		}
	// 	}
	// 	cout << answer << endl;
	// }
}