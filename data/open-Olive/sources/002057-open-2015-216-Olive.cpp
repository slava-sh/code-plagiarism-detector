#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 300 + 10;
const ll INF = 2e18;

int tree[N], a[N], n;

int sum(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        res += tree[i];
    }
    return res;
}

void modify(int x) {
    for (int i = x; i < N; i = (i | (i + 1))) {
        tree[i]++;
    }
}

ll get_ans() {
    ll res = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        res += i - sum(a[i]) - 1;
        modify(a[i]);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = get_ans();
    int p1 = -1, p2 = -1;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1 + 1; i2 <= n; i2++) {
            swap(a[i1], a[i2]);
            ll cur = get_ans();
            swap(a[i1], a[i2]);
            if (cur < ans) {
                ans = cur;
                p1 = i1;
                p2 = i2;
            }
        }
    }
    cout << p1 << " " << p2 << "\n";
    return 0;
}