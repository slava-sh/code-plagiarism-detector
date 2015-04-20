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

#define N 222222

int n, k, a[N];

	inline bool f(int x)
	{
		LL ans = 0;
		forr(i, 1, n-1) ans = max(ans+x, 1ll*a[i]);
		if (ans+x <= k) return true;
		return false;
	}

int main()
{
	//ios_base::sync_with_stdin(false);
	//FIN;
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	SC(n); SC(k);
	forr(i, 1, n) SC(a[i]);
	sort(a+1, a+n+1);
	int l = -1, r = a[1]+1;
	while (l+1 < r)
	{
		int m = (l+r)/2;
		if (f(m)) l = m; else r = m;
	}
	if (f(l)) CC(l); else CC(r);
	return 0;
}