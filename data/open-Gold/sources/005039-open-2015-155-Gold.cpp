#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

int main()
{
	long long n, k, c, d;
	cin >> n >> k >> c >> d;
	vector<pair<int, int> > a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	vector<long long> len;
	for (int i = 1; i < n; ++i)
		len.push_back(a[i].first - a[i - 1].second);
	sort(len.rbegin(), len.rend());
	long long ans = (long long)(a.back().second - a[0].first) * d;
	int i2 = 0;
	int cnt = k - 1;
	while (cnt && i2 < (int)len.size())
	{
		--cnt;
		ans -= len[i2] * d;
		++i2;
	}
	long long bestans = ans;
	while (i2 < (int)len.size())
	{
		ans += c;
		int cnt = k;
		while (cnt && i2 < (int)len.size())
		{
			--cnt;
			ans -= len[i2] * d;
			++i2;
		}
		bestans = min(bestans, ans);
	}
	cout << bestans << endl;
}