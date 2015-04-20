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
int n,m;
bool solve (int k,int minc){
    if (minc-k>m/k)
     return 0; else return 1; 
}
int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
   //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m; 
     int minc=INF,maxc=0,sum=0;
     int j=1;
     for (int k=1;k<=n;++k){
         int a;
          cin>>a;
          if (a>=m) j++;
          minc=min(minc,a);
          maxc=max(maxc,a);
          sum+=a;
          }
          if (j>=2) {cout<<0;return 0;}
         if (sum<=m){cout<<minc; return 0;} 
         int l,r;
          l=0; r=min(minc,m/n);
        while (l<r){
           int mid=(l+r)/2;
          if (solve(mid,minc)==0)
            l=mid+1; else r=mid;    
        }  
        cout<<l;
return 0;
}






