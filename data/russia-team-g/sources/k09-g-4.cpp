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
#define fname "prizes"
#define ll long long
#define ull unsigned long long
#define f first
#define s second
const ll INF = (ll)1e18 + 123;
const int MAXN = (int)1e6 + 123;
const double eps = 1e-6;

using namespace std;
ll n,m,ans;
int main()
{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin >> n >> m;
	if (m < n)
		swap(n,m);
	if (n == 2)
	{
		cout << "0";
		return 0;
	}
	if(n <= 2 && m <= 2)
	{	
		cout <<"0";
		return 0;
	}
	if (n == 1)
	{
		m -= 3;
		ans ++;
		ans += (m / 4);
		cout << ans;
		return 0;
	}
	n -= 3;
	ans ++;
	ans += (n / 4);
	cout << ans;
	return 0;
}
