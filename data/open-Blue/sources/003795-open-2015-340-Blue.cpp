#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l,n,pi[100105],u[100105];
char s[100105],s2[100105],s3[100105];
ll BASE = 7ll, MOD = 1000000007ll, p[100105];
ll suff_hash[100105];

void calc_hash() {
    p[0] = 1ll;
    for (int i = 1; i <= n + 5; ++i) p[i] = (p[i-1] * BASE) % MOD;
    for (int i = n-1; i >= 0; --i) {
        suff_hash[i] = (suff_hash[i+1] * BASE + ll(s[i] - 'a' + 1)) % MOD;
    }
}

ll get_hash(int L, int R) {
    if (L > R) return 0ll;
    return ((suff_hash[L] - suff_hash[R+1] * p[R-L+1]) % MOD + MOD) % MOD;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%s",&l,s);
    n = strlen(s);
    if (l >= n) { printf("1\n"); printf("%s",s); return 0; }
    bool isa = false, isb = false, isc = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') isa = true;
        if (s[i] == 'b') isb = true;
        if (s[i] == 'c') isc = true;
    }
    if (isa && !isb && !isc) { printf("1\n"); printf("a"); return 0; }
    if (!isa && isb && !isc) { printf("1\n"); printf("b"); return 0; }
    if (!isa && !isb && isc) { printf("1\n"); printf("c"); return 0; }

    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    int curlen = n - pi[n-1];
    if (n % curlen == 0 && curlen <= l) {
        strcpy(s2, s);
        s2[curlen] = 0;
        printf("1\n");
        printf("%s",s2);
        return 0;
    }

    if (!isa || !isb || !isc) {
        printf("2\n");
        if (isa) printf("a\n");
        if (isb) printf("b\n");
        if (isc) printf("c\n");
        return 0;
    }

    calc_hash();

    for (int i = 1; i <= n && i <= l; ++i) {
        /// TRY FROM LEAST
        int L = i, R = n-1;
        ll curhash = get_hash(0, i-1);
        while (L <= R) {
            if (R - L + 1 <= i) {
                printf("2\n");
                for (int j = 0; j < i; ++j) printf("%c",s[j]);
                printf("\n");
                for (int j = L; j <= R; ++j) printf("%c",s[j]);
                return 0;
            }
            if (get_hash(L, L+i-1) == curhash) L += i;
            else if (get_hash(R-i+1, R) == curhash) R -= i;
            else break;
        }

        int found = -1;
        for (int j = 1; j + j <= R-L+1 && j <= l; ++j) {
            if (get_hash(L, L+j-1) == get_hash(R-j+1, R)) {
                found = j;
                int prevl = L;
                ll curhash2 = get_hash(L, L+found-1);

                while (L <= R) {
                    if (get_hash(L, L+i-1) == curhash) L += i;
                    else if (get_hash(L, L+found-1) == curhash2) L += found;
                    else if (get_hash(R-i+1, R) == curhash) R -= i;
                    else if (get_hash(R-found+1, R) == curhash2) R -= found;
                    else break;
                }
                if (L > R) {
                    printf("2\n");
                    for (int j = 0; j < i; ++j) printf("%c",s[j]);
                    printf("\n");
                    for (int j = prevl; j <= prevl+found-1; ++j) printf("%c",s[j]);
                    return 0;
                }
            }
        }
    }

    printf("3\na\nb\nc");

    return 0;
}
