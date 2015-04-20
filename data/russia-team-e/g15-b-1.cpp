#include<iostream>
#include<map>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<fstream>
#include<math.h>
#include<utility>
#define INF 100000000
using namespace std;
struct o{
       int x,y;
       };
long long n,m,a[1000000]={0};
int main(){
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
   //  freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m; long long s=0;
    for (int k=1;k<=n;++k) cin>>a[k];
    sort(a+1,a+n+1);
    for (int k=1;k<=n;++k){
        long l=1,r=n+1;a[r]=INF;
        while (l<r){
              long mid=(l+r)/2;
              if (a[mid]-a[k]<=m) l=mid+1;
              else {r=mid;}
              }
              s+=n-l+1;
    }
    cout<<s;
    return 0;
}
