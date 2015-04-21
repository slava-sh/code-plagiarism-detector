#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 5000;

typedef long long ll;
typedef long double ld;

int d[maxn][maxn];
int a[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
        for (int j = i + 1; j < n; ++j) {
            d[i][j] = d[i][j - 1];
            if (a[i] > a[j]) d[i][j]++;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        d[i][i] = 0;
        for (int j = i - 1; j >= 0; --j) {
            d[i][j] = d[i][j + 1];
            if (a[j] > a[i]) d[i][j]++;
        }
    }
    int ans = 0;
    int ans1 = -2, ans2 = -2;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (d[i][j] + d[j][i] - (j - i + 1) > ans) {
                ans = d[i][j] + d[j][i] - (j - i + 1);
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout << ans1 + 1 << ' ' << ans2 + 1 << endl;

    return 0;
}

