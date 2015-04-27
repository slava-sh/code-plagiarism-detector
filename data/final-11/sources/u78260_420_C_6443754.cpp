#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int>   pii;
typedef __int64 ll;
const int N = 300000+5;

int x[N], y[N], cnt[N], sum[N];
map< pii,int >  mp;

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    for(int i = 1;i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        if(x[i] > y[i]) swap(x[i], y[i]);
        mp[pii(x[i], y[i])]++;
        cnt[x[i]]++;
        cnt[y[i]]++;
    }
    int sub = 0;
    for(int i = 1;i <= n; i++) {
        if(mp[pii(x[i], y[i])]) {
            int tot = cnt[x[i]] + cnt[y[i]] - mp[pii(x[i],y[i])];
            if(tot < p && cnt[x[i]] + cnt[y[i]] >= p)   sub ++;
            mp[pii(x[i], y[i])] = 0;
        }
    }
    for(int i = 1;i <= n; i++)  sum[cnt[i]]++;
    for(int i = 1;i <= n; i++)  sum[i] += sum[i-1];
    ll ans = 0;
    for(int i = 1;i <= n; i++) {
        int cur = cnt[i];
        if(cnt[i] >= p) ans += sum[n];
        else    ans += sum[n] - sum[p-cnt[i]-1];
        if(cnt[i]*2 >= p)   ans --;
    }
    printf("%I64d\n", ans/2-sub);
    return 0;
}
