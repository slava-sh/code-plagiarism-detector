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
ll n,m;
int main(){
    freopen("prizes.in","r",stdin); freopen("prizes.out","w",stdout);
    cin>>n>>m;
    if (n>m) swap(n,m);
    n--; m--;
    if (m==0){ cout<<0<<endl; return 0; }
    if (n==0){
              n=m%4;
              if (n>=2) n=1; else n=0;
              cout<<m/4+n<<endl;
              return 0;
              }    
    m=n%4;
    if (m>=2) m=1; else m=0;
    cout<<n/4+m<<endl;
    return 0;
}
















