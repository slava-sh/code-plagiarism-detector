#include <iostream>  
#include <vector>
#include <queue>
#include <fstream>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#define int64 long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define mp make_pair 

using namespace std;

const int N = 3000010;

int n, p, kol[N], calc[N], cum[N], cur[N], k[N];
pair <int, int> a[N];

int main()
{
#ifdef _DEBUG
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
#endif
    scanf("%d%d", &n, &p);
    rep(i,1,n) scanf("%d%d", &a[i].first, &a[i].second);
    rep(i,1,n)
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    memset(kol, 0, sizeof(kol));
    memset(cur, 0, sizeof(cur));
    rep(i,1,n) kol[a[i].first]++;
    rep(i,1,n) kol[a[i].second]++;
    int mx = 0;
    rep(i,1,n) mx = max(mx, kol[i]);
    rep(i,1,n) calc[kol[i]]++;
    cum[mx] = calc[mx];
    repd(i,mx-1,0) cum[i] = cum[i + 1] + calc[i];
    sort(a + 1, a + n + 1);
    int64 ans = 0;
    int last = 1;
    rep(i,1,n)
        if (i == n || (a[i] != a[i + 1]))
        {
            k[a[i].first]++;
            k[a[i].second]++;
            if (kol[a[i].first] + kol[a[i].second] - (i - last + 1) >= p) ans++;
            last = i + 1;
            if (kol[a[i].second] >= p - kol[a[i].first]) cur[a[i].second]++;
            if (kol[a[i].first] >= p - kol[a[i].second]) cur[a[i].first]++;
        }
    int64 res = 0;
    rep(i,1,n)
        if (p - kol[i] <= 0) res += n - 1 - k[i];
        else
        {
            res += cum[p - kol[i]] - cur[i];
            if (kol[i] >= p - kol[i]) res--;
        }
    res /= 2;
    ans += res;
    cout << ans;
    return 0;
}