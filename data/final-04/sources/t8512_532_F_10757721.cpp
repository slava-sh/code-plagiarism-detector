#undef NDEBUG
#ifdef ssu1
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define ford(i, n) for(int i = int(n - 1); i >= 0; --i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;

const int H = 3;
const int N = 200500;

li A[H];
li M[H];
li PM[H][N];

li mul[H][N];

inline bool isPrime(li a) {
    if (a == 1)
        return false;
    for (li i = 2; i*i <= a; ++i)
        if (a % i == 0)
            return false;
    return true;
}

int n, m;
string s, t;

vector<int> pt[30];
li ht[H][30];

vector<int> ps[30];
vector<li> hs[H][30];

int cused;
int used[30];

bool check(int start, int at, int as) {
    if (pt[at].empty())
        return true;
    vector<int>::iterator it = lower_bound(all(ps[as]), start + pt[at][0]);
    if (it == ps[as].end())
        return false;

    int is = it - ps[as].begin();
    if (sz(ps[as]) - is < sz(pt[at]))
        return false;

    forn(hi, H) {
        li cht = (ht[hi][at] + start * PM[hi][sz(pt[at]) - 1]) % M[hi];
        cht = (cht * mul[hi][N - sz(pt[at])]) % M[hi];

        li chs = hs[hi][as][is + sz(pt[at]) - 1];
        if (is > 0) {
            chs -= hs[hi][as][is - 1];
            if (chs < 0)
                chs += M[hi];
        }

        chs = (chs * mul[hi][N - (is + sz(pt[at]))]) % M[hi];

        if (chs != cht)
            return false;
    }

    return true;
}

int main() {
    #ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
    #endif

    {
        int cnt = 0;
        for (li i = 1000000000; cnt < H; ++i)
            if (isPrime(i))
                M[cnt++] = i;

        cnt = 0;
        for (li i = 200500; cnt < H; ++i)
            if (isPrime(i))
                A[cnt++] = i;

        forn(i, 3) {
            mul[i][0] = 1;
            for (int j = 1; j < N; ++j)
                mul[i][j] = (mul[i][j - 1] * A[i]) % M[i];
        }
    }

    forn(i, H) {
        PM[i][0] = mul[i][0];
        for (int j = 1; j < N; ++j) {
            PM[i][j] = PM[i][j - 1] + mul[i][j];
            if (PM[i][j] >= M[i])
                PM[i][j] -= M[i];
        }
    }

    cin >> n >> m >> s >> t;

    forn(i, sz(t))
        pt[t[i] - 'a'].push_back(i);
    forn(i, H) {
        forn(j, 26) {
            ht[i][j] = 0;
            forn(k, sz(pt[j]))
                ht[i][j] = (ht[i][j] + pt[j][k] * mul[i][k]) % M[i];
        }
    }

    forn(i, sz(s))
        ps[s[i] - 'a'].push_back(i);
    forn(i, H) {
        forn(j, 26) {
            li curH = 0;
            forn(k, sz(ps[j])) {
                curH = (curH + ps[j][k] * mul[i][k]) % M[i];
                hs[i][j].push_back(curH);
            }
        }
    }

    vector<int> ans;
    forn(start, n - m + 1) {
        cused++;

        bool good = true;
        forn(i, 26) {
            if (pt[i].empty() || used[i] == cused)
                continue;
            int pos = start + pt[i].front();
            forn(j, 26) {
                if (!binary_search(all(ps[j]), pos))
                    continue;

                if (used[j] == cused || !check(start, i, j) || !check(start, j, i))
                    good = false;
                else {
                    used[i] = used[j] = cused;
                }
                break;
            }

            if (!good)
                break;
        }

        if (good)
            ans.push_back(start);
    }

    cout << sz(ans) << endl;

    forn(i, sz(ans)) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i] + 1);
    }
    cout << endl;
    return 0;
}

