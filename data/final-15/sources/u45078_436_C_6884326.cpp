#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<string> fields[1000];

int d[1000][1000];
const int INF = 1000000000;

vector<pair<int, int> > answer;
int total_answer = 0;
vector<int> printed;
int k;

void dfs(int v, int p)
{
  answer.push_back(make_pair(v + 1, p + 1));
  printed[v] = 1;
  for (int i = 0; i < k; ++i)
  {
    if (i !=p && i!= v && d[v][i] != INF)
    {
      dfs(i, v);
      total_answer += d[v][i];
    }
  }
}

int main()
{
  int n, m, w;
  cin >> n >> m >> k >> w;

  for (int i = 0; i < k; ++i)
  {
    fields[i].resize(n);
    for (int j = 0; j < n; ++j)
      cin >> fields[i][j];
  }


  for (int i = 0; i < k; ++i)
  {
    for (int j = i + 1; j < k; ++j)
    {
      int diff = 0;
      for (int p = 0; p < n; ++p)
        for (int u = 0; u < m; ++u)
        if (fields[i][p][u] != fields[j][p][u])
          ++diff;

      if (diff * w < n * m)
        d[i][j] = d[j][i] = diff * w;
      else
        d[i][j] = d[j][i] = INF;
    }
  }
  set<pair<int, int> > mst;
  vector<bool> used (k);

  while (true)
  {
    int start = -1;
    for (int i = 0; i < k; ++i)
    {
      if (used[i] == 0)
      {
        start = i;
        break;
      }
    }

    if (start == -1)
      break;

    vector<int> min_e (k, INF), sel_e (k, -1);
    min_e[start] = 0;
    for (int i=0; i<k; ++i)
    {
      int v = -1;
      for (int j=0; j<k; ++j)
        if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
          v = j;
      if (v == -1 || min_e[v] == INF) {
        break;
      }

      used[v] = true;
      if (sel_e[v] != -1)
        mst.insert(make_pair(std::min(v, sel_e[v]), std::max(v, sel_e[v])));

      for (int to=0; to<k; ++to)
        if (d[v][to] < min_e[to]) {
          min_e[to] = d[v][to];
          sel_e[to] = v;
        }
    }
  }

  for (int i = 0; i < k; ++i)
    for (int j = i + 1; j < k; ++j)
    {
      if (mst.find(make_pair(i, j)) == mst.end())
        d[i][j] = d[j][i] = INF;
    }

  answer.reserve(k);
  printed.resize(k, 0);

  for (int i = 0; i < k; ++i)
  {
    if (printed[i])
      continue;

    dfs(i, -1);
    total_answer += n * m;
  }

  printf("%d\n", total_answer);

  for (int i = 0; i < answer.size(); ++i)
  {
    printf("%d %d\n", answer[i].first, answer[i].second);
  }

  //vector<int> res;
  //res.resize(k);
  //vector<int> bests;
  //bests.resize(k);
  //vector<int> parents;
  //parents.resize(k);

  //res[0] = 0;
  //bests[0] = n * m;
  //parents[0] = -1;
  //int cur_total = n * m;

  //for (int i = 1; i < k; ++i)
  //{
  //  vector<pair<int, int> > lefts;
  //  lefts.resize(i + 1);
  //  lefts[0].first = n * m;
  //  lefts[0].second = -1;
  //  for (int j = 1; j <= i; ++j)
  //  {
  //    if (d[i][res[j-1]] < lefts[j-1].first)
  //    {
  //      lefts[j].first = d[i][res[j-1]];
  //      lefts[j].second = res[j-1];
  //    }
  //    else
  //      lefts[j] = lefts[j-1];
  //  }

  //  vector<int> rights;
  //  rights.resize(i + 1);
  //  rights[i] = 0;
  //  for (int j = i - 1; j >= 0; --j)
  //  {
  //    rights[j] = rights[j+1];
  //    if (d[i][res[j]] < bests[j])
  //    {
  //      rights[j] += bests[j] - d[i][res[j]];
  //    }
  //  }

  //  int best_pos = 0;
  //  int best_res = cur_total + n * m - rights[0];

  //  for (int j = 1; j <= i; ++j)
  //  {
  //    int pos_res = cur_total + lefts[j].first - rights[j];
  //    if (pos_res < best_res)
  //    {
  //      best_pos = j;
  //      best_res = pos_res;
  //    }
  //  }

  //  for (int j = best_pos; j < i; ++j)
  //  {
  //    if (d[res[j]][i] < bests[j])
  //    {
  //      bests[j] = d[res[j]][i];
  //      parents[j] = i;
  //    }
  //  }

  //  vector<int>::iterator it = res.begin() + best_pos;
  //  res.insert(it, i);
  //  it = bests.begin() + best_pos;
  //  bests.insert(it, lefts[best_pos].first);
  //  it = parents.begin() + best_pos;
  //  parents.insert(it, lefts[best_pos].second);
  //  cur_total = best_res;
  //}

  //cout << cur_total << '\n';

  //for (int i = 0; i < k; ++i)
  //{
  //  cout << res[i] + 1 << ' ' << ((parents[i] == -1) ? 0 : parents[i] + 1) << '\n';
  //}

  return 0;
}