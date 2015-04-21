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

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (i > 0 && h[i] < h[i - 1]) {
            ans++;
        }
    }
    pair<int, pair<int, int> > p = make_pair(ans, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(h[i], h[j]);
            int t = 0;
            if (i < n - 1 && h[i] > h[i + 1] && h[j] < h[i + 1]) {
                t++;
            }
            if (i < n - 1 && h[i] < h[i + 1] && h[j] > h[i + 1]) {
                t--;
            }
            if (j > 0 && h[j] < h[j - 1] && h[i] > h[j - 1]) {
                t++;
            }
            if (j > 0 && h[j] > h[j - 1] && h[i] < h[j - 1]) {
                t--;
            }
            if (j == i + 1) {
                if (h[j] > h[i]) {
                    t--;
                } else {
                    t++;
                }
            } else {
                if (j < n - 1 && h[j] > h[j + 1] && h[i] < h[j + 1]) {
                    t++;
                }
                if (j < n - 1 && h[j] < h[j + 1] && h[i] > h[j + 1]) {
                    t--;
                }
                if (i > 0 && h[i] < h[i - 1] && h[j] > h[i - 1]) {
                    t++;
                }
                if (i > 0 && h[i] > h[i - 1] && h[j] < h[i - 1]) {
                    t--;
                }
            }
            if (ans + t < p.first) {
                p = make_pair(ans + t, make_pair(i + 1, j + 1));
            }
        }
    }
    cout << p.second.first << ' ' << p.second.second << endl;
    return 0;
}
