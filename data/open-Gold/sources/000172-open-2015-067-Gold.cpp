#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;

int n, k;
LL c, d;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> n >> k >> c >> d;
    scanf("%d%d%lld%lld", &n, &k, &c, &d);

    LL l, r;
    LL ans = 0;
    scanf("%lld%lld", &l, &r);
    ans += (r - l) * d;
    //cout << r << endl;

    vector <LL> v;

    for (int i = 0; i < n - 1; ++i) {
        scanf("%lld", &l);
        v.puba(l - r);
        scanf("%lld", &r);
        ans += (r - l) * d;
        //cout << ans << endl;
    }
     
    sort(bend(v));
    reverse(bend(v));

    for (int i = 0; i < n - 1; i += k) {
        LL nowsum = 0;
        for (int j = 0; j < k && i + j < n - 1; ++j) {
            nowsum += v[i + j];
        }
        if (nowsum > c) {
            ans += c;
        } else {
            ans += nowsum * d;
        }
    }

    cout << ans << endl;


    return 0;
}