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
int h[100000];

inline int get() {
    int h1[100000];
    for (int i = 0; i < n; i++) {
        h1[i] = h[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool b = true;
        for (int j = 0; j < n - 1; j++) {
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

int d[5000][5000];


int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        h[i]--;
    }
    ans = get();
    int ans1 = ans;
    pair<int, int> p = make_pair(-1, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = (j > 0 ? d[i][j - 1]: 0) + (h[j] > i ? 1: 0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ans2 = ans;
            ans2 -= d[h[i]][i];
            ans2 -= d[h[j]][j];
            ans2 += d[h[i]][j];
            ans2 += d[h[j]][i];
            if (ans2 < ans1) {
                ans1 = ans2;
                p = make_pair(i + 1, j + 1);
            }
        }
    }
    cout << p.first << ' ' << p.second << endl;
    return 0;
}
