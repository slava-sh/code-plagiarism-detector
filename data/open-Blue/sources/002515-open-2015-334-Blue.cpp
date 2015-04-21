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

string s, d, x;
int l, res(3), i;

int main() {
    inp("input.txt");
    cin >> l >> s;
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
    cout << "2\na\nb";
}
