#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    ios_base::sync_with_stdio(false);

    int N, K, C, D;
    cin >> N >> K >> C >> D;

    vector<int> segments;
    segments.reserve(N - 1);
    int result = 0;

    int prev_b = 0;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        if (i != 1) {
            segments.push_back(a - prev_b);
        }
        prev_b = b;
        result += b - a;
    }
    result *= D;

    sort(segments.begin(), segments.end());

    if (N <= K) {
        cout << result << endl;
        return 0;
    }

    for (int i = 0; i < K - 1; i++) {
        segments.pop_back();
    }
    int S = accumulate(segments.begin(), segments.end(), 0LL);
    int res = S * D;
    for (int i = 1; !segments.empty(); i++) {
        for (int j = 0; j < K && !segments.empty(); j++) {
            S -= segments.back();
            segments.pop_back();
        }
        res = min(res, S * D + i * C);
    }

    cout << result + res << endl;

}
