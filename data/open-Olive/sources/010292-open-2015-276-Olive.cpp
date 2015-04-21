#include <bits/stdc++.h>
#define DEBUG false
#define dout if (DEBUG) cout

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

short pref[15007][15007];

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int sval = 0;
    pair<int, int> ans = {-1, -1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j-1] + (v[j] < v[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int d1 = pref[i][i] + pref[j][j];
            int d2 = pref[i][j] + pref[j][i];
            if (d2-d1 > sval) {
                sval = d2-d1;
                ans = {i, j};
            }
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
}

