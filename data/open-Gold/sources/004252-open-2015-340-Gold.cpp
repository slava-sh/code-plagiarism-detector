#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n,k,c,d;
int a[200105],b[200105];
ll ans = 9e18, sum = 0;
ll gaps[200105];
ll pref_sum[200105];

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d",&n,&k,&c,&d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&a[i],&b[i]);
        sum += ll(b[i] - a[i]) * ll(d);
    }
    for (int i = 1; i < n; ++i)
        gaps[i-1] = a[i+1] - b[i];
    sort(gaps, gaps+n-1);
    reverse(gaps, gaps+n-1);
    pref_sum[0] = gaps[0];
    for (int i = 1; i < n-1; ++i)
        pref_sum[i] = pref_sum[i-1] + gaps[i];

    for (int x = 0; x <= n; ++x) {
        int idx = min(ll(n-1), ll(x+1) * ll(k) - 1ll);
        ans = min(ans, sum + ll(c) * ll(x) - ll(d) * ((idx ? pref_sum[idx-1] : 0ll) - pref_sum[n-2]));
    }
    cout << ans;

    return 0;
}
