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

int ans = 0;
int mx = 0;

void answer() {
    ans = max(ans, mx);
    printf("%d\n", ans);
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

    vector<int> can;

    for (int i = 0; i < n; ++i) {
        mx = max(mx, L[i]);
    }

    if (n == 1) {
        printf("%d\n", mx);
        return 0;
    }

    mx = max(mx, L[0] + L[1] - 2 * d);

    int ctr = 0;
    for (int i = 0; i < n; ++i) {
        if (L[i] <= d) {
            continue;
        }

        if (L[i] - 2 * d < d) {
            can.pub(L[i] - d);
        } else {
            ans += L[i] - 2 * d;
            ++ctr;
        }
    }

    if (ctr == 0) {
        printf("%d\n", mx);
        return 0;
    }

    sort(can.begin(), can.end(), cmp);
    if (can.size() > 1) {
        ans += can[0] + can[1];
        answer();
        return 0;
    }

    if (can.size() > 0) {
        ans += can[0] + d;
        answer();
        return 0;
    }

    if (can.size() == 0) {
        ans += 2 * d;
        answer();
        return 0;
    }
}