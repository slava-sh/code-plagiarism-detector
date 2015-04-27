#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int L;
    cin >> L;
    cin >> s;
    int N = s.size();

    int result = N + 1;
    set<string> words;
    for (int mask = 0; mask < (1 << (N - 1)); mask++) {
        vector<int> borders;
        borders.push_back(0);
        for (int i = 0; i < N - 1; i++) {
            if (mask & (1 << i)) borders.push_back(i + 1);
        }
        borders.push_back(N);

        bool flag = true;
        set<string> Set;
        for (int i = 0; i < borders.size() - 1; i++) {
            int l = borders[i], r = borders[i + 1] - 1;
            if (r - l + 1 > L) flag = false;
            Set.insert(s.substr(l, r - l + 1));
        }
        if (flag && Set.size() < result) {
            result = Set.size();
            words.clear(); for (auto i: Set) words.insert(i);
        }
    }
    cout << result << endl;
    for (auto i: words) {
        cout << i << endl;
    }
}
