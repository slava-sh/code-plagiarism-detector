#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int NN = 2*(int)(1e5) + 7;
int qa[NN + 7], qb[NN + 7];
int a, b;
vector<int> v[NN];
int lvla[NN];
int lvlb[NN];
vector<int> w;

bool la(int u, int pr)
{
  int ma = 0;
  bool ret = false;
  for (int i = 0; i < (int)v[u].size(); i++)
  {
    if (pr != v[u][i])
    {
      bool tre = la(v[u][i], u);
      if (!ret)
        ret = tre;
      if (ma < lvla[v[u][i]] + 1)
        ma = lvla[v[u][i]] + 1;
    }
  }
  lvla[u] = ma;
  if (v[u].size() <= 1 && u != a)
    lvla[u] = 0;
  if (u == b)
    ret = true;
  if (ret)
    w.push_back(u);
  return ret;
}

void lb(int u, int pr)
{
  int ma = 0;
  for (int i = 0; i < (int)v[u].size(); i++)
  {
    if (pr != v[u][i])
    {
      lb(v[u][i], u);
    
      if (ma < lvlb[v[u][i]] + 1)
        ma = lvlb[v[u][i]] + 1;
    }
  }
  lvlb[u] = ma;
  if (v[u].size() == 1 && u != b)
    lvlb[u] = 0;
} 

int main()
{
  freopen("dwarfs.in", "r", stdin);
  freopen("dwarfs.out", "w", stdout);

  int n;
  scanf("%d", &n);
 // cout << n << endl;
   
  for (int i = 0; i < n - 1; i++)
  {
     
     scanf("%d%d", &a, &b);
   //  cout << a << " " << b << " " << endl;
     a--;
     b--;
    // cout << a << " " << b << " " << endl;
     v[a].push_back(b);
     v[b].push_back(a);
     //cout << "****" << endl;
  }  
 
  scanf("%d%d", &a, &b);
  a--; b--;
  
  la(a, -1);
  
  lb(b, -1);
  int ma, mb;
 // w.push_back(a);
 // for (int i = 0; i < (int)w.size(); i++)
 //   cout << "W: " << w[i] << "* " << endl;
  for (int i = 0; i < (int)v[a].size(); i++)
  {
    ma = 0;
    if (v[a][i] != w[(int)w.size() - 1])
    {
      ma = max(ma, lvla[v[a][i]] + 1);
        //   cout << v[a][i] << " " << lvla[v[a][i]] << endl;
          // cout << ma << endl;
    }
  }
 // cout << ma << endl;
  for (int i = 0; i < (int)v[b].size(); i++)
  {
    mb = 0;
    if (v[b][i] != w[1])
    {
      mb = max(mb, lvlb[v[b][i]] + 1);
     // cout << v[b][i] << " " << lvlb[v[b][i]] << endl;
    }
  }

  //cout << "ma " << ma << " mb " << mb << endl;

  
  qb[0] = mb;
  for (int i = 1; i < (int)w.size() - 1; i++)
  {
    int u = w[i];
    int M = 0;
    for (int j = 0; j < (int)v[u].size(); j++)
    {
      if (v[u][j] != w[i - 1] && v[u][j] != w[i + 1] && M < lvlb[v[u][j]] + i + 1)
        M = lvlb[v[u][j]] + i + 1;
   //   cout << (lvlb[v[u][i]] + i) + 1 << endl;      
    }
    qb[i] = M;
  //  cout << "qb[" << i << "] =  " << qb[i] << endl << endl;
  }

  qa[(int)w.size() - 1] = ma;
  for (int i = (int)w.size() - 2; i >= 1; i--)
  {
    int u = w[i];
    int M = 0;
    for (int j = 0; j < (int)v[u].size(); j++)
    {
      if (v[u][j] != w[i - 1] && v[u][j] != w[i + 1] && M < lvla[v[u][j]] + (int)w.size() - i + 1)
        M = lvla[v[u][j]] + (int)w.size() - i + 1;        
    }
    qa[i] = M;
  }
  int ans = 0;
  for (int i = 0; i < (int)(w.size() - 1); i++)
  {
    int w = min(qb[i], qa[i + 1]);
    if (w > ans)
      ans = w;
  }
  printf("%d", ans + 1);

  return 0;
}

