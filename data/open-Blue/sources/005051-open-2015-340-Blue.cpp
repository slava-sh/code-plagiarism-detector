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
ll BASE1 = 7ll, MOD1 = 1000000007ll, p1[100105];
ll BASE2 = 11ll, MOD2 = 1000000009ll, p2[100105];
ll suff_hash1[100105];
ll suff_hash2[100105];

void calc_hash() {
    p1[0] = 1ll;
    for (int i = 1; i <= n + 5; ++i) p1[i] = (p1[i-1] * BASE1) % MOD1;
    p2[0] = 1ll;
    for (int i = 1; i <= n + 5; ++i) p2[i] = (p2[i-1] * BASE2) % MOD2;
    for (int i = n-1; i >= 0; --i) {
        suff_hash1[i] = (suff_hash1[i+1] * BASE1 + ll(s[i] - 'a' + 1)) % MOD1;
        suff_hash2[i] = (suff_hash2[i+1] * BASE2 + ll(s[i] - 'a' + 1)) % MOD2;
    }
}

ll get_hash1(int L, int R) {
    if (L > R) return 0ll;
    return ((suff_hash1[L] - suff_hash1[R+1] * p1[R-L+1]) % MOD1 + MOD1) % MOD1;
}

ll get_hash2(int L, int R) {
    if (L > R) return 0ll;
    return ((suff_hash2[L] - suff_hash2[R+1] * p2[R-L+1]) % MOD2 + MOD2) % MOD2;
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
        ll curhash = get_hash1(0, i-1);
        ll curhash_2 = get_hash2(0, i-1);
        while (L <= R) {
            if (R - L + 1 <= l) {
                printf("2\n");
                for (int j = 0; j < i; ++j) printf("%c",s[j]);
                printf("\n");
                for (int j = L; j <= R; ++j) printf("%c",s[j]);
                return 0;
            }
            if (get_hash1(L, L+i-1) == curhash && get_hash2(L, L+i-1) == curhash_2) L += i;
            else if (get_hash1(R-i+1, R) == curhash && get_hash2(R-i+1, R) == curhash_2) R -= i;
            else break;
        }

        for (int j = 1; j + j <= R-L+1 && j <= l; ++j) {
            if (get_hash1(L, L+j-1) == get_hash1(R-j+1, R) && get_hash2(L, L+j-1) == get_hash2(R-j+1, R)) {
                int prevl = L, prevr = R;
                ll curhash2 = get_hash1(L, L+j-1);
                ll curhash2_2 = get_hash2(L, L+j-1);

                while (L <= R) {
                    if (L+j-1 <= R && get_hash1(L, L+j-1) == curhash2 && get_hash2(L, L+j-1) == curhash2_2) L += j;
                    else if (L+i-1 <= R && get_hash1(L, L+i-1) == curhash && get_hash2(L, L+i-1) == curhash_2) L += i;
                    else if (R-j+1 >= L && get_hash1(R-j+1, R) == curhash2 && get_hash2(R-j+1, R) == curhash2_2) R -= j;
                    else if (R-i+1 >= L && get_hash1(R-i+1, R) == curhash && get_hash2(R-i+1, R) == curhash_2) R -= i;
                    else break;
                }
                if (L > R) {
                    printf("2\n");
                    for (int k = 0; k < i; ++k) printf("%c",s[k]);
                    printf("\n");
                    for (int k = prevl; k < prevl+j; ++k) printf("%c",s[k]);
                    return 0;
                }

                L = prevl;
                R = prevr;
            }
        }
    }

    printf("3\na\nb\nc");

    return 0;
}
