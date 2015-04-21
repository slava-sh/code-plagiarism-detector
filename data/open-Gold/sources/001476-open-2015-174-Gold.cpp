#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e17;

main() {
    ios_base::sync_with_stdio(false);

    int N, K, C, D;
    cin >> N >> K >> C >> D;

    vector<int> prev(K + 1, INF);
    vector<int> next(K + 1, INF);

    int prev_b = 0;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        if (i == 1) {
            next[1] = (b - a) * D;
            for (int i = 2; i <= K; i++) {
                next[i] = INF;
            }
        } else {
            next[1] = (b - a) * D + min(prev[K] + C, prev[1] + (a - prev_b) * D);
            for (int i = 2; i <= K; i++) {
                next[i] = (b - a) * D + min(prev[i - 1], prev[i] + (a - prev_b) * D);
            }
        }
        for (auto &i: next) {
            i = min(i, INF);
        }
        prev_b = b;
        prev.swap(next);
        //for (auto i: prev) cout << i << ' '; cout << endl;
    }

    int result = INF;
    for (int i = 1; i <= K; i++) {
        result = min(result, prev[i]);
    }

    cout << result << endl;
}
