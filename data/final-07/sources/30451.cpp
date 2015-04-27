#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
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

pair<int,int> a[300000];

int n,nn;

void solve(int x,int y)
{
  set<int> st;
  int i,xx,tmp;
  if (x>=y) return;
  xx=a[(x+y)/2].first;
  //printf("%d\n",xx);
  st.clear();
  for (i=x;i<=y;i++)
    if (a[i].first!=xx)
      st.insert(a[i].second);
  for (i=x;i<=y;i++)
    if (a[i].first==xx)
      st.erase(a[i].second);
  for (set<int>::iterator it=st.begin();it!=st.end();it++)
  {
    a[nn].first=xx;
    a[nn].second=(*it);
    nn++;
  }
  tmp=(x+y)/2;
  while ((tmp>=x)&&(a[tmp].first==xx)) tmp--;
  solve(x,tmp);
  tmp=(x+y)/2;
  while ((tmp<=y)&&(a[tmp].first==xx)) tmp++;
  solve(tmp,y);
}

int main()
{
  int i,j;
  scanf("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  nn=n;
  solve(0,n-1);
  printf("%d\n",nn);
  for (i=0;i<nn;i++)
    printf("%d %d\n",a[i].first,a[i].second);
}
