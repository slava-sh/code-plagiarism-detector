#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K, C, D;
	cin >> N >> K >> C >> D;
	vector<pair<int, int> > vis(N);
	for (int i = 0; i < N; i++)
		cin >> vis[i].first >> vis[i].second;
	vector<vector<long long> > din(N);
	for (int i = 0; i < N; i++)
	{
		din[i].resize(N + 1);
		for (int q = 0; q < N + 1; q++)
			din[i][q] = 1000000007;
	}
	din[0][1] = (vis[0].second - vis[0].first) * D;
	for (int i = 1; i < N; i++)
	{
		for (int q = 1; q <= i; q++)
		{
			din[i][q + 1] = min((vis[i].second - vis[i].first) * D + din[i - 1][q] + ((q + 1) / K + (q + 1) % K - q / K - q % K) * C, din[i][q + 1]);
			din[i][q] = min((vis[i].second - vis[i].first) * D + din[i - 1][q] + (vis[i].first - vis[i - 1].second) * D, din[i][q]);
		}
	}
	long long ans = 1000000007;
	for (int i = 1; i < N + 1; i++)
	{
		ans = min(din[N - 1][i], ans);
	}
	cout << ans << endl;
	return 0;
}