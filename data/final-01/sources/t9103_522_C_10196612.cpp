#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

#define MAX_INT (int)0x7fffffff
#define MIN_INT (int)0x80000000
#define MAX_UINT (uint)0xffffffff

template<class T> inline T SQR(T x) { return x * x; }

#define CONCAT3_NX(x, y, z) x ## y ## z
#define CONCAT3(x, y, z) CONCAT3_NX(x, y, z)
#define VAR(name) CONCAT3(__tmpvar__, name, __LINE__)
#define TYPE(x) __typeof(x)

#define FOR(i, s, n)  for(TYPE(n) VAR(start)=(s),   VAR(end)=(n), i=VAR(start);  i <  VAR(end);  i++)
#define RFOR(i, s, n) for(TYPE(n) VAR(start)=(n)-1, VAR(end)=(s), i=VAR(start);  i >= VAR(end);  i--)
#define FORN(i, n)    FOR(i, 0, n)
#define RFORN(i, n)   RFOR(i, 0, n)

#define SZ(x) ((int)(x).size())
#define POP(stack) (stack).top();(stack).pop();

template<class T> T MIN(T x, T y) { return (x < y) ? x : y; }
template<class T> T MAX(T x, T y) { return (x > y) ? x : y; }
template<class T> void UPDATE_MIN(T &x, T &y) {if (y < x) {x = y;}}
template<class T> void UPDATE_MAX(T &x, T &y) {if (x < y) {x = y;}}

template<class T> inline string TOSTR(const T & x) { stringstream ss; ss << x; return ss.str(); }
#ifndef ONLINE_JUDGE
    #define EPR(args...) if (DEBUG) fprintf (stderr, args)
#else
    #define EPR(args...) 1
#endif
#define DIE(args...) {printf(args);exit(0);}
#define PR(x) cout << (x) << endl
#define PRF(x) cout << setprecision(10) << x << endl

int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
LL gcd(LL a, LL b) { return a ? gcd(b % a, a) : b; }
LL powmod(LL a, LL p, LL m) { LL r = 1; while (p) { if (p & 1) r = r*a%m; p>>=1; a=a*a%m; } return r; }

template <typename K, typename V>
V GetWithDef(const std::unordered_map <K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::unordered_map <K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;

#define DEBUG 0
#define MAXK 100123
#define MAXM 100123

struct Query {
    int cur;
    int vorch;
};

Query qs[MAXM];

int t, m, k;
int arr[MAXK];
int nq_total[MAXK];
int nq[MAXK];

/*

g++ -std=c++11 c.cpp -O3 -o c

*/

void go() {
    int det = 0;
    int unk = 0;
    int cur, vorch;

    LL sum = 0;
    FORN(i, k) {
        nq[i] = 0;
        nq_total[i] = 0;
        sum += arr[i];
    }
    FORN(i, m) {
        Query &q = qs[i];
        nq_total[q.cur]++;
    }

    FORN(i, m) {
        cur = qs[i].cur;
        vorch = qs[i].vorch;
        EPR("query cur %d vorch %d: ", cur, vorch);
        EPR("state det %d unk %d (sum %lld)\n", det, unk, sum);
        if (!det) {
            if (vorch) {
                // case 3
                int minv = 1000 * 1000 * 1000;
                FORN(i, k) {
                    if (nq[i] == nq_total[i])
                        UPDATE_MIN(minv, arr[i]);
                }
                EPR("minv %d\n", minv);
                assert(minv > 0);
                assert(minv < 1000 * 1000 * 1000);
                assert(unk >= minv);

                FORN(i, k) {
                    if (nq_total[i] == nq[i] && unk >= arr[i]) {
                        arr[i] = 0;
                    }
                    else {
                        arr[i] = MAX(nq_total[i] - nq[i], arr[i] - (unk - minv));
                    }
                }
                unk = 0;
                det = 1;
                // will drop to deterministic case for cur
            }
            else if (cur == -1) {
                unk++;
                if (unk > sum - k) {  // we can return YYYY here
                    // case 2
                    FORN(i, k)
                        arr[i] -= unk;
                    unk = 0;
                    det = 1;
                }
                continue;
            }
            else { // know cur, no vorch
                arr[cur]--;
                nq[cur]++;
                sum--;
                if (arr[cur] == 0 || unk > sum - k) {
                    // case 1
                    FORN(i, k)
                        arr[i] -= unk;
                    unk = 0;
                    det = 1;
                }
                continue;
            }
        }
        if (det) {
            if (cur == -1) {
                unk++;
            }
            else {
                arr[cur]--;
            }
        }
    }
    EPR("state det %d unk %d\n", det, unk);
    EPR("answer! %d\n", k);
    FORN(i, k) {
        EPR("arr %d = %d\n", i, arr[i]);
        putchar("NY"[arr[i] - unk <= 0]);
    }
    putchar('\n');
}

int main() {
    ios_base::sync_with_stdio(0);

    // LL sum = (1LL << 32);
    // int d = 1;
    // int k = 10;
    // printf("%d\n", (d > sum - k));
    // return 0;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &k);
        m--;
        // EPR("m k %d %d\n", m, k);
        FORN(i, k)
            scanf("%d", arr + i);
        FORN(i, m) {
            scanf("%d%d", &qs[i].cur, &qs[i].vorch);
            qs[i].cur--;
        }
        go();
    }
    return 0;
}
