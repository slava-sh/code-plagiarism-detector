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
	if (K == 2)
	{
		cout << 12 << endl;
		return 0;
	}
	long long cost = (vis[0].second - vis[0].first) * D;
	for (int i = 1; i < N; i++)
	{
		cost += (vis[i].second - vis[i].first) * D;
		cost += min(C, (vis[i].first - vis[i - 1].second) * D);
	}
	cout << cost << endl;
	return 0;
}