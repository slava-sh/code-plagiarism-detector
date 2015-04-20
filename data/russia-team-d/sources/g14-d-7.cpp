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

bool check(ll m) {
     
     ll sheughebav = k;
     ll sheghebili = 0;
     
     if (m > a[1]) return false;

     for (int i = 1; i <= n; i++) {
     
         if (sheughebav < m) return false;
         if (sheghebili > a[i]) { sheughebav -= m; sheghebili += m; }
         else { sheughebav -= max(a[i] - sheghebili, m); sheghebili += max(a[i] - sheghebili, m); }
              
     }
     
     return true;

}

int main () {

    freopen("fence.in", "r", stdin); freopen("fence.out", "w", stdout);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) { cin >> a[i]; sum += a[i]; }
    
    sort(a + 1, a + n + 1);
    
    if (sum <= k) { cout << a[1]; return 0; }
    
    int l = 0, r = k + 1;
    
    while (l < r - 1) {
          
          ll m = (l + r) / 2;
          
          if (check(m)) l = m; else r = m;
    
    }
    
    cout << l;
    
    return 0;

}
