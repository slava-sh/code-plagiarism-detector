#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n, r, t;
vector <string> ans;

pair <int, int> itp(int x) {
    return mp(x / n, x % n);
}

int pti(pair <int, int> x) {
    return x.F * n + x.S;
}

void dfs(int q, string s, vector <int> m) {
    if (q == t) {
        ans.pb(s);
        return;
    }
    for (int i = 0; i < m.size(); ++i) {
        pair <int, int> cur = itp(i);
        if (cur.F + 1 < n && s[pti(mp(cur.F + 1, cur.S))] == '.') {
            s[pti(mp(cur.F + 1, cur.S))] = '*';
            m.pb(pti(mp(cur.F + 1, cur.S)));
            dfs(q + 1, s, m);
            s[pti(mp(cur.F + 1, cur.S))] = '.';
            m.pop_back();
        }
        if (cur.F - 1 >= 0 && s[pti(mp(cur.F - 1, cur.S))] == '.') {
            s[pti(mp(cur.F - 1, cur.S))] = '*';
            m.pb(pti(mp(cur.F - 1, cur.S)));
            dfs(q + 1, s, m);
            s[pti(mp(cur.F - 1, cur.S))] = '.';
            m.pop_back();
        }
        if (cur.S + 1 < r && s[pti(mp(cur.F, cur.S + 1))] == '.') {
            s[pti(mp(cur.F, cur.S + 1))] = '*';
            m.pb(pti(mp(cur.F, cur.S + 1)));
            dfs(q + 1, s, m);
            s[pti(mp(cur.F, cur.S + 1))] = '.';
            m.pop_back();
        }
        if (cur.S - 1 >= 0 && s[pti(mp(cur.F, cur.S - 1))] == '.') {
            s[pti(mp(cur.F, cur.S - 1))] = '*';
            m.pb(pti(mp(cur.F, cur.S - 1)));
            dfs(q + 1, s, m);
            s[pti(mp(cur.F, cur.S - 1))] = '.';
            m.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("virus.in", "r", stdin);
    freopen("virus.out", "w", stdout);
    string s;
    cin >> n >> r >> t;
    for (int i = 0; i < n; ++i) {
        string b;
        cin >> b;
        s += b;
    }
    vector <int> e;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '*')
            e.pb(i);
    dfs(0, s, e);
    int w = 1;
    sort(ans.begin(), ans.end());
    for (int i = 1; i < ans.size(); ++i)
        if (ans[i] != ans[i - 1])
            w++;
    cout << w << endl;
    return 0;
}
