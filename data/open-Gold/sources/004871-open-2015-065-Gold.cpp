#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll inf = 1000000000ll * 1000000000ll;

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n, k;
    ll c, d;

    cin >> n >> k >> c >> d;

    vector <ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    if (n == 1) {cout << (b[0] - a[0]) * d << "\n"; return 0;}

    ll ans0 = (b[n - 1] - a[0]) * d;
    ll ans = ans0;
    vector <ll> holes(n - 1);

    for (int i = 0; i < n - 1; i++)
        holes[i] = (a[i + 1] - b[i]) * d;

    sort(all(holes));
    reverse(all(holes));

    vector <ll> sum(n - 1);
    sum[0] = holes[0];

    for (int i = 1; i < n - 1; i++)
        sum[i] = sum[i - 1] + holes[i];

    for (int s = k - 1; s < n - 1; s += k)
    {
        ll x = (s / k) * c;
        if (s > 0) x -= sum[s - 1];
        if (ans > ans0 + x) ans = ans0 + x;
    }

    cout << ans << "\n";

}
