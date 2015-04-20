// vai bidzia 
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
long long n,m,a[1000001]={0}; 
int main(){ 
   //Freopen; 
   freopen("sochi.in","r",stdin); freopen("sochi.out","w",stdout); 
    cin>>n>>m;0 
    for (int k=1;k<=n;++k) 
       cin>>a[k]; 
       sort(a+1,a+n+1); 
       long long maxc=a[n]; long long s=a[n]; 
     for (int k=n-1;k>=1;--k){ 
         bool compiler=0; 
         if (a[k]-m<m) break; 
         s=s+a[k]-2*m; 
         maxc=s; 
     } 
     cout<<maxc; 
return 0; 
}
