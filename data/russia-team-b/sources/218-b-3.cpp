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

#define TASK "che"

int n, r;
vector<int> L;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    

    scanf("%d %d", &n, &r);
    L.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &L[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int ind = max(0, lower_bound(L.begin(), L.end(), L[i] - r) - L.begin() - 1);
        if (L[ind] < L[i] - r) {
            ans += ind + 1;
        }
    }

    cout << ans;
}