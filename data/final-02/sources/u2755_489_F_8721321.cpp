#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
int n, m, mod;
string s;
int C[606];
int c1[501][501], c2[501][501];
void add(int &x, long long y) {
    y %= mod;
    x += y;
    if (x >= mod) x -= mod;
}
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> mod;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int counter = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') counter++;
            C[j] += s[j] - '0';
        }
        if (counter != 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i)
        if (C[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    int fir, sec;
    fir = sec = 0;
    for (int i = 0; i < n; ++i)
        if (C[i] == 0) fir++; else if (C[i] == 1) sec++;
    c1[fir][sec]=1;
    for (int i = m; i < n; ++i) {
        memset(c2, 0, sizeof(c2));
        for (int j = 0; j <= n; ++j)
            for (int q = 0; q <= n && j + q <= n; ++q)
                if (c1[j][q]) {
                    if (j >= 2) add(c2[j - 2][q + 2], 1LL * c1[j][q] * j * (j - 1) / 2);
                    if (q >= 2) add(c2[j][q - 2], 1LL * c1[j][q] * q * (q - 1) / 2);
                    if (j >= 1 && q >= 1) add(c2[j - 1][q], 1LL * c1[j][q] * j * q);
                }
        for (int j = 0; j <= n; ++j)
            for (int q = 0; q <= n; ++q)
                c1[j][q] = c2[j][q];
    }
    cout<<c1[0][0]<<endl;
}
