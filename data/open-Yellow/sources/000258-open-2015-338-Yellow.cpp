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

const int MAXN = 100003;
int a[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int p = -1;
	a[0] = -1, a[n] = -1;
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