#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll res, ans;
int l[200500], r[200500];
int d[200500], sz;

int main()
{
    sz = 0;
    int n, k, C, D;
    ll sum = 0;
    scanf("%d%d%d%d", &n, &k, &C, &D);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &l[i], &r[i]);
        sum += (r[i]-l[i]);
    }
    int need = (n+k-1)/k;
    need = max(0, need-1);
    ans = sum * 1LL * D + need * 1LL * C;
    for(int i = 1; i <= n-1; ++i){
        d[sz++] = l[i+1] - r[i];
    }
    sort(d, d + sz);
    for(int i = 0; i < sz; ++i){
        sum += 1LL * d[i];
        n--;
        need = (n+k-1)/k;
        need = max(0, need-1);
        res = sum * 1LL * D + need * 1LL * C;
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}
