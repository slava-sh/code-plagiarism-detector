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

char s[100];
vector<int> a[110000];
int pos[110000];
int first[110000];
int last[110000];
int can[110000];

int main()
{
  int i,j,m,n,x,has1,has2,tmp,lp,ln,fp,fn,cnt,lastt;
  vector<int> ans;
  vector<int> d;
  scanf("%d%d",&n,&m);
  for (i=0;i<n;i++)
  {
    a[i].clear();
    can[i]=1;
  }
  d.clear();
  for (i=0;i<m;i++)
  {
    scanf("%s",s);
    scanf("%d",&x);
    tmp=x;
    if (s[0]=='-') tmp=-tmp;
    d.push_back(tmp);
    x--;
    tmp=i+1;
    if (s[0]=='-') tmp=-tmp;
    a[x].push_back(tmp);
    //cout<<tmp<<endl;
  }
  memset(last,0,sizeof(last));
  memset(first,0,sizeof(first));
  memset(pos,0,sizeof(pos));
  lp=0;ln=0;fp=0;fn=0;
  for (i=0;i<n;i++)
    if (a[i].size()>0)
    {
      if (a[i][0]>0)
      {
        fp++;
        first[i]=1;
      }
      else
      {
        fn++;
        first[i]=-1;
      }
    }
  cnt=0;
  for (i=0;i<d.size();i++)
  {
    has1=0;
    if (lp>0) has1=1;
    if (fn>0) has1=1;
    if (has1==1) cnt++;
    x=abs(d[i])-1;
    if (first[x]==1) fp--;
    else if (first[x]==-1) fn--;
    if (last[x]==1) lp--;
    else if (last[x]==-1) ln--;
    last[x]=first[x];
    pos[x]++;
    if (pos[x]<a[x].size())
    {
      if (a[x][pos[x]]>0)
        first[x]=1;
      else if (a[x][pos[x]]<0)
        first[x]=-1;
    }
    else first[x]=0;

    if (first[x]==1) fp++;
    else if (first[x]==-1) fn++;
    if (last[x]==1) lp++;
    else if (last[x]==-1) ln++;

    has2=0;
    if (lp>0) has2=1;
    if (fn>0) has2=1;
    /*
    if ((has1==1)&&(d[i]>0))
      can[x]=0;
    if ((has2==1)&&(d[i]<0))
      can[x]=0;
    */
  }
  if (has2==1) cnt++;
  //cout<<cnt<<endl;
  for (i=0;i<n;i++)
  {
    lastt=0;tmp=0;
    for (j=0;j<a[i].size();j++)
      if (a[i][j]>0)
      {
        lastt=a[i][j];
      }
      else
      {
        tmp+=(-a[i][j]-lastt);
        lastt=-1;
      }
    if (lastt!=-1)
      tmp+=m+1-lastt;
    //cout<<i<<" "<<tmp<<endl;
    if (tmp>=cnt) can[i]=1;
    else can[i]=0;
  }
  ans.clear();
  for (i=0;i<n;i++)
    if (can[i]==1)
      ans.push_back(i+1);
  printf("%d\n",(int)ans.size());
  for (i=0;i<ans.size();i++)
    printf("%d ",ans[i]);
  printf("\n");
}
