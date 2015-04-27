#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cerr<<#x<<":"<<x<<"\n"
#define lim 1010
#define inf 1000000000
int n,m,i,j,z,s,sx,sy,mn,h,w,x,y;
char A[lim][lim];
int S[lim][lim];
int move(int x1,int y1)
{
  int x2,y2;
  x2=x1+h-1;
  y2=y1+w-1;
  return S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1]==w*h;
}
int main()
{
  scanf("%d%d",&n,&m);
  sx=-1;
  for(i=1;i<=n;i++)
  {
    scanf("%s",A[i]);
    for(j=m;j>0;j--)
      A[i][j]=A[i][j-1];
    for(j=1;j<=m;j++)
    {
      z+=A[i][j]=='X';
      S[i][j]=(A[i][j]=='X')+S[i][j-1]+S[i-1][j]-S[i-1][j-1];
      if( A[i][j]!='.' && sx==-1)
      {
        sx=i;
        sy=j;
      }
    }
  }
  mn=inf;
  h=1;
  for(w=1;move(sx,sy);w++);
  w--;
  for(h=1;h<=n;h++)
  {
    x=sx;
    y=sy;
    if(!move(x,y))
      break;
    s=w*h;
    while(1)
      if(move(x,y+1))
      {
        s+=h;
        y++;
      }
      else if(move(x+1,y))
      {
        s+=w;
        x++;
      }
      else
        break;
    if(s==z)
      mn=min(mn,w*h);
  }

  
  w=1;
  for(h=1;move(sx,sy);h++);
  h--;
  for(w=1;w<=m;w++)
  {
    x=sx;
    y=sy;
    if(!move(x,y))
      break;
    s=w*h;
    while(1)
      if(move(x,y+1))
      {
        s+=h;
        y++;
      }
      else if(move(x+1,y))
      {
        s+=w;
        x++;
      }
      else
        break;
    if(s==z)
      mn=min(mn,w*h);
  }

  if(mn==inf)
    mn=-1;
  printf("%d\n",mn);
	return 0;
}
