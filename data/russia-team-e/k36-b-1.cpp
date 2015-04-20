#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <time.h>
#include <cassert>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>

#define FORN(i, n) for(int i=0; i<n; i++)
#define FORI(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a-1; i>=b; i--)

using namespace std;

long long ans;
int n, r;
int mas[300010];
vector<int>v;

int main () {
    //#define LOCAL
    #ifndef LOCAL
        freopen ("che.in", "r", stdin);
        freopen ("che.out", "w", stdout);
    #endif

    cin >> n >> r;
    int m;
    FORN(i, n){
        cin >> mas[i];
    }
    FORN(i, n) {
        int cur = mas[i];
        int k=upper_bound(mas,mas+n,mas[i]+r)-mas ;
        ans+=n-k;

    }
    cout << ans << endl;
    return 0;
}
