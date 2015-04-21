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

#define int long long int

using namespace std;

main()
{
	ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");

	int n, k, c, d;
	cin >> n >> k >> c >> d;
	
	int answer = 0;
	vector<pair<int, int> > A(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> A[i].first >> A[i].second;
		answer += (A[i].second - A[i].first) * d;
	}

	vector<int> F(n - 1);
	for (int i = 1; i < n; ++i)
		F[i - 1] = A[i].first - A[i - 1].second;

	sort(F.begin(), F.end());
	reverse(F.begin(), F.end());

	int current = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		current += F[i];
		if ((i + 1) % k == 0)
		{
			answer += min(c, current * d);
			current = 0;
		}
	}
	cout << answer << endl;
}