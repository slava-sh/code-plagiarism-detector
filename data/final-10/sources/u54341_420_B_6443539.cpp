#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

typedef long long ll;
const int INF = (1 << 30) - 1;
const ll lINF = (1LL << 62) - 1;
const double dINF = 1e40;

const int MAXN = 101000;
bool app[MAXN],inValid[MAXN];
pair<char,int> d[MAXN];


int main() 
{
  int n,m;
  scanf("%d%d",&n,&m);
  memset(app,false,sizeof(app));
  
  int cnt = 0,v;
  for(int i = 0; i < m; i++)
    {
      scanf(" %c%d",&d[i].first,&d[i].second);
      if ( d[i].first == '-' && !app[ d[i].second ] ) 
	{
	  ++cnt;
	  v = d[i].second;
	}

      app[ d[i].second ] = true;
    }

  if (cnt == 0) v = d[0].second;

  bool flag = true,valid = true;
  for(int i = 0; i < m; i++)
    {
      if (d[i].first == '+') ++cnt;
      else --cnt;

      if (d[i].second == v)
	{
	  flag = d[i].first == '+';
	}
    
      if (!flag && cnt > 0) 
	{
	  valid = false;
	}
    }
  

  int c = 0;
  for(int i = 1; i <= n; i++) if (!app[i] || (i == v && valid)) ++c;
  printf("%d\n",c);

  if (c)
    {
      for(int i = 1; i <= n; i++) if (!app[i] || (i == v && valid)) printf("%d ",i);
      printf("\n");
    }
  return 0;
}
