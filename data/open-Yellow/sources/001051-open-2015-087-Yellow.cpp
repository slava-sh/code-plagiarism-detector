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
    int d1,d2;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> d1 >> d2;
        d1--;
        a[d1] = d2;
        last = -2000000000;
        k = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != last) {
                k++;
                last = a[j];
            }
        }
        cout << k << endl;
    }
    return 0;
}
