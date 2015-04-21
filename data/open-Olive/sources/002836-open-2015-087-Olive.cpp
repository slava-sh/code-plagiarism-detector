#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int f[1001000];

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
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    int ans = -1;
    int a1 = -1, a2 = -1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            //cout << j << " " << i << " " << abs(i - f[i]) + abs(j - f[j]) - abs(j - f[i]) - abs(i - f[j]) << endl;
            if (ans < abs(i - f[i]) + abs(j - f[j]) - abs(j - f[i]) - abs(i - f[j])) {
                ans = abs(i - f[i]) + abs(j - f[j]) - abs(j - f[i]) - abs(i - f[j]);
                a1 = j;
                a2 = i;
            }
        }
    }
    cout << a1 << " " << a2 << endl;
    return 0;
}
