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
        freopen("output1.txt", "w", stdout);
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
        a[d1] = d2;
        last = -1;
        k = 0;
         for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != last) {
                k++;
                last = a[i];
            }
        }
        cout << k << endl;
    }
    return 0;
}
