#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n, r, t;
set <vector <int> > ans;

pair <int, int> itp(int x) {
    return mp(x / n, x % n);
}

int pti(pair <int, int> x) {
    return x.F * n + x.S;
}

void dfs(int q, string s, vector <int> m) {
    sort(m.begin(), m.end());
    if (ans.find(m) != ans.end())
        return;
    /*for (int i = 0; i < n; ++i) {
            for (int j = 0; j < r; ++j)
                cout << s[pti(mp(i, j))];
            cout << endl;
        }
        for (int i = 0; i < m.size(); ++i)
            cout << m[i] << " ";
        cout << endl << endl;*/
    if (q == t) {
        ans.insert(m);
        /*for (int i = 0; i < n; ++i) {
            for (int j = 0; j < r; ++j)
                cout << s[pti(mp(i, j))];
            cout << endl;
        }
        for (int i = 0; i < m.size(); ++i)
            cout << m[i] << " ";
        cout << endl << endl;*/
        return;
    }
    for (int i = 0; i < m.size(); ++i) {
        pair <int, int> cur = itp(m[i]);
        if (cur.F + 1 < n && s[pti(mp(cur.F + 1, cur.S))] == '.') {
            s[pti(mp(cur.F + 1, cur.S))] = '*';
            vector <int> m1 = m;
            m1.pb(pti(mp(cur.F + 1, cur.S)));
            dfs(q + 1, s, m1);
            s[pti(mp(cur.F + 1, cur.S))] = '.';
        }
        if (cur.F - 1 >= 0 && s[pti(mp(cur.F - 1, cur.S))] == '.') {
            s[pti(mp(cur.F - 1, cur.S))] = '*';
            vector <int> m1 = m;
            m1.pb(pti(mp(cur.F - 1, cur.S)));
            dfs(q + 1, s, m1);
            s[pti(mp(cur.F - 1, cur.S))] = '.';
        }
        if (cur.S + 1 < r && s[pti(mp(cur.F, cur.S + 1))] == '.') {
            s[pti(mp(cur.F, cur.S + 1))] = '*';
            vector <int> m1 = m;
            m1.pb(pti(mp(cur.F, cur.S + 1)));
            dfs(q + 1, s, m1);
            s[pti(mp(cur.F, cur.S + 1))] = '.';
        }
        if (cur.S - 1 >= 0 && s[pti(mp(cur.F, cur.S - 1))] == '.') {
            s[pti(mp(cur.F, cur.S - 1))] = '*';
            vector <int> m1 = m;
            m1.pb(pti(mp(cur.F, cur.S - 1)));
            dfs(q + 1, s, m1);
            s[pti(mp(cur.F, cur.S - 1))] = '.';
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
    if (ans.empty())
        cout << 1;
    else
        cout << ans.size();
    cout << endl;
    return 0;
}
