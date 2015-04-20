#pragma comment(linker, "/STACK:100000000")

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
#define MAXN 200001
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front

typedef long long int64;
typedef long double real;
typedef pair<int, int> pii;

#define TASK "dwarfs"

int n;
int a, b;
vector<int> G[MAXN];

int d[MAXN];
void setd(int v, int p, int depth) {
    d[v] = depth;

    for (int i = 0; i < G[v].size(); ++i) {
        int to = G[v][i];
        if (to == p) {
            continue;
        }

        setd(to, v, depth + 1);
    }
}

int isOnWay[MAXN];

bool setiow(int v, int p) {
    if (v == b) {
        isOnWay[v] = 0;
    }

    for (int i = 0; i < G[v].size(); ++i) {
        int to = G[v][i];
        if (to == p) {
            continue;
        }

        if(setiow(to, v)) {
            isOnWay[v] = isOnWay[to] + 1;
        }
    }

    return isOnWay[v] != -1;
}

int dp[MAXN];

void calcdp(int v, int p) {
    dp[v] = 1;
    for (int i = 0; i < G[v].size(); ++i) {
        int to = G[v][i];
        if (to == p) {
            continue;
        }

        calcdp(to, v);
        if (isOnWay[to] == -1) {
            dp[v] = max(dp[v], dp[to] + 1);
        }
    }
}

int ans = 0;
int mx;

void setans(int v, int p) {
    if (v == b) {
        return;
    }

    for (int i = 0; i < G[v].size(); ++i) {
        int to = G[v][i];
        if (to == p || isOnWay[to] == -1) {
            continue;
        }

        mx = max(mx, dp[v] + d[v]);
        ans = max(ans, min(mx, dp[to] + isOnWay[to]));
        setans(to, v);
    }
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
    
    for (int i = 0; i < MAXN; ++i) {
        isOnWay[i] = -1;
    }

    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].pub(v);
        G[v].pub(u);
    }

    scanf("%d %d", &a, &b);
    setd(a, -1, 0);
    setiow(a, -1);
    calcdp(a, -1);

    mx = dp[a];
    setans(a, -1);

    printf("%d\n", ans);
}