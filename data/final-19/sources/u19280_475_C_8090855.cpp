#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <iostream>

#define mp make_pair
#define pb push_back
#define sz size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define F first
#define S second
#define REP(i,a,n) for(i=a;i<=n;i++)
#define big long long

using namespace std;

int sum[1005][1005],a[1005][1005],N,M,i,j,l,u,ys,xs,gavi,n,m,sul,x,y,ans=1234567890;
string s;

void go(int x,int y)
{
    if (sum[x+N-1][y+M]-sum[x+N-1][y+M-1]-sum[x-1][y+M]+sum[x-1][y+M-1]==N)
     { gavi+=N;
       go(x,y+1);
     } else
    if (sum[x+N][y+M-1]-sum[x+N-1][y+M-1]-sum[x+N][y-1]+sum[x+N-1][y-1]==M)
    { gavi+=M;
      go(x+1,y);
    } 
}

main()
{
     cin>>n>>m;
      
      REP(i,1,n)
       {
         cin>>s;
          
         for (j=1;j<=m;j++)
          {
            if(s[j-1]=='X') {a[i][j]=1; sul++;}
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
          }
       }
       for (i=1;i<=n;i++)
         {
        for (j=1;j<=m;j++)
         if (a[i][j]==1) break;
         if (j<=m) break;
         }
         x=i;y=j;
         
         i=0;
          while (a[x][y+i]==1) i++;
           ys=i; 
        
        i=0;
         while (a[x+i][y]==1) i++;
         xs=i;
          
          for (i=1;i<=xs;i++)
           {
             M=ys;
             N=i;
                gavi=N*M;
             go(x,y);
             if (gavi==sul)
              {
                ans=min(ans,N*M);
                break;
              }
           }       
         
         for (i=1;i<=ys;i++)
          {
            M=i;
            N=xs;
             gavi=N*M;
             go(x,y);
             if (gavi==sul)
              {
                ans=min(ans,N*M);
                break;
              }
          }
          
          if (ans==1234567890) ans=-1;
          
          cout<<ans<<endl;
     
}