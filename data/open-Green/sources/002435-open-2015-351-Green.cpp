#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const long long inf = 11111111111111111LL;

long long n, k;
unordered_map<pair<long long, int>, long long> q;
vector<int> v;

long long fun(long long i, int j) {
    if (j == 1) {
        return (i + 1) / 2;
    }
    pair<long long, int> p = make_pair(i, j);
    if (q.count(p)) {
        return q[p];
    }
    long long res = inf;
    for (long long d = 1; d * d <= i; ++d) {
        int x = (d + 1) / 2;
        if (x >= res) {
            q[p] = res;
            return res;
        }
        if (i % d == 0) {
            res = min(res, x * fun(i / d, j - 1));
        }
    }
    q[p] = res;
    return res;
}

int main() {
    cin >> n >> k;
    cout << fun(n, k) << endl;
    return 0;
}
