#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int n, d, x;
long long ans;
vector < int > a;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	cin >> n >> d;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (x >= 3 * d)
			ans += x, ++cnt;
		else
			a.push_back(x);
	}
	if (cnt > 0)
		ans -= 2 * d * (cnt - 1);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	if (a.size() > 0 && a[0] >= 2 * d && a[0] < 3 * d)
		ans += a[0] - 2 * d * (cnt ? 1 : 0), ++cnt;
	if (a.size() > 1 && a[1] >= 2 * d && a[1] < 3 * d)
		ans += a[1] - 2 * d * (cnt ? 1 : 0), ++cnt;
	if (cnt == 0 && a.size() > 0)
		ans = a[0];
	cout << ans << endl;
}