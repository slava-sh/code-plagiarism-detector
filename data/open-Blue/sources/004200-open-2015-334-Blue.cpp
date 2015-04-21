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

string s, d, x, dd, xx;
int l, res(3), i, j;

int main() {
    inp("input.txt");
    cin >> l >> s;
    char c;
    for(i = 0; i < min(sz(s), l); i++) {
        d += s[i];
        x = "";
        while(sz(s) % sz(d) == 0 && x.size() < s.size()) {
            x += d;
        }
        if(x == s) {
            cout << "1\n" << d;
            return 0;
        }
    }
    d = "";
    for(i = 0; i < min(sz(s), l); i++) {
        d += s[i];
        x = "";
        while(s.substr(x.size(), d.size()) == d)
            x += d;
        dd = "";
        for(j = x.size(); j < min(sz(s), sz(x) + l); j++) {
            dd += s[j];
            xx = x;
            while(xx.size() < s.size()) {
                if(sz(xx) + sz(d) <= sz(s) && s.substr(xx.size(), d.size()) == d)
                    xx += d;
                else if(sz(xx) + sz(dd) <= sz(s) && s.substr(xx.size(), dd.size()) == dd)
                    xx += dd;
                else
                    break;
            }
            if(xx == s) {
                cout << "2\n" << d << "\n" << dd << "\n";
                return 0;
            }
        }
    }

    cout << "3\na\nb\nc";

}
