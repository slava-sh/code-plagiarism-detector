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
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
  //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);
    cin>>n>>m; long long s=0;
     long long minc=INF,maxc=0,sum=0;
     for (int k=1;k<=n;++k){
         long long a;
          cin>>a;
          minc=min(minc,a);
          maxc=max(maxc,a);
          sum+=a;
          }
          if (sum>m){cout<<min(minc,m/n);return 0;}
          cout<<minc;
    return 0;
}
