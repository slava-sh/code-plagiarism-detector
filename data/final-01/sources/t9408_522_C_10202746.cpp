#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int SZ = 2e5 + 100;
const int INF = 1e9;

int a[SZ];
int b[SZ];
int ans[SZ];

int main()
{
    int t;
    cin >> t;
    for (int o = 0; o < t; o++) {
        int m, k;
        cin >> m >> k;

        for (int j = 0; j < k; j++) {
            cin >> a[j + 1];
        }
        int was01 = 0;
        int before = 0, after = 0;
        for (int j = 0; j < m - 1; j++) {
            int t, r;
            cin >> t >> r;

            if (t != 0 && r == 0) {
                a[t]--;
                b[t] = INF;
                if (a[t] == 0) {
                    if (!was01) memcpy(b, a, (k + 2) * sizeof(int));
                    was01 = 1;
                    ans[t] = 1;
                }
            }

            if (t == 0 && r == 1 && !was01) {
                was01 = 1;
                memcpy(b, a, (k + 2) * sizeof(int));
            }

            if (t == 0) {
                if (was01) {
                    after++;
                } else {
                    before++;
                }
            }

            if (t != 0 && r == 1) {
                if (!was01) {
                    memcpy(b, a, (k + 2) * sizeof(int));
                    was01 = 1;
                }
                a[t]--;
                b[t] = INF;
            }
        }
        int c = before + after;
        if (was01) {
            for (int i = 1; i <= k; i++) {
                if (b[i] <= before) {
                    ans[i] = 1;
                }
            }
            int mn = 1e9;
            for (int i = 1; i <= k; i++) {
                if (b[i] < mn) {
                    mn = b[i];
                }
            }
            c -= mn;
        }


        for (int i = 1; i <= k; i++) {
            if (a[i] <= c) {
                ans[i] = 1;
            }
        }

        for (int i = 1; i <= k; i++) {
            cout << (ans[i] ? 'Y' : 'N');
            ans[i] = 0;
        }
        cout << endl;

    }
    return 0;
}
