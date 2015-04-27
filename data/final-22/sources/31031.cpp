#include <cstdio>
#include <cstring>

#define zero(a) memset(a, 0, sizeof(a))
#define MaxV 500010
#define MaxE 800010


int d[MaxV];
int q[MaxV][13];
int tl[13];
int hd[13];
int head[MaxV];
int to[2 * MaxE];
int next[2 * MaxE];
int w[2 * MaxE];
int k = 0, x = 0;

void adde(int i, int j, int wt)
{
  next[k] = head[i];
  head[i] = k;
  to[k] = j;
  w[k] = wt;
  k++;
}


void push(int l, int k)
{
  tl[k] = (tl[k] + 1) % MaxV;
  q[tl[k] - 1][k] = l;
  x++;
}


int pop(int k)
{
  int m = q[hd[k]][k];
  hd[k] = (hd[k] + 1) % MaxV;
  x--;
  return m;
}


void bfs( void )
{
  q[0][0] = 0;
  zero(hd);
  zero(tl);
  tl[0] = 1;
  int v, k = 0;
  x = 1;
  while (x > 0)
  {
  //  printf("%i\n", k);
    if (hd[k] != tl[k])
    {
      v = pop(k);
    //  printf("!!!!%i\n", v);
      for (int a = head[v]; a != -1; a = next[a])
        if (d[to[a]] > d[v] + w[a])
        {
          push(to[a], (k + w[a]) % 13);
          d[to[a]] = d[v] + w[a];
      //    printf("%i ----> %i, %i, %i\n", v, to[a], w[a], d[to[a]]);

        }
    //  printf(">>%i\n", x);
    }
    else
      k = (k + 1) % 13;
  }
}




int main( void )
{
  int n, m;
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  scanf("%i %i", &n, &m);
  int s, q, wt;
  for (int i = 0; i < n; i++)
    head[i] = -1;
  for (int i = 0; i < m; i++)
  {
    scanf("%i%i%i", &s, &q, &wt);
    adde(s - 1, q - 1, 12 / wt);
    adde(q - 1, s - 1, 12 / wt);
  }
  d[0] = 0;
  for (int i = 1; i < n; i++)
    d[i] = MaxE;
  bfs();
  for (int i = 1; i < n; i++)
    printf("%.10lf\n", ((double)d[i]) / 12);
  return 0;
}



