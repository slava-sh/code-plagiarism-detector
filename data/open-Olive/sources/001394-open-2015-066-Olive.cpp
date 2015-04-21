#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int> >dp(n + 1, vector<int> (n + 1));
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + (int)(a[i] > j);
        }
    }
    pair<int,pair<int,int> > ans = {0, {-1, -1}};
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int val1 = dp[i - 1][a[i]] + dp[j - 1][a[j]];
            int val2 = dp[i - 1][a[j]] + dp[j - 1][a[i]] + (a[j] > a[i]);
            //printf("%2d ", val1 - val2);
            ans = max(ans, {val1 - val2, {i, j}});
        }
    }
    cout << ans.se.fi << " " << ans.se.se << endl;
    return 0;
}
