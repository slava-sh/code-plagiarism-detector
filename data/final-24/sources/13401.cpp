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
    int cur, curcur;
    cin >> l >> s;
    s = " " + s;
    calc_hash(s);
//    for(i = 1; i < s.size(); i++)
//        cout << hsh1[i] << ' ' << c1[i] << "\n";
    for(i = 1; i < min(sz(s), l + 1); i++) {
        d += s[i];
        if((sz(s) - 1) % i != 0)
            continue;
        cur = 1;
        while(cur < sz(s) && (hsh1[i] * c1[cur]) % mod1 == (hsh1[cur + i - 1] - hsh1[cur - 1] + mod1) % mod1) {
            cur += i;
        }
        if(cur == sz(s)) {
            cout << "1\n" << d << "\n";
            return 0;
        }
    }

    d = "";
    for(i = 1; i < min(sz(s), l + 1); i++) {
        d += s[i];
        cur = 1;
        while(cur < sz(s) && (hsh1[i] * c1[cur]) % mod1 == (hsh1[cur + i - 1] - hsh1[cur - 1] + mod1) % mod1) {
            cur += i;
        }
        dd = "";
        for(j = cur; j < min(sz(s), cur + l); j++) {

            dd += s[j];
            curcur = cur;
            while(curcur < s.size()) {
                if(curcur + i <= sz(s) && (hsh1[i] * c1[curcur]) % mod1 == (hsh1[curcur + i - 1] - hsh1[curcur - 1] + mod1) % mod1)
                    curcur += i;
                else if(curcur + j - cur + 1 <= sz(s) &&

                        ((hsh1[j] - hsh1[cur - 1] + mod1) % mod1 * c1[curcur]) % mod1 ==
                        ((hsh1[curcur + j - cur] - hsh1[curcur - 1] + mod1) % mod1 * c1[cur]) % mod1)
                    curcur += j - cur + 1;
                else
                    break;
            }
            if(curcur == s.size()) {
                cout << "2\n" << d << "\n" << dd << "\n";
                return 0;
            }
        }
    }
    cout << "3\na\nb\nc";

}
