#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

const int K = 1e5;
const int INF = 1e9;

int a[K], b[K], last[K];
bool ans[K];

int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int m, k, cnt = 0, _cnt = 0, firstBad = -1;
        cin >> m >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            b[i] = 0;
            last[i] = -1;
            ans[i] = 0;
        }
        for (int i = 0; i < m - 1; i++) {
            int t, r;
            cin >> t >> r;
            t--;
            if (t == -1)
                cnt++;
            else {
                last[t] = i;
                b[t]++;
            }
            if (r == 1 && firstBad == -1)
                firstBad = i;
            if (t == -1 && firstBad == -1)
                _cnt++;
        }
        if (firstBad == -1) {
            for (int i = 0; i < k; i++)
                if (a[i] - b[i] <= cnt)
                    ans[i] = 1;
        }
        else {
            int mn = INF;
            for (int i = 0; i < k; i++)
                if (last[i] < firstBad && a[i] - b[i] <= _cnt) {
                    ans[i] = 1;
                    mn = min(a[i] - b[i], mn);
                }
            assert(mn < INF);
            for (int i = 0; i < k; i++)
                if (!ans[i] && a[i] - b[i] <= cnt - mn)
                    ans[i] = 1;
        }
        for (int i = 0; i < k; i++)
            cout << (ans[i] ? "Y" : "N");
        cout << endl;
    }
    return 0;
}
