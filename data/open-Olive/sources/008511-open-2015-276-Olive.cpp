#include <bits/stdc++.h>
#define DEBUG false
#define dout if (DEBUG) cout

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

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
        for (int j = i+1; j <= n; j++) {
            int od = abs(v[i]-i) + abs(v[j]-j);
            int nd = abs(v[i]-j) + abs(v[j]-i);

            //cout << i << ' ' << j << ' ' << od << ' ' << nd << endl;

            if (od-nd > sval) {
                sval = od-nd;
                ans = {i, j};
            }

        }
    }
    cout << ans.first << ' ' << ans.second << endl;

}

