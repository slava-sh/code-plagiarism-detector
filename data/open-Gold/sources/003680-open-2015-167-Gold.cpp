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

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;

ll d[3007][3007];

int main(){
    ll c, dd, a, b, t, ans = -1;
    int n, k;
    cin >> n >> k >> c >> dd;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            d[i][j] = -1;
    cin >> a >> b;
        d[1][1] = (b - a) * dd;
    t = b;
    for (int i = 2; i <= n; i++){
        cin >> a >> b;
        if (d[i - 1][k] != -1)
            d[i][1] = min(d[i - 1][1] + (b - t) * dd, d[i - 1][k] + c + (b - a) * dd);
        else
            d[i][1] = d[i - 1][1] + (b - t) * dd;
        for (int j = 2; j <= k; j++)
            if (d[i - 1][j - 1] == -1 && d[i - 1][j] == -1)
                continue;
            else{
                if (d[i - 1][j] == -1)
                    d[i][j] = d[i - 1][j - 1] + (b - a) * dd;
                else
                    d[i][j] = min(d[i - 1][j - 1] + (b - a) * dd, d[i - 1][j] + (b - t) * dd);
            }
        t = b;
    }
    for (int i = 1; i <= k; i++)
        if (d[n][i] != -1){
            if (ans == -1ll)
                ans = d[n][i];
            ans = min(ans, d[n][i]);
        }
    cout << ans;
    return 0;
}
