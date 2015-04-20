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
#define fname "che"
#define ll long long
#define ull unsigned long long
#define f first
#define s second
const ll INF = (ll)1e18 + 123;
const int MAXN = (int)3 * 1e5 + 123;
const double eps = 1e-6;

using namespace std;
ll n,rad,d[MAXN],l,r,mid,ans,id;
int main()
{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin >> n >> rad;
	for (int i = 1;i <= n;i ++)
		cin >> d[i];
	for (int i = 1;i < n;i ++)
	{
		l = i + 1;
		r = n;
		id = -1;
		while(l <= r)
		{
			mid = (l + r)/2;
			if (d[mid] - d[i] > rad)
			{
				id = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		if(id != -1)
		{
			ans += n - id + 1;
		}
	}
	cout << ans;
	return 0;
}