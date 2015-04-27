/* In the Name of God */
#include <iostream>
#include <set>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include<cstdio>
#define lch(r) (2*(r)+1)
#define rch(r) (2*(r)+2) 
#define inf (1<<30)
#define F first
#define S second
#define mod 1000000007
using namespace std;
typedef   long long ll;
typedef long double ld;
typedef pair<int  ,int  > pii;
const int   MAXN = 100000+10;
char c[11][11][1001];
int ted[1001][1001] , mted[1001] , nted[1001];
int n,m,k,w;
int d(int  x , int  y )
{
     
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
          if(c[i][j][x]!=c[i][j][y])
           ted[x][y]+=w;
           if(ted[x][y]<mted[x])
             {
                mted[x]=ted[x][y];
                nted[x]=y;
             }
       ted[y][x]=ted[x][y];
       swap(x,y);
        if(ted[x][y]<mted[x])
                     {
                        mted[x]=ted[x][y];
                        nted[x]=y;
                     }
}
vector<int>ans;
int ans1=0;
int anss[1001], mark[1001];
int check()
{
        
        for(int i=1;i<=k;i++)
        if(mark[i]==0)
              if(mark[nted[i]] == 1)
              {
                        ans.push_back(i);
                        anss[i]=nted[i];
                        mark[i]=1;
                        ans1+=ted[i][nted[i]];
                        return 1;   
              }
              return 0;
}
int fin()
{
        int x   , y=mod;
        for(int i=1;i<=k;i++)
        if(mark[i]==0)
                x=i;
         for(int i=1;i<=k;i++)
          if(mark[i]==0)
          {
                for(int j=0;j<ans.size();j++)
                 if(ted[i][ans[j]] < y)
                 {
                        y=ted[i][ans[j]];
                        x=i;
                 }
          }  
          return x;
}
int main()
{
   ios_base::sync_with_stdio(false);
    
       cin>>n>>m>>k>>w;
       for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
         for(int h=1;h<=m;h++)
          cin>>c[j][h][i];
          
      for(int i=1;i<=k;i++)
        mted[i]= mod;
        
      for(int i=1;i<=k;i++)
       for(int j=i+1;j<=k;j++)
        d(i,j);
   
        for(int i=1;i<=k;i++)
              if(mted[i] >= m*n)
              {
                        mark[i]=1;
                        ans.push_back(i);
                        ans1+=m*n;
               }
               int t=0;                            
             while(check())
                  t++; 
             while(ans.size()<k)
             {
                        int i = fin();        
                        int x=0 , p=n*m;
                        for(int j=0;j<ans.size();j++)
                         if(ted[i][ans[j]] <p)
                        {
                          x=ans[j];
                                p=ted[i][ans[j]];
                        }
                      
                         ans1+=p;
                        mark[i]=1;
                        ans.push_back(i);
                        anss[i]=x;
                              while(check()) 
                               t++;
                
              }       
                cout<<ans1<<endl;  
           for(int i=0;i<ans.size();i++)
            cout<<ans[i] <<' '<<anss[ans[i]] <<endl;     
}
 
