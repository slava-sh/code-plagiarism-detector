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

lol mod1 = 1000000009;
lol mod2 = 1000000007;
lol cf1 = 5;
lol cf2 = 7;
lol hsh1[20100];
lol c1[20100];
lol c2[20100];
lol hsh2[20100];

void calc_hash(string s) {

    c1[1] = c2[1] = 1;
    hsh1[1] = (s[1] - 'a' + 1);
    hsh2[1] = (s[1] - 'a' + 1);
    for(i = 2; i < s.size(); i++) {
        c1[i] = (c1[i - 1] * cf1) % mod1;
        c2[i] = (c2[i - 1] * cf2) % mod2;
        hsh1[i] = (hsh1[i - 1] + (s[i] - 'a' + 1) * c1[i]) % mod1;
        hsh2[i] = (hsh2[i - 1] + (s[i] - 'a' + 1) * c2[i]) % mod2;
    }
}


int main() {
    inp("input.txt");
    int cur;
    cin >> l >> s;
    s = " " + s;
    calc_hash(s);
    for(i = 0; i < s.size(); i++)
//        cout << hsh1[i] << ' ' << hsh2[i] << "\n";
//cout << "FINISH\n";
    for(i = 1; i < min(sz(s), l + 1); i++) {
        d += s[i];
//        cout << "i=" << i << "\n";
        if((sz(s) - 1) % i != 0)
            continue;
        cur = 1;
        while(cur < sz(s) && (hsh1[i] * c1[cur]) % mod1 == (hsh1[cur + i - 1] - hsh1[cur - 1] + mod1) % mod1) {

            cur += i;
//            cout << hsh1[i] << ' ' << c1[cur] << "\n\t";
//            cout << (hsh1[cur + i - 1] - hsh1[cur - 1] + mod1) % mod1 << "\n";
//            cout << "\n" << cur << "\n\n";
        }
        if(cur == sz(s)) {
            cout << "1\n" << d << "\n";
            return 0;
        }
    }


//    d = "";
//    for(i = 0; i < min(sz(s), l); i++) {
//        d += s[i];
//        x = "";
//        while(s.substr(x.size(), d.size()) == d)
//            x += d;
//        dd = "";
//        for(j = x.size(); j < min(sz(s), sz(x) + l); j++) {
//            dd += s[j];
//            xx = x;
//            while(xx.size() < s.size()) {
//                if(sz(xx) + sz(d) <= sz(s) && s.substr(xx.size(), d.size()) == d)
//                    xx += d;
//                else if(sz(xx) + sz(dd) <= sz(s) && s.substr(xx.size(), dd.size()) == dd)
//                    xx += dd;
//                else
//                    break;
//            }
//            if(xx == s) {
//                cout << "2\n" << d << "\n" << dd << "\n";
//                return 0;
//            }
//        }
//    }
    cout << "FINISHED\n2\na\nb";
    return 0;
    cout << "3\na\nb\nc";

}
