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

const int MXN = 200100;
const int MXK = 11;
const int inf = 1e9;
const ll linf = 1e18;

int n,k;
ll c,d;

ll cst [MXN];

int main()
{
    cin>>n>>k>>c>>d;

    ll res = 0;

    int prev;

    rep(i,n){
        int a,b;
        scanf("%d%d", &a, &b);
        res += d*(b-a);
        if(i) res += (a-prev)*d;
        if(i) cst[i-1] = (a-prev)*d;
        prev = b;
    }
    n--;
    sort(cst, cst+n, greater<ll>());
    //res += c;
    bool fst = true;
    int i1 = 0;
    while(i1<n && i1<k-1){
        res -= cst[i1];
    }
    while(i1<n){
        ll sum = 0;
        int j = i1;
        while(j<n && j < i1+k){
            sum+=cst[j];
            j++;
        }
        if(sum>c){
            res += c;
            res -= sum;
            i1 = j;
        }
        else break;
    }

    cout<<res;


    return 0;
}
