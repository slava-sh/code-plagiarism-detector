#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <limits>
#include <bitset>
#include <chrono>

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef chrono::high_resolution_clock hclock;

bool hadDebugEnv = false;
bool isDebugEnv = false;
bool isDebug() {if(!hadDebugEnv){hadDebugEnv=true;isDebugEnv=(getenv("SWATMAD_CF_DEBUG")!=NULL);}return isDebugEnv;}

hclock::time_point timeStart;

#define debug(s) if (isDebug()) { cerr << s << endl; }
#define print(s) cout << s << endl;
#define cdebug(s) if (isDebug()) { s; }
#define starttime() cdebug(timeStart = hclock::now())
#define checktime() debug("Time check: " << double(chrono::duration_cast<chrono::milliseconds>(hclock::now() - timeStart).count()) / 1000)
#define all(v) (v).begin(), (v).end()
#define rfor(x, a) for (const auto& x : a)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornb(i, b, n) for (int i = (int)(b); i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fordb(i, n, b) for (int i = (int)(n) - 1; i >= b; --i)
#define rvar(x) cin >> x;
#define rvec(x, a) for (auto& x : a) cin >> x;
#define vec2d(type, n, m, v) vector<vector<type>>(n, vector<type>(m, v))
#define setbit(x, b) x |= (1 << b)
#define setbit0(x) setbit(x, 0)
#define clbit(x, b) x &= ~(1 << b)
#define clbit0(x) clearbit(x, 0)
#define swbit(x, b) x ^= (1 << b)
#define swbit0(x) swbit(x, 0)
#define checkbit(x, b) x & (1 << b)
#define checkbit0(x) checkbit(x, 0)
#define popcnt(x) __builtin_popcountll(x)
#define forsubs(x) for (int s = x; s >= 0; s = (s > 0) ? (s - 1)&x : -1)

const int INF = numeric_limits<int>::max();
const i64 LLINF = numeric_limits<i64>::max();

std::bitset<32> bits(int x) { return std::bitset<32>(x); }

template <class F, class S>
ostream& operator<<(ostream& o, const pair<F,S>& p) {
    return o << "(" << p.first << ", " << p.second << ")";
}
template <class T> ostream& operator<<(ostream& o, const vector<T>& a);
template<class C> void csp(ostream& o, const C& c) {
    bool f = 1; for (const auto& x : c) { if (!f) o << ", "; f = 0; o << x; }
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& a) {
    o << "["; csp(o, a); o << "]"; return o;
}
template <class T>
ostream& operator<<(ostream& o, const vector<vector<T>>& a) {
    for (const auto& x : a) {
        o << "["; csp(o, x); o << "]\n";
    }
    return o;
}
template <class T, class R>
ostream& operator<<(ostream& o, const map<T, R>& a) {
    o << "{"; csp(o, a); o << "}"; return o;
}
template <class T, class R>
ostream& operator<<(ostream& o, const unordered_map<T, R>& a) {
    o << "{"; csp(o, a); o << "}"; return o;
}
template <class T>
ostream& operator<<(ostream& o, const set<T>& a) {
    o << "{"; csp(o, a); o << "}"; return o;
}
template <class T>
ostream& operator<<(ostream& o, const unordered_set<T>& a) {
    o << "{"; csp(o, a); o << "}"; return o;
}

int main() {
    starttime();
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t; rvar(t);
    forn(i, t) {
        int m, k; cin >> m >> k;
        vector<int> a(k); rvec(x, a);
        vector<int> wasted(k, 0);
        vector<int> wastedBeforeDis(k, 0);
        vector<int> b(m - 1);
        int firstDis = -1;
        int numUnk = 0;
        int unkBeforeDis = 0;
        vector<bool> wasAfterDis(k, false);
        forn(j, m - 1) {
            int y; cin >> b[j] >> y;
            --b[j];
            if (y == 1 && firstDis == -1) {
                firstDis = j;
            }
            if (b[j] == -1) {
                ++numUnk;
                if (firstDis == -1) {
                    ++unkBeforeDis;
                }
            } else {
                ++wasted[b[j]];
                if (firstDis == -1) {
                    ++wastedBeforeDis[b[j]];
                } else {
                    wasAfterDis[b[j]] = true;
                }
            }
        }
        vector<bool> ans(k, false);
        if (firstDis > -1) {
            int minNeedToDis = INF;
            forn(i, k) {
                if (!wasAfterDis[i] &&
                        unkBeforeDis >= a[i] - wastedBeforeDis[i]) {
                    int needToDis = (a[i] - wastedBeforeDis[i]);
                    if (needToDis < minNeedToDis) {
                        minNeedToDis = needToDis;
                    }
                    ans[i] = true;
                }
            }
            unkBeforeDis -= minNeedToDis;
            numUnk -= minNeedToDis;
        }
        forn(i, k) {
            if (!ans[i]) {
                if (numUnk >= a[i] - wasted[i]) {
                    ans[i] = true;
                }
            }
            printf("%c", (ans[i] ? 'Y' : 'N'));
        }
        printf("\n");
    }

    checktime();
    return 0;
}
