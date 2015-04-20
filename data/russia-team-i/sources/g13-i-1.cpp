#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue> 
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define inf 2000000000
#define For(i,s,n) for (int i=s;i<=n;i++)
#define FOR(i,s,n) for (int i=s;i<n;i++)
#define Ford(i,s,n) for (int i=s;i>=n;i--)
#define MD 1000000007

typedef long long ll;

using namespace std;

ll n,d,j,a[200000],res;
int main(){
    freopen("sochi.in","r",stdin); freopen("sochi.out","w",stdout);
    cin>>n>>d;
    For(k,1,n) cin>>a[k];
    sort(a+1,a+n+1);
    For(k,1,n) if (a[k]>=3*d){ j=k; break; }
    For(k,j,n) res+=a[k]-2*d;
    if (j==2){
              res+=d;
              if (a[1]>d*2) res+=a[1]-d; else res+=d;
              }
    if (j==1) res+=d*2;
    if (j>2){
             if (a[j-1]>d) res+=a[j-1]-d;
             if (a[j-2]>d) res+=a[j-2]-d;
             }
    cout<<res<<endl;
    return 0;
}
















