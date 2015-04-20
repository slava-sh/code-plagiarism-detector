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

#define TASK "fence"

int n, k;
vector<int> A;

bool check(int x) {
    int64 ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] < x) {
            return false;
        }

        ptr += x;
    }

    return ptr <= k;
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
    
    scanf("%d %d", &n, &k);
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    sort(A.begin(), A.end());
    int l = 0, r = A[0] + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m))  {
            l = m;
        } else {
            r = m;
        }
    }

    printf("%d\n", l);
}