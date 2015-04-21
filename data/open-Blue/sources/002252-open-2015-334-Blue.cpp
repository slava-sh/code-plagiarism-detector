#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

string s;
int l, res(1000000000);
multiset<string> d;

void rec(int cur, int ans) {
//    if(ans > res)
//        return;
//    cout << cur << ' ' << s.size() << "\n\t";
//    cout << ans << "\n";
    if(cur >= s.size()) {
        res = min(res, ans);
        return;
    }
    string q;
    for(int i = cur; i < min(cur + l, sz(s)); i++) {
//        cout << cur << ' ' << i << "\n\t";
//        cout << q << "\n";
        q += s[i];
        if(d.find(q) == d.end())
            ans++;
        d.insert(q);
        rec(i + 1, ans);
        d.erase(d.find(q));
        if(d.find(q) == d.end())
            ans--;

    }
}

int main() {
    inp("input.txt");
    cin >> l >> s;
    rec(0, 0);
    cout << res;
}
