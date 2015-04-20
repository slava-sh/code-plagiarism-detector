#include<iostream>
#include<map>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<fstream>
#include<math.h>
#include<utility>
#define INF 1000000001
using namespace std;
struct o{
       int x,y;
       };
long long n,m,sum=0;
long long  b[1000000]={0};
bool solve (int l,int minc){
      long long  h=sum,cham=0,pre=b[1];
    for (int k=2;k<=n;++k)  {
     long long pre1=pre; pre+=l;
        pre=max(pre,pre1+b[k]-b[k-1]);
        if (k==n && pre>m && pre1+l<=m) {return 1;}
        }
    if (pre<=m) return 1;else return 0;
}
int main(){
  freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
//freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   cin>>n>>m; 
   long long  minc=INF,maxc=0;
     int j=0;
     for (int k=1;k<=n;++k){
      long long  a;
          cin>>a;
          b[k]=a;
          if (a>=m) j++;
          minc=min(minc,a);
          sum+=a;
          }
          sort(b+1,b+n+1);
          if (j>=2) {cout<<0;return 0;}
         if (sum<=m){cout<<minc; return 0;} 
         long long l,r; long long  inc=minc;
           r=min(m/n,inc);
        for(l=3;l>=3;--l){
            if (solve(l,minc)==1){
              break;
            }     
        }  
        cout<<min(minc,l);
return 0;
}
