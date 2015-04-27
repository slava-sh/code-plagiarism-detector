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

const int MAXT = 1 << 22,MAXN = 1001000;
struct seg_tree
{
  int sum[MAXT],len;
  void build(int n)//Index 0..n-1
  {
    for(len = 1; len < n; len <<= 1);
  }
  template<int val>
  void update(int pos)
  {
    for(int x = pos + len; x > 0; x >>= 1)
      sum[x] += val;
  }
  int find(int k)
  {
    int x;
    for(x = 1; x < len; )
      {	
	x <<= 1;
	if (sum[x] < k)
	  {
	    k -= sum[x];
	    x ^= 1;
	  }
      }
    return x - len;
  }
} ds;
int pos[MAXT],val[MAXN];
bool app[MAXN];

int main() 
{
  int n,m;
  scanf("%d%d",&n,&m);

  ds.build(n + m); //Index [0,n+m)
  for(int i = 0; i < n; i++)
    {
      pos[m + i] = i;
      ds.update<1>(m + i);
    }
  memset(val,-1,sizeof(val));

  bool flag = true;
  for(int i = m-1; i >= 0; i--)
    {
      int k,mark;
      scanf("%d%d",&mark,&k);
      
      int p = ds.find(k),op = pos[p];
      ds.update<-1>(p);
      pos[i] = op;
      ds.update<1>(i);

      if ( val[op] == -1 ) val[op] = mark;
      else if ( val[op] != mark )
	{
	  flag = false;
	  break;
	}
    }

  memset(app,false,sizeof(app));
  for(int i = 0; i < n; i++) 
    if (val[i] != -1)
    {
      if (app[val[i]])
	{
	  flag = false;
	  break;
	}
      app[val[i]] = true;
    }

  if (flag)
    {
      for(int i = 0,v = 1; i < n; i++)
	{
	  if (val[i] == -1)
	    {
	      for(; app[v]; ++v);
	      app[v] = true;
	      val[i] = v;
	    }

	  if (i == n - 1) printf("%d\n",val[i]);
	  else printf("%d ",val[i]);
	}
    }
  else
    puts("-1");
  return 0;
}
