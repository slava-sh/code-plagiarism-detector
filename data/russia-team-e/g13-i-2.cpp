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

ll n,d,j,a[200000],res,q;
int main(){
    freopen("sochi.in","r",stdin); freopen("sochi.out","w",stdout);
    cin>>n>>d;
    For(k,1,n) cin>>a[k];
    sort(a+1,a+n+1);
    j=0;
    if (n==1){ cout<<a[1]<<endl; return 0; }
    For(k,1,n) if (a[k]>=3*d){ j=k; break; }
    if (j==0){
              q=a[n]+a[n-1]-2*d;
              if (q>a[n]) cout<<q<<endl; else cout<<a[n]<<endl;
              return 0;
              }
    For(k,j,n) res+=a[k];
    q=(n-j+1)*2;
    if (j>=3){
              if(a[j-1]-d*2>0){
                             res+=a[j-1]; 
                             q++;
                             if (a[j-2]-d*2>0){
                                             res+=a[j-2];
                                             q++; 
                                             }
                             else q--;
                             }
              else q-=2;
              res=res-q*d;
              cout<<res<<endl;
              return 0;
              }
    if (j==2){
              q--;
              if (a[1]-d*2>0){
                              q++; res+=a[1];
                              }
              res=res-q*d;
              cout<<res<<endl;
              return 0;
              }
    q-=2;
    cout<<res-q*d<<endl;
    return 0;
}
















