#include <cstdio>
#include <cstring>
#include <vector>

#define maxn 500010
#define maxv 800000

using namespace std;

int V, E;
int beg[13];
int end[13];
int queu[400000][13];
int d[maxn];
int used[maxn];
int to[maxv * 2];
int head[maxn];
int next[maxv * 2];
int w[maxv * 2];
int k = 0;

void adde(int i, int j, int wt)
{
  next[k] = head[i];
  head[i] = k;
  to[k] = j;
  w[k] = wt;
  k++;
}

void bfs ()
{
  int u, i, t1, t2, t3;
  int k = 0;
  int e = 1;
  while (e != 0)  
  {
    while (beg[k] < end[k])
    {               
      u = queu[beg[k]][k]; 
      used[u] = 1;
      for (int j = head[u]; j != -1; j = next[j])
      {
        t1 = d[u] + w[j];
        t2 = (k + w[j]) % 13;
        t3 = to[j];
        if (d[t3] > t1)
        {
          d[t3] = t1;
          if (!used[t3])
          {
            queu[end[t2]++][t2] = t3;
            e++;
          }
        }
      }
      e--;
      beg[k]++;
    }
    k++;
    k %= 13;
  }
}

int main (void)
{
  int a, b, c;
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  memset (head, -1, sizeof(head));
  scanf ("%d%d", &V, &E);
  for (int i = 0; i < E; i++)
  {
    scanf ("%d%d%d", &a, &b, &c);
    a--, b--;
    c = 12 / c;
    adde (a, b, c);
    adde (b, a, c);
  }
  queu[0][0] = 0;
  end[0] = 1;
  memset(d, 60, sizeof(d));
  d[0] = 0;
  bfs();
  for (int i = 1; i < V; i++)
    printf ("%.10lf\n", double(d[i]) / 12.0);
  return 0;
}