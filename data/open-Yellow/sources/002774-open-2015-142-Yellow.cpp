#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define repe(i,n) for( i = 0; i < (n); i++ )
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second

const int MXN = 100100;
const int MXK = 11;
const int inf = 1e9;
const ll linf = 1e18;


int a [MXN];


int main()
{
    int n;
    scanf("%d", &n);

    int ans = 0;

    rep(i,n){
        scanf("%d", &a[i]);
        if(i && a[i-1]!=a[i] ) ans++;
    }
    int q;
    scanf("%d", &q);
    rep(i,q){
        int p,c;
        scanf("%d%d", &p, &c);
        p--;
        if(p && a[p-1]!=a[p]) ans--;
        if(p+1<n && a[p]!=a[p+1]) ans--;
        a[p] = c;
        if(p && a[p-1]!=a[p]) ans++;
        if(p+1<n && a[p]!=a[p+1]) ans++;
        printf("%d\n", ans+1);
    }

    return 0;
}
