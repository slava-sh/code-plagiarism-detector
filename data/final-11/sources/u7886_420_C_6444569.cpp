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

vector<int> d[400000];
int cnt[400000];
int dd[400000];
int a[400000][2];

int main()
{
  int i,j,n,p,tmp;
  _int64 ans;
  memset(cnt,0,sizeof(cnt));
  scanf("%d%d",&n,&p);
  for (i=0;i<n;i++)
    d[i].clear();
  for (i=0;i<n;i++)
  {
    scanf("%d%d",&a[i][0],&a[i][1]);
    a[i][0]--;
    a[i][1]--;
    d[a[i][0]].push_back(a[i][1]);
    d[a[i][1]].push_back(a[i][0]);
    cnt[a[i][0]]++;
    cnt[a[i][1]]++;
  }
  for (i=0;i<n;i++)
    dd[cnt[i]]++;
  for (i=n;i>=0;i--)
  {
    dd[i-1]+=dd[i];
  }
  ans=0;
  for (i=0;i<n;i++)
  {
    for (j=0;j<d[i].size();j++)
    {
      dd[cnt[d[i][j]]]--;
      cnt[d[i][j]]--;
      //dd[cnt[d[i][j]]]++;
    }
    tmp=p-cnt[i];
    if (tmp<0) tmp=0;
    ans+=dd[tmp];
    if (cnt[i]>=tmp) ans--;
    //cout<<i<<" "<<dd[p-cnt[i]]<<endl;
    for (j=0;j<d[i].size();j++)
    {
      //dd[cnt[d[i][j]]]--;
      cnt[d[i][j]]++;
      dd[cnt[d[i][j]]]++;
    }
  }
  cout<<ans/2<<endl;
}

