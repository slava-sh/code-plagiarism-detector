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
        printf("%d ", n);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        int cur = dfs(n / i, k - 1);
        if (res == cur * ((i + 1)) / 2) {
            printf("%d\n", i);
            build(n / i, k - 1, cur);
            return;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int get = dfs(n, k);
    printf("%d\n", get);
    //build(n, k, get);
    return 0;
}