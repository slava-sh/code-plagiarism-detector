#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int SUM,sum[1005][1050],q[1005][1005],n,m,xx,yy,i,j,ans,X,Y;
char s[1005][1005];
bool OK(int x,int y,int A,int B)
{
    if (sum[x][y]-sum[x][y-B]-sum[x-A][y]+sum[x-A][y-B]!=A*B) return false;
    int sum1=A*B;
    while (1)
    {
        if (x<=n && sum[x+1][y]-sum[x+1][y-B]-sum[x-A+1][y]+sum[x-A+1][y-B]==A*B)
        {
            x++;
            sum1+=B;
        } else
        if (y<=m && sum[x][y+1]-sum[x][y-B+1]-sum[x-A][y+1]+sum[x-A][y-B+1]==A*B)
        {
            y++;
            sum1+=A;
        } else break;
    }
    return (sum1==SUM);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%s",s[i]);
    for (i=1; i<=n; i++)
      for (j=1; j<=m; j++)
        if (s[i-1][j-1]=='X')
        {
            sum[i][j]=q[i][j]=1;
            if (X==0) {X=i; Y=j;}
            SUM++;
        }
    for (i=1; i<=n; i++)
      for (j=1; j<=m; j++)
        sum[i][j]+=sum[i-1][j];
    for (i=1; i<=n; i++)
       for (j=1; j<=m; j++)
         sum[i][j]+=sum[i][j-1];
    for (i=X; i<=n; i++) if (q[i][Y]==0) break;
    xx=i-X;
    for (i=Y; i<=m; i++) if (q[X][i]==0) break;
    yy=i-Y; ans=453266144;
    for (i=1; i<=yy; i++)
    {
        if (OK(X+xx-1,Y+i-1,xx,i)) ans=min(ans,i*xx);
    }
    for (i=1; i<=xx; i++)
      if (OK(X+i-1,Y+yy-1,i,yy)) ans=min(ans,i*yy);
    if (ans==453266144) cout<<-1; else cout<<ans;
    return 0;
}
