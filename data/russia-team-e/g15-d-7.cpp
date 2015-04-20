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
int n,m;
bool solve (int k,int minc){
    if (m-minc>=(n-1)*k)
     return 1; else return 0; 
}
int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
  // freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout);
    cin>>n>>m; 
     int minc=INF,maxc=0,sum=0;
     int j=0;
     for (int k=1;k<=n;++k){
         int a;
          cin>>a;
          if (a>=m) j++;
          minc=min(minc,a);
          sum+=a;
          }
          if (j>=2) {cout<<0;return 0;}
         if (sum<=m){cout<<minc; return 0;} 
         int l,r; int inc=minc;
          l=1; r=min(m/n,inc);
        for(l=r;l>=1;--l){
            if (solve(l,minc)==1){
              break;
            }     
        }  
        cout<<l;
return 0;
}
