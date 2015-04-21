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

const int MXN = 1000100;
const int MXK = 11;
const int inf = 1e9;
const ll linf = 1e18;


int a [MXN];
int p [MXN];

int dd [MXN];

void updd( int l, int v ){
    for( ; l < MXN; l = (l|(l+1)) )
        dd[l] += v;
}
int sumd( int r ){
    int res = 0;
    for( ; r>=0; r = (r & (r+1) ) - 1)
        res += dd[r];
    return res;
}
int sumd( int l, int r ){
    return sumd(r) - sumd(l-1);
}




int main()
{
//    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);gr[v*2+1].begin(), gr[v*2+1].end(),

    int n;
    scanf("%d", &n);

    rep(i,n){
        scanf("%d", &a[i]);
        a[i]--;
        p[a[i]] = i;
    }

    int res = 0;
    int l = 0, r = 0;

    rep(i,n){
        rep(j,n) dd[j] = 0;
        int q = p[i];
        if(q){
            for( int j = q-1; j>=0; j-- ){
                if(a[j]<i) continue;
                int rs = sumd(a[j]);
                if(rs>res){
                    res = rs;
                    l = j;
                    r = q;
                }
                updd(a[j],1);
            }
        }
    }
    if(res) printf("%d %d", l+1, r+1);
    else printf("-1 -1");

    return 0;
}
