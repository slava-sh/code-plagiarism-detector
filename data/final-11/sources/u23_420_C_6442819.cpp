#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

const int MAXN = 300000;
VI ve[MAXN + 10];

int main(void) {
    int n, P; scanf("%d%d", &n, &P);
    VI deg(n);
    vector<PII> p;
    REP (i, n) {
        int a, b; scanf("%d%d", &a, &b);
        --a; --b;
        ++deg[a]; ++deg[b];
        if (a > b) {
            swap(a, b);
        }
        p.PB(MP(a, b));
        ve[a].PB(b);
        ve[b].PB(a);
    }
    REP (i, n) {
        sort(ALL(ve[i]));
        ve[i].erase(unique(ALL(ve[i])), ve[i].end());
    }
    LL res = 0LL;
    sort(ALL(p));
    for (int i = 0; i < SZ(p); ) {
        int j;
        for (j = i; j < SZ(p) && p[i] == p[j]; ++j);
        int a = p[i].first, b = p[i].second;
        if (deg[a] + deg[b] - (j - i) >= P) {
            res += 2;
        }
        i = j;
    }
    VI ds = deg;
    sort(ALL(ds));
    REP (i, n) {
        int B = P - deg[i];
        int cnt = n - (lower_bound(ALL(ds), B) - ds.begin());
        res += cnt;
        if (deg[i] >= B) {
            --res;
        }
        FC (ve[i], it) {
            if (deg[*it] >= B) {
                --res;
            }
        }
    }
    res /= 2;
    printf("%I64d\n", res);
    return 0;
}


