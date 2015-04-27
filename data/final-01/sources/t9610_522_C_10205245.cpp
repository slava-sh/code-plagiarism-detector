#include<bits/stdc++.h>
using namespace std;


void solve() {

    int n, k, firstRoar = -1;
    scanf("%d%d", &n, &k);
    n--;

    vector<int> a(k), ans(k), r(n), t(n);
    for (int &i : a) {
        scanf("%d", &i);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &t[i], &r[i]);
        t[i]--;
        if (r[i] && firstRoar == -1) {
            firstRoar = i;
        }
    }

    if (firstRoar == -1) {
        int unidentified = 0;
        for (int i = 0; i < n; i++)
            if (t[i] != -1) {
                a[t[i]]--;
            } else {
                unidentified++;
            }
        for (int i = 0; i < k; i++) {
            printf(unidentified >= a[i] ? "Y" : "N");
        }
        printf("\n");
        return;
    }

    vector<char> meetInSuf(k);
    for (int i = firstRoar; i < n; i++)
        if (t[i] != -1) {
            meetInSuf[t[i]] = true;
        }

    int unidentified = 0;
    for (int i = 0; i < firstRoar; i++)
        if (t[i] != -1) {
            a[t[i]]--;
        } else {
            unidentified++;
        }

    int minToSpend = 1e9;
    for (int i = 0; i < k; i++)
        if (!meetInSuf[i] && a[i] <= unidentified) {
            ans[i] = true;
            minToSpend = min(minToSpend, a[i]);
        }

    unidentified -= minToSpend;
    for (int i = firstRoar; i < n; i++)
        if (t[i] != -1) {
            a[t[i]]--;
        } else {
            unidentified++;
        }

    for (int i = 0; i < k; i++)
        if (a[i] <= unidentified) {
            ans[i] = true;
        }

    for (int i : ans) {
        printf(i ? "Y" : "N");
    }
    printf("\n");

    return;
}


main() {
#ifndef ONLINE_JUDGE
    freopen("1.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}
