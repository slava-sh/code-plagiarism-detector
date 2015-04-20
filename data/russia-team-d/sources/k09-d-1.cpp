#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#define pb push_back
#define pp pop_back
#define sz size()
#define mp make_pair
#define fname "fence"
#define ll long long
#define ull unsigned long long
#define f first
#define s second
const ll INF = (ll)1e18 + 123;
const int MAXN = (int)1e5 + 123;
const double eps = 1e-6;

using namespace std;
int n,k,a[MAXN],mini = 1000000009,sum,l,r = 1000000000,mid ,ans;
bool check(int x)
{
	int last = a[1];
	if (x > a[1])
		return 0;
	for (int i = 2;i <= n;i ++)
	{
		int p = max(a[i],last + x);
		if (p > k || x > a[i])
			return 0;
		last = p ;
	}	
	return 1;
}
int main()
{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
	{	
		cin >> a[i];
		mini = min(a[i],mini);
		sum += a[i];
	}
	sort(a + 1,a + n + 1);
	if (sum <= k)
	{
		cout << mini;
		return 0;
	}
	l = 1;
	while(l <= r)
	{
		mid = (l + r)/2;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}