#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(a) (int)a.size()
#define zero(a) memset (a, 0, sizeof(a))
#define mp make_pair

const int maxn = 200000;

struct my 
{
  int val, count;
  my(){}
  my (int v, int c)
  {
    val = v, count = c;
  }
};
int sz = 0;
int m[maxn];
int n;

bool operator < (const my &a, const my &b)
{
  if (a.count == b.count)
    return a.val < b.val;
  return a.count > b.count;
}

set <my> p;

int res = 0;
int ans[maxn][3];
int a[3];

int r[maxn];

int main (void)
{
  #ifdef LOCAL
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
  #endif

  scanf (" %d", &n);

  for (int i = 0; i < n; i++)
    scanf ("%d", &r[i]);

  sort (r, r + n);

  for (int i = 0; i < n;)
  {
    int st = i;
    my tmp (r[i], 0);
    while (r[i] == r[st] && i < n)
      i++, tmp.count++;
    p.insert(tmp);
  }
  /*
  for (int i = 0; i < n; i++)
  {
    if (p.empty() || (--p.end())->val != r[i])
      p.insert(my(r[i], 1));
    else
    {
      my tp = *(--p.end());
      p.erase(--p.end());
      tp.count++;
      p.insert(tp);
    }
  }
  */
//  for (set<my>::iterator i = p.begin(); i != p.end(); i++)
//    printf ("%d ", i->val);

  while (p.size() >= 3)
  {
    set<my>::iterator i, j, k;

    i = p.begin();
    j = (++i), i--;
    k = (++j), j--;

    a[0] = i->val;
    a[1] = j->val;
    a[2] = k->val;
    //cerr<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    my tmp1 = *i;
    my tmp2 = *j;
    my tmp3 = *k;
    p.erase(tmp1);
    tmp1.count--;
    if (tmp1.count)
      p.insert(tmp1);
    p.erase(tmp2);
    tmp2.count--;
    if (tmp2.count)
      p.insert(tmp2);
    p.erase(tmp3);
    tmp3.count--;
    if (tmp3.count)
      p.insert(tmp3);
    sort(a, a + 3);
    reverse(a, a + 3);
    res++;
    for (int l = 0; l < 3; l++)
      ans[res - 1][l] = a[l];
  }

  printf ("%d\n", res);

  for (int i = 0; i < res; i++, puts(""))
    for (int j = 0; j < 3; j++)
      printf ("%d ", ans[i][j]);

  return 0;
}

