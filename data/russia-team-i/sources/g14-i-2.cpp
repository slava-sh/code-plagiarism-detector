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

ll n, d, res, a[300010], sum;

int main () {

    freopen("sochi.in", "r", stdin); freopen("sochi.out", "w", stdout);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    cin >> n >> d;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    
    reverse(a + 1, a + n + 1);
    
    int i;
    
    for (i = 1; i <= n; i++)
        if (a[i] < 2 * d) break; else sum += a[i];
    
    if (a[i] < d) i--; else sum += a[i];
    
    cout << sum - (i - 2) * 2 * d - 2 * d;

    return 0;

}