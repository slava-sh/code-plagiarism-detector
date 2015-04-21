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

multiset <ll> s;

const int MND = 400;


ll nd[MND];
int ns = 0;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;
	int k;
	cin >> n >> k;
	while ((n % 2 == 0) && (k > 1))
	{
		n /= 2;
		k--;
	}
	while (ns < k) nd[ns++] = 1;
	for (int i = 2; (ll)i * (ll)i <= n; i++)
	{
		while (n % i == 0)
		{
			nd[ns++] = i;
			n /= i;
		}
	}
	nd[ns++] = n;
	for (int i = 0; i < ns - k; i++)
	{
		nd[i + 1] *= nd[i];
		sort(nd + i + 1, nd + ns);
	}
	ll ans = 1;
	for (int i = ns - k; i < ns; i++)
	{
		ans *= (nd[i] + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}