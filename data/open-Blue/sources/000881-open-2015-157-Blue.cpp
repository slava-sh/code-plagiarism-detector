#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int INF = 1234657890;
const int pw = 31;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k;
    scanf("%d", &k);

    string s;
    cin >> s;

    int n = (int)s.length();

    vector<int> p(n, -1);
    vector<pair<int, set<int> > > dp(n, mp(INF, set<int>()));
    for (int i = 0; i < n; i++) {
        int curhash = 0, curp = 1;
        set<int> curset;
        if (i > 0) curset = dp[i - 1].se;
        for (int j = i; j < min(i + k, n); j++, curp *= pw) {
            curhash += s[j] * curp;
            curset.insert(curhash);
            if (curset.size() < dp[j].fi) {
                dp[j] = mp(curset.size(), curset);
                p[j] = i - 1;
            }
        }
    }

    vector<int> pos;
    for (int i = p[n - 1]; p[i] != i && i != -1; i = p[i]) {
        pos.push_back(i + 1);
    }

    unordered_set<string> ans;
    for (int i = (int)pos.size() - 1; i >= 0; i--) {
        string t = "";
        if (i == (int)pos.size() - 1) {
            for (int j = 0; j < pos[i]; j++) {
                t += s[j];
            }
        } else {
            for (int j = pos[i + 1]; j < pos[i]; j++) {
                t += s[j];
            }
        }
        ans.insert(t);
    }

    printf("%d\n", (int)ans.size());
    for (auto x: ans) {
        cout << x << endl;
    }
}
