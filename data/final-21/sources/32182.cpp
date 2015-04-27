#include <stdio.h>
#include <iostream>
#include <string.h>

#define mp make_pair

using namespace std;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PUU;

const int prime1 = 31;
const int prime2 = 47;

int n;
char s[200200];
PUU pw[200200], f[200200], b[200200];

void read() {
    scanf("%s", &s);
}

PUU getHashFwd(int le, int ri) {
    if(!le) return f[ri];
    PUU ret;
    ret.first = f[ri].first - f[le - 1].first * pw[ri - le + 1].first;
    ret.second = f[ri].second - f[le - 1].second * pw[ri - le + 1].second;
    return ret;
}

PUU getHashBwd(int le, int ri) {
    if(ri == 2 * n - 1) return b[le];
    PUU ret;
    ret.first = b[le].first - b[ri + 1].first * pw[ri - le + 1].first;
    ret.second = b[le].second - b[ri + 1].second * pw[ri - le + 1].second;
    return ret;
}

void solve() {
    n = strlen(s);
    for(int i = n; i < 2 * n; i ++)
        s[i] = s[i - n];

    f[0] = mp(s[0] - 'a' + 1, s[0] - 'a' + 1);
    for(int i = 1; i < 2 * n; i ++) {
        f[i].first = f[i - 1].first * prime1 + (s[i] - 'a' + 1);
        f[i].second = f[i - 1].second * prime2 + (s[i] - 'a' + 1);
    }

    b[2 * n - 1] = mp(s[2 * n - 1] - 'a' + 1, s[2 * n - 1] - 'a' + 1);
    for(int i = 2 * n - 2; i >= 0; i --) {
        b[i].first = b[i + 1].first * prime1 + (s[i] - 'a' + 1);
        b[i].second = b[i + 1].second * prime2 + (s[i] - 'a' + 1);
    }

    for(int i = 0; i < n; i ++)
        if(getHashFwd(i, i + n - 1) == getHashBwd(i, i + n - 1)) {
            printf("%d\n", i);
            return;
        }

    printf("-1\n");
}

int main()
{
    freopen("inventory.in", "r", stdin);
    freopen("inventory.out", "w", stdout);

    pw[0] = mp(1, 1);
    for(int i = 1; i <= 200000; i ++) {
        pw[i].first = pw[i - 1].first * prime1;
        pw[i].second = pw[i - 1].second * prime2;
    }

    int t;
    scanf("%d", &t);
    for( ; t; t --) {
        read();
        solve();
    }

    return 0;
}
