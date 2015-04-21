#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int a[100100];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int last = -1;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != last) {
            k++;
            last = a[i];
        }
    }
    int d1,d2;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> d1 >> d2;
        d1--;
        if (a[d1] == d2) {
            cout << k << endl;
            continue;
        }
        if (d1 == 0) {
            if (n > 1 && a[1] == a[0]) {
                k++;
            }
            a[0] = d2;
            if (n > 1 && a[0] == a[1]) {
                k--;
            }
        } else if (d1 == n-1) {
            if (n > 1 && a[d1] == a[d1-1]) {
                k++;
            }
            a[d1] = d2;
            if (n > 1 && a[d1] == a[d1-1]) {
                k--;
            }
        } else {
            if (a[d1] == a[d1+1]) k++;
            if (a[d1] == a[d1-1]) k++;
            a[d1] = d2;
            if (a[d1] == a[d1-1]) k--;
            if (a[d1] == a[d1+1]) k--;
        }
        cout << k << endl;
    }
    return 0;
}
