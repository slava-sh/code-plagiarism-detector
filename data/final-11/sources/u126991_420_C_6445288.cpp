#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define LL long long
#define eps 1e-8
#define mod 1000000007
#define mxn 110005
#define mxe 230005
#define MP make_pair

int cnt[300005], x[300005], y[300005], p, n;
int a[300005], sum[300005];
map<pair<int,int>,int> mp;

int main()
{
    cin >> n >> p;
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d%d", x + i, y + i );
        ++cnt[x[i]]; ++cnt[y[i]];
        if(x[i] > y[i]) swap(x[i], y[i]);
        ++mp[MP(x[i],y[i])];
    }
    LL ans = 0;
    for( int i = 1; i <= n; ++i ) ++a[cnt[i]];
    sum[0] = a[0];
    for( int i = 1; i <= n; ++i ) sum[i] = sum[i-1] + a[i];
    for( int i = 1; i <= n; ++i ) {
        if( cnt[i] >= p ) ans += n - 1;
        else {
            int k = p - cnt[i];
            ans += n - sum[k-1];
            if( cnt[i] * 2 >= p ) --ans;
        }
    }
    ans /= 2;
    for( int i = 1; i <= n; ++i ) {
        if( cnt[x[i]] + cnt[y[i]] >= p && cnt[x[i]] + cnt[y[i]] - mp[MP(x[i], y[i])] < p )
            --ans, mp[MP(x[i], y[i])] = 0;
    }
    cout << ans << endl;
    return 0;
}