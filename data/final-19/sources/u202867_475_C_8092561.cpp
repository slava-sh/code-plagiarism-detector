#include<cstdio>
#include<iostream>
using namespace std;
#define sum(x1,y1,x2,y2) (H[x2][y2]-H[x1-1][y2]-H[x2][y1-1]+H[x1-1][y1-1])
int n,m;
char c[1005][1005];
int H[1005][1005];
int ans=1000000000;

int DFS(int x,int y,int wx,int wy)
{
  if(sum(x,y+1,x+wx-1,y+wy)==wx*wy)return wx+DFS(x,y+1,wx,wy);
  if(sum(x+1,y,x+wx,y+wy-1)==wx*wy)return wy+DFS(x+1,y,wx,wy);
  return 0;
}

int main()
{
  scanf("%d%d\n",&n,&m);
  int flag=0,px,py;
  for(int i=1;i<=n;i++)
    gets(c[i]+1);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
      if(c[i][j]=='X')
      {
        if(!flag){flag=1;px=i;py=j;}
        H[i][j]=H[i-1][j]+H[i][j-1]-H[i-1][j-1]+1;
      }
      else H[i][j]=H[i-1][j]+H[i][j-1]-H[i-1][j-1];
    }
  int tmp,wx,wy;
  for(tmp=px;c[tmp][py]=='X';tmp++);
  wx=tmp-px;
  for(int i=py;c[px][i]=='X';i++)
    if(DFS(px,py,wx,i-py+1)+wx*(i-py+1)==H[n][m])ans=min(ans,wx*(i-py+1));
  for(tmp=py;c[px][tmp]=='X';tmp++);
  wy=tmp-py;
  for(int i=px;c[i][py]=='X';i++)
    if(DFS(px,py,i-px+1,wy)+(i-px+1)*wy==H[n][m])ans=min(ans,(i-px+1)*wy);
  if(ans<=n*m)cout<<ans<<endl;
  else cout<<-1<<endl;
  return 0;
}