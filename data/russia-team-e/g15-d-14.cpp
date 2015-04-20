//Giorgi Kldiashvili 
#include <iostream> 
#include <stdio.h> 
#include <math.h> 
#include <iomanip> 
#include <algorithm> 
#include <vector> 
#include <map> 
#include <queue> 
#include <utility> 
#include <string> 
#define INF 2147483647 
#define Pi 3.14159265358 
#define mod9 %1000000009 
#define mod7 %1000000007 
#define ll long long 
#define time clock()/(double)CLOCKS_PER_SEC 
#define Freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout) 
using namespace std; 
struct name{ 
   int x,y;     
}; 
bool comp(name a,name b){ 
    return a.x>b.x;  
}; 
ll n,m,a[100001]={0}; 
bool solve (ll k,ll minc){ 
      int b=minc;
    for (int i=2;i<=n;++i){
         if (a[i]<m){
         b+=max(k,a[i]-a[i-1]);
         if (b>m) return 0;  }
         else {
            if (i==n && m-b>=k)
              return 1;
              else return 0;  
         }
    }  
     return 1;
} 
int main(){ 
  // Freopen; 
   freopen("fence.in","r",stdin); 
   freopen("fence.out","w",stdout); 
  cin>>n>>m;  
     ll minc=INF,maxc=0,sum=0; 
     ll j=0; 
     for (int k=1;k<=n;++k){  
          cin>>a[k]; 
          if (a[k]>=m) j++; 
          minc=min(minc,a[k]); 
          sum+=a[k]; 
          } 
         sort(a+1,a+n+1);
          if (j>=2) {cout<<0;return 0;} 
         if (sum<=m){cout<<minc; return 0;}  
         ll l,r; ll inc=minc; 
          l=1; r=min(m/n,inc);
        for(l=r;l>=1;--l){ 
            if (solve(l,minc)==1){ 
              break; 
            }      
        }   
        cout<<l; 
        return 0;
}
