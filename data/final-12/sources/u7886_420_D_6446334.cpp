#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

int d[5000000];
pair<int,int> dd[5000000];
int dy[1100000];
int used[1100000];
int next,n;

void add1(int x,int ll,int rr,int t,pair<int,int> p)
{
  int mid;
  if (rr==ll)
  {
    d[x]++;
    dd[x]=p;
    return;
  }
  mid=(ll+rr)/2;
  if (t<=mid) add1(x+x+1,ll,mid,t,p);
  else add1(x+x+2,mid+1,rr,t,p);
  d[x]++;
}

pair<int,int> get1(int x,int ll,int rr,int t)
{
  int mid;
  pair<int,int> p;
  if (ll==rr)
  {
    d[x]--;
    return dd[x];
  }
  mid=(ll+rr)/2;
  if (d[x+x+1]>=t) p=get1(x+x+1,ll,mid,t);
  else p=get1(x+x+2,mid+1,rr,t-d[x+x+1]);
  d[x]--;
  return p;
}

int main()
{
  int i,j,m,x,y;
  pair<int,int> p;
  scanf("%d%d",&n,&m);
  memset(dy,-1,sizeof(dy));
  memset(d,0,sizeof(d));
  for (i=0;i<n;i++)
  {
    add1(0,0,(1<<21),(1<<20)+i,make_pair(i,-1));
  }
  next=-1;
  for (i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    p=get1(0,0,(1<<21),y);
    if ((p.second!=-1)&&(p.second!=x))
    {
      printf("-1\n");
      return 0;
    }
    p.second=x;
    dy[p.first]=x;
    add1(0,0,(1<<21),(1<<20)+next,p);
    next--;
  }
  for (i=0;i<n;i++)
    if (dy[i]!=-1)
    {
      if (used[dy[i]]!=0)
      {
        printf("-1\n");
        return 0;
      } 
      used[dy[i]]=1;
    }
  j=1;
  for (i=0;i<n;i++)
  {
    if (dy[i]!=-1)
      printf("%d ",dy[i]);
    else
    {
      while (used[j]==1) j++;
      printf("%d ",j);
      j++;
    }
  }
  printf("\n");
}
