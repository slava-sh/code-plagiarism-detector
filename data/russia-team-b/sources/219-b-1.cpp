#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <functional>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define SS stringstream
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> > 
#define FIN freopen("1.in", "r", stdin)
#define FOUT freopen("1.out", "w", stdout)
#define FILE FIN; FOUT
#define SRD srand((int)time(NULL))
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) (1ll*(x)*(x))
#define pw(x) (1ll<<(x))
#define SC(x) scanf("%d", &x)
#define CC(x) cout << x << endl
#define forr(i, l, r) for(int i = l; i <= r; i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;

using namespace std;

#define N 333333

int n, a[N], d;

int main()
{
	//ios_base::sync_with_stdin(false);
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	SC(n); SC(d);
	forr(i, 1, n) SC(a[i]);
	sort(a+1, a+n+1);
	int r = 1;
	LL ans = 0;
	forr(l, 1, n)
	{
		if (l > r) r = l;
		while (r <= n && a[r]-a[l] <= d) r++;
		if (r <= n) ans += n-r+1;
	}
	CC(ans);
	return 0;
}