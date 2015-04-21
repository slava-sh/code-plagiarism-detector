#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>

using namespace std;

const int N = (int)1e6 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;

int a[N], d[N][15];

int main()
{
    int k, n, t, cc, v = 0;
    cin >> n >> k;
    d[1][0] = 1;
    for (int i = 1; i * i <= n; i++)
    if (n % i == 0){
        a[v++] = i;
        if (i * i != n)
            a[v++] = n / i;
    }
    sort(a, a + v);
    for (int ii = 0; ii < v - 1; ii++){
        int i = a[ii];
        for (int j = 0; j < k; j++){
            if (d[i][j] == 0)
                continue;
            t = n / i;
            for (int c = 1; c * c <= t; c++)
            if (t % c == 0){
                if (d[i * c][j + 1] == 0ll)
                    d[i * c][j + 1] = d[i][j] * ((ll)c / 2ll + c % 2ll);
                d[i * c][j + 1] = min(d[i * c][j + 1], d[i][j] * (c / 2 + c % 2));
                cc = t / c;
                if (d[i * cc][j + 1] == 0ll)
                    d[i * cc][j + 1] = d[i][j] * ((ll)cc / 2ll + cc % 2ll);
                d[i * cc][j + 1] = min(d[i * cc][j + 1], d[i][j] * (cc / 2 + cc % 2));
            }
        }
    }
    cout << d[n][k];
    return 0;
}
