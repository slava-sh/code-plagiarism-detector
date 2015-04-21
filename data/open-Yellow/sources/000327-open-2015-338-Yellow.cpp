#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <queue>
#include <sstream>

#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 100010;
int a[MAXN];
const int INF = 1000 * 1000 * 1001;
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	a[0] = -1, a[n + 1] = INF;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != a[i - 1]) ans++;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int p, c;
		cin >> p >> c;
		if (a[p] != a[p - 1]) ans--;
		if (a[p + 1] != a[p]) ans--;
		a[p] = c;
		if (a[p] != a[p - 1]) ans++;
		if (a[p + 1] != a[p]) ans++;
		cout << ans << "\n";
	}
	return 0;
}