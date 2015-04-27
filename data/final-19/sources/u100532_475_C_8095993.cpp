/*************************************************************************
    > File Name: CC.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年10月05日 星期日 23时26分56秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
/*Let's fight!!!*/

#define sum(x1,y1,x2,y2) (G[x2][y2]-G[x1-1][y2]-G[x2][y1-1]+G[x1-1][y1-1])

int n,m,G[1005][1005],ans=1000000000;
char str[1005][1005];
bool vis[1005][1005];

int dfs(int x,int y,int wx,int wy)
{
  	vis[x][y] = true;
    if(sum(x,y+1,x+wx-1,y+wy)==wx*wy) return wx+dfs(x,y+1,wx,wy);
    if(sum(x+1,y,x+wx,y+wy-1)==wx*wy) return wy+dfs(x+1,y,wx,wy);
    return 0;
}

int main()
{
  	memset(vis, false, sizeof(vis));
    scanf("%d%d\n",&n,&m);
    int flag=0,px,py;
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='X')
            {
                if(!flag) {flag=1;px=i;py=j;}
                G[i][j]=G[i-1][j]+G[i][j-1]-G[i-1][j-1]+1;
            }
            else G[i][j]=G[i-1][j]+G[i][j-1]-G[i-1][j-1];
        }
    int tmp,wx,wy;
    for(tmp=px;str[tmp][py]=='X';tmp++);
    wx=tmp-px;
    for(int i=py;str[px][i]=='X';i++)
        if(dfs(px,py,wx,i-py+1)+wx*(i-py+1)==G[n][m])ans=min(ans,wx*(i-py+1));
    for(tmp=py;str[px][tmp]=='X';tmp++);
    wy=tmp-py;
    for(int i=px;str[i][py]=='X';i++)
        if(dfs(px,py,i-px+1,wy)+(i-px+1)*wy==G[n][m])ans=min(ans,(i-px+1)*wy);

    if(ans<=n*m) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
