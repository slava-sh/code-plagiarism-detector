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
int t[100000];
int l[100000], r[10000];
int q;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (i > 0 && t[i] != t[i - 1]) {
            ans++;
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int p, c;
        cin >> p >> c;
        p--;
        if (t[p] == c) {
            cout << ans << endl;
        } else {
            if (p > 0 && t[p - 1] == c) {
                ans--;
            }
            if (p + 1 < n && t[p + 1] == c) {
                ans--;
            }
            if (p > 0) {
                if (t[p] == t[p - 1]) {
                    ans++;
                }
            }
            if (p + 1 < n) {
                if (t[p + 1] == t[p]) {
                    ans++;
                }
            }
            t[p] = c;
            cout << ans << endl;
        }
    }
    return 0;
}
