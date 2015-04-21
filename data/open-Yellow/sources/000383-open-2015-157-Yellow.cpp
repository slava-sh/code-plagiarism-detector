#include <bits/stdc++.h>
using namespace std;

const int INF = 1234567890;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<int> t(n + 2);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    t[0] = t[n + 1] = INF;

    int ans = 0;
    vector<int> left(n + 2), right(n + 2);
    for (int i = 1; i <= n; i++) {
        if (t[i - 1] != t[i]) {
            ++ans;
        }

        if (t[i - 1] != t[i]) left[i] = 1;
        if (t[i + 1] != t[i]) right[i] = 1;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        /*
        for (int j = 1; j <= n; j++) {
            cout << left[j] << ' ';
        }
        cout << endl;
        for (int j = 1; j <= n; j++) {
            cout << right[j] << ' ';
        }
        cout << endl;*/

        int p, c;
        scanf("%d%d", &p, &c);

        int curLeft = (t[p - 1] != c);
        int curRight = (t[p + 1] != c);
        //cout << curLeft << ' ' << curRight << endl;
        ans += curLeft - left[p];
        ans += curRight - right[p];
        left[p] = curLeft;
        right[p] = curRight;
        t[p] = c;
        right[p - 1] = (t[p - 1] != t[p]);
        left[p + 1] = (t[p + 1] != t[p]);

        /*for (int j = 1; j <= n; j++) {
            cout << left[j] << ' ';
        }
        cout << endl;
        for (int j = 1; j <= n; j++) {
            cout << right[j] << ' ';
        }
        cout << endl;*/

        printf("%d\n", ans);
        //puts("-----------");
    }
}
