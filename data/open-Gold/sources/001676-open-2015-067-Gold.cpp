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
    bool flag = false;
    int up = k - 1;
    bool flag2 = false;

    for (int i = 0; i < n - 1; i += up) {
        if (flag) {
            up = k;
        }
        flag = true;
        //cout << i << endl;
        LL nowsum = 0;
        for (int j = 0; j < up && i + j < n - 1; ++j) {
            nowsum += v[i + j];
        }
        if (nowsum * d > c && (!flag2 || k == 1)) {
            ans += c;
        } else {
            ans += nowsum * d;
            flag2 = true;
        }                
    }

    cout << ans << endl;


    return 0;
}