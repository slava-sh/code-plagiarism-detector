/*
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 300000 + 10;

int in[N];
int n, p;

int main() {
    scanf("%d%d", &n, &p);
    int u, v;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &v);
        ++in[u - 1];
        ++in[v - 1];
    }

    std::sort(in, in + n);

    long long ans = 0;
    int l, r, mid;
    for (int i = 0; i + 1 < n; ++i) {
        if (in[n - 1] + in[i] < p)
            continue;
        l = i, r = n - 1;
        while (r - l > 1) {
            mid = (l + r) >> 1;
            if (in[mid] + in[i] >= p)
                r = mid;
            else
                l = mid;
        }
        ans += n - r;
    }

    printf("%I64d\n", ans);
    return 0;
}
*/
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int N = 755000;
int n, p;
int x[N], y[N], h[N], s[N];
vector<int> v[N];

int add(int x, int v) {
    x ++;
    while(x <= n + 1) {
        s[x] += v;
        x = x + x - (x & (x - 1));
    }
}
int fin(int x) {
    int r = 0;
    x ++;
    while(x > 0) {
        r += s[x];
        x &= x - 1;
    }
    return r;
}
int main() {
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i], --y[i];
        h[x[i]]++, h[y[i]]++;
        v[x[i]].push_back(i);
        v[y[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        add(h[i], 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j =0; j < v[i].size(); ++j) {
            int id = v[i][j];
            add(h[x[id]], -1);
            add(h[y[id]], -1);
            h[x[id]]--;
            h[y[id]]--;
            add(h[x[id]], 1);
            add(h[y[id]], 1);
        }
        int need = p - (int) v[i].size();
        int ad = n;
        if (need > 0) ad = n - fin(need - 1);

        if (h[i] >= need) --ad;
        ans += ad;
        for (int j = 0; j < v[i].size(); ++j) {
            int id = v[i][j];
            add(h[x[id]], -1);
            add(h[y[id]], -1);
            h[x[id]]++;
            h[y[id]]++;
            add(h[x[id]], 1);
            add(h[y[id]], 1);
        }
    }
    /*
for (int i = 0; i < n; ++i) {
        for (int j =0; j < v[i].size(); ++j) {
            int id = v[i][j];
            add(h[x[id]], -1);
            add(h[y[id]], -1);
            h[x[id]]--;
            h[y[id]]--;
            add(h[x[id]], 1);
            add(h[y[id]], 1);
        }
        int need = p - (int) v[i].size();
        int ad = n;
        if (need > 0) ad = n - fin(need - 1);

        if (h[i] >= need) --ad;
        ans += ad;
        for (int j = 0; j < v[i].size(); ++j) {
            int id = v[i][j];
            add(h[x[id]], -1);
            add(h[y[id]], -1);
            h[x[id]]++;
            h[y[id]]++;
            add(h[x[id]], 1);
            add(h[y[id]], 1);
        }
    }
    */
    cout << ans / 2 << endl;
    return 0;
}