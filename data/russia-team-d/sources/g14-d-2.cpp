#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define m9 1000000009
#define m7 1000000007
#define INF 1000000001
#define fi first
#define se second
#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
using namespace std;

ll n, k, res, res_md, p, a[300010], sum, q;

int main () {

    freopen("sochi.in", "r", stdin); freopen("sochi.out", "w", stdout);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) { cin >> a[i]; sum += a[i]; }
    
    sort(a + 1, a + n + 1);
    
    res = k / n;
    res_md = k % n;
    
    if (sum <= k) { cout << a[1]; return 0; }
    
    for (int i = 1; i <= n; i++) {
        
        p = a[i] - a[i - 1];
        
        if (p > res) {res_md -= (p - res); q++;}
        if (res_md < 0) { res--; res_md += n;res_md-=q; }
    
    }
    while(res_md<0){res--;res_md+=n;}
    cout << max(0LL,res);
    
    return 0;

}
