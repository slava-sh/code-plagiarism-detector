#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;

#define EPS 1e-9
#define MAXN 100001
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front

typedef long long int64;
typedef long double real;
typedef pair<int, int> pii;

#define TASK "sochi"

int n, d;
vector<int> L;

bool cmp(const int &i1, const int &i2) {
    return i1 > i2;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    
    scanf("%d %d", &n, &d);
    L.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &L[i]);
    }

    sort(L.begin(), L.end(), cmp);

    int ans = 0;
    vector<int> can;

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(ans, L[i]);
    }

    if (n == 1) {
        printf("%d", mx);
        return 0;
    }

    mx = max(mx, L[0] + L[1] - 2 * d);

    for (int i = 0; i < n; ++i) {
        if (L[i] <= d) {
            continue;
        }

        if (L[i] - 2 * d < d) {
            can.pub(L[i] - d);
        } else {
            ans += L[i] - 2 * d;
        }
    }

    sort(can.begin(), can.end(), cmp);
    if (can.size() > 0) {
        ans += can[0];
    }

    if (can.size() > 1) {
        ans += can[1];
    }

    ans = max(ans, mx);
    printf("%d\n", ans);
}