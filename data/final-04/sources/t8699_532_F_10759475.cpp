#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll P1 = (ll)1e9 + 7;
const ll P2 = (ll)1e9 + 21;
const ll T = 257;

const int maxN = 200500;

ll pw1[maxN], pw2[maxN];
int n, m;
char s[maxN], t[maxN];
int was[26];
set<int> sett[26];
ll revT1, revT2;

void calcPW() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < maxN; i++) {
        pw1[i] = (pw1[i - 1] * T) % P1;
        pw2[i] = (pw2[i - 1] * T) % P2;
    }
}

ll powmod(ll x, ll n, ll p) {
    x %= p;
    ll res = 1 % p;
    while (n) {
        if ((n & 1)) {
            res = (res * x) % p;
            n--;
        }
        else {
            x = (x * x) % p;
            n >>= 1;
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    calcPW();

    scanf("%d%d", &n, &m);

    scanf("%s%s", s + 1, t + 1);

    for (int i = 1; i <= n; i++)
        s[i] -= 'a';
    for (int j = 1; j <= m; j++)
        t[j] -= 'a';

    revT1 = powmod(T, P1 - 2, P1);
    revT2 = powmod(T, P2 - 2, P2);

    int it = 0;

    ll need1 = 0, need2 = 0;

    for (int i = 1; i <= m; i++) {
        if (was[(int)t[i]] == 0) was[(int)t[i]] = ++it;
        need1 = (need1 + was[(int)t[i]] * pw1[i]) % P1;
        need2 = (need2 + was[(int)t[i]] * pw2[i]) % P2;
    }

    ll cur1[26] = {0}, cur2[26] = {0};

    int r;
    for (r = 1; r <= m; r++) {
        cur1[(int)s[r]] = (cur1[(int)s[r]] + pw1[r]) % P1;
        cur2[(int)s[r]] = (cur2[(int)s[r]] + pw2[r]) % P2;
        sett[(int)s[r]].insert(r);
    }

    vector<int> answer;

    r = m;
    for (int l = 1; l <= n; l++) {
        ll h1 = 0, h2 = 0;
        int go[26];
        memset(go, 255, sizeof(go));
        bool bad = false;
        for (int c = 0; c < 26; c++) {
            if (sett[c].empty()) continue;
            int idx = *sett[c].begin();
            if (go[c] == -1) {
                go[c] = t[idx - (l - 1)];
                if (go[go[c]] == -1) go[go[c]] = c;
                else if (go[go[c]] != c) bad = true;
            }
            else {
                if (go[c] != t[idx - (l - 1)]) {
                    bad = true;
                }
            }
        }
        if (!bad) {
        for (int c = 0; c < 26; c++) {
            if (go[c] == -1) continue;
            h1 = (h1 + cur1[c] * (was[go[c]])) % P1;
            h2 = (h2 + cur2[c] * (was[go[c]])) % P2;
        }
        if (h1 < 0) h1 += P1;
        if (h2 < 0) h2 += P2;
        if ((need1 * pw1[l - 1]) % P1 == h1 && (need2 * pw2[l - 1]) % P2 == h2) answer.push_back(l);
        }
        ++r;
        if (r > n) break;
        cur1[(int)s[l]] = (cur1[(int)s[l]] - pw1[l]) % P1;
        cur2[(int)s[l]] = (cur2[(int)s[l]] - pw2[l]) % P2;
        cur1[(int)s[r]] = (cur1[(int)s[r]] + pw1[r]) % P1;
        cur2[(int)s[r]] = (cur2[(int)s[r]] + pw2[r]) % P2;
        sett[(int)s[r]].insert(r);
        sett[(int)s[l]].erase(l);
    }

    printf("%d\n", (int)answer.size());

    for (int i = 0; i < (int)answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    puts("");

    return 0;
}
