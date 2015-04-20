#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define pb push_back;
#define rs resize;
#define inf 1e9;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vl;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n;
	ll r;
	cin >> n >> r;
	vl d(n);
	for (int i = 0; i < n; ++i)
		cin >> d[i];
	vi ans(n);
	ans[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		ans[i] = ans[i - 1];
		for (int j = ans[i - 1]; j < i && d[i] - d[j] > r; j++)
			ans[i]++;
	}
	ll s = 0;
	for (int i = 0; i < n; ++i)
		s += (ll)ans[i];
	cout << s;
	return 0;
}