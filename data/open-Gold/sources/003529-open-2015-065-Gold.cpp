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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    ll c, d;

    cin >> n >> k >> c >> d;

    vector <vector <ll> > dp(n, vector <ll> (k, inf));
    vector <ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    dp[0][k - 1] = d * (b[0] - a[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + (b[i] - a[i]) * d);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + (b[i] - b[i - 1]) * d);
        }
        dp[i][k - 1] = min(dp[i - 1][k - 1] + (b[i] - b[i - 1]) * d, dp[i - 1][0] + (b[i] - a[i]) * d + c);
    }

    ll ans = inf;
    for (int i = 0; i < k; i++)
        ans = min(ans, dp[n - 1][i]);

    cout << ans << "\n";

}
