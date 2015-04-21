#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int INF = 2e9;

ll mas[20], n, last;
int k;

int dfs(int n, int k) {
    if (k == 1) {
        return (n + 1) / 2;
    }
    int best = INF;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        int res = dfs(n / i, k - 1);
        best = min(best, res * ((i + 1) / 2));
    }
    return best;
}

void build(int n, int k, int res) {
    if (k == 1) {
        mas[++last] = n;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        int cur = dfs(n / i, k - 1);
        if (res == cur * ((i + 1)) / 2) {
            mas[++last] = i;
            build(n / i, k - 1, cur);
            return;
        }
    }
}

ll cnt(int x, ll n) {
    if (x > k) {
        return ((n + 1) / 2);
    }
    ll gg = cnt(x + 1, n / mas[x]);
    return ((mas[x] + 1) / 2) * gg;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("good.txt", "w", stdout);
    int n;
    scanf("%d %d", &n, &k);
    last = 0;
    int get = dfs(n, k);
    build(n, k, get);
    printf("%lld\n", cnt(1, n));
    return 0;
}