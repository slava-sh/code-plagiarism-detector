#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 201
#define lim2 lim*lim

int sh,st,r,n,i,h,t,h2,t2,x,z,k,m,s;
bool f;
int H1[lim],T1[lim],H2[lim],T2[lim];
queue <int> Q;
int H[lim][lim],M[lim2],D[lim2],P[lim2],S[lim2],T[lim2];
vector <int> V[lim2];

void push(int x,int y)
{
  if(D[x]==-1)
  {
    D[x]=D[y]+1;
    P[x]=y;
    Q.push(x);
  }
  else
    if(!f)
    {
      while(y!=x && P[y]!=y)
        y=P[y];
      f=x==y;
    }
}
int solve(int i)
{
  int &res=M[i],j;
  
  if(res==-1)
  {
    res=0;
    for(j=0;j<S[i];j++)
      res=max(res,solve(V[i][j]));
    res++;
    //printf("*%d %d\n",i,res);
  }
  return res;
}
int main()
{
  scanf("%d%d%d",&sh,&st,&r);
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    scanf("%d%d",&H1[i],&T1[i]); 
  scanf("%d",&m);
  for(i=1;i<=m;i++)
    scanf("%d%d",&H2[i],&T2[i]); 
  for(h=0;h<=r;h++)
    for(t=0;h+t<=r;t++)
      H[h][t]=z++;
  for(h=0;h<=r;h++)
    for(t=0;h+t<=r;t++)
    {
      for(k=1;k<=min(h,n);k++)
      {
        h2=h-k+H1[k];
        t2=t+T1[k];
        if(h2+t2<=r)
        {
          V[H[h][t]].push_back(H[h2][t2]);
          S[H[h][t]]++;
        }
      }
      for(k=1;k<=min(t,m);k++)
      {
        h2=h+H2[k];
        t2=t-k+T2[k];
        if(h2+t2<=r)
        {
          V[H[h][t]].push_back(H[h2][t2]);
          S[H[h][t]]++;
        }
      }
    }
  memset(D,-1,sizeof D);
  s=H[sh][st];
  D[s]=0;
  Q.push(s);
  P[s]=s;
  z=0;
  while(!Q.empty())
  {
    x=Q.front();
    T[z++]=x;
    //printf(" %d %d\n",x,P[x]);
    Q.pop();
    for(i=0;i<S[x];i++)
      push(V[x][i],x);
  }
  if(D[0]==-1)
    if(f)
      printf("Draw\n");
    else
    {
      memset(M,-1,sizeof M);
      while(--z>=0)
        solve(T[z]);
      printf("Zmey\n%d\n",solve(s));
    }
  else
    printf("Ivan\n%d",D[0]);
  return 0;
}
