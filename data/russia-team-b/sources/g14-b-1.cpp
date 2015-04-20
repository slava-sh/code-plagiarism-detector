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

ll n, r, res, a[300010];

int main () {

    freopen("che.in", "r", stdin); freopen("che.out", "w", stdout);
    
    cin >> n >> r;
    
    for (int j = 1; j <= n; j++) cin >> a[j];
    
    int i = 1;
    
    for (int j = 1; j <= n;) {
    
        if (a[j] - a[i] > r) { res += n - j + 1; i++; }
        else j++;
        
    }
    
    cout << res;

    return 0;

}
