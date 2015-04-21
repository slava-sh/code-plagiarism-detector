#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;

int n;
short h[100000];

inline int get(int l, int r) {
    int h1[100000];
    for (int i = 0; i < n; i++) {
        h1[i] = h[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool b = true;
        for (int j = l; j < r - 1; j++) {
            if (h1[j + 1] < h1[j]) {
                swap(h1[j + 1], h1[j]);
                ans++;
                b = false;
            }
        }
        if (b) {
            break;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    ans = get(0, n);
    pair<int, pair<int, int> > p = make_pair(ans, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (h[j] > h[i]) {
                continue;
            }
            int ans2 = get(i, j + 1);
            swap(h[i], h[j]);
            int ans1 = get(i, j + 1);
            if (ans - ans2 + ans1 < p.first) {
                p = make_pair(ans1, make_pair(i + 1, j + 1));
            }
            swap(h[i], h[j]);
        }
    }
    cout << p.second.first << ' ' << p.second.second << endl;
    return 0;
}
