/*
 * c.cpp
 *
 *  Created on: Jun 13, 2014
 *      Author: istrandjev
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define mpair make_pair
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

const std::string PROGRAM_NAME = "ivo";

struct edge {
  int from, to;
  int len;
};

class DSF {
public:
  DSF(int _n)
      : n(_n), dad(_n), rank(_n, 0) {
    for (int i = 0; i < (int)dad.size(); ++i) {
      dad[i] = i;
    }
  }

  int component(int a) {
    vector<int> sta;
    while (dad[a] != a) {
      sta.push_back(a);
      a = dad[a];
    }

    for (int i = 0; i < (int)sta.size(); ++i) {
      dad[sta[i]] = a;
    }

    return a;
  }

  pair<int, bool> merge(int a, int b) {
    vector<int> sta, stb;
    while (dad[a] != a) {
      sta.push_back(a);
      a = dad[a];
    }
    sta.push_back(a);

    while (dad[b] != b) {
      stb.push_back(b);
      b = dad[b];
    }
    stb.push_back(b);

    int nroot = a;
    if (rank[b] > rank[a]) {
      nroot = b;
    } else if (rank[b] == rank[a]) {
      rank[a]++;
    }
    for (int i = 0; i < (int)sta.size(); ++i) {
      dad[sta[i]] = nroot;
    }
    for (int i = 0; i < (int)stb.size(); ++i) {
      dad[stb[i]] = nroot;
    }

    return make_pair(nroot, a != b);
  }

private:
  int n;
  vector<int> dad;
  vector<int> rank;
};

int main() {
  // freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  // freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);

  int n, m, k, w;
  cin >> n >> m >> k >> w;
  string temp;
  getline(cin, temp);
  vector<vector<string> > levels(k, vector<string>(n));
  for (int i = 0; i < (int)levels.size(); ++i) {
    for (int j = 0; j < (int)levels[i].size(); ++j) {
      getline(cin, levels[i][j]);
    }
  }

  const int max_size = 1000 * 128;
  vector<vector<edge> > e(max_size);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < i; ++j) {
      int tl = 0;
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
          if (levels[i][x][y] != levels[j][x][y]) {
            tl += w;
          }
        }
      }
      edge temp;
      temp.from = i + 1;
      temp.to = j + 1;
      temp.len = tl;
      e[tl].push_back(temp);
    }
  }

  for (int i = 0; i < k; ++i) {
    edge temp;
    temp.from = 0;
    temp.to = i + 1;
    temp.len = n * m;
    e[n * m].push_back(temp);
  }

  DSF dsf(k + 1);
  int num = 0;
  int ic = 0;
  int ii = 0;

  int result = 0;
  vector<vector<int> > ne(k + 1);
  while (num < k) {
    if (ii >= (int)e[ic].size()) {
      ii = 0;
      ic++;
      continue;
    }

    int tl = e[ic][ii].len;
    int a = e[ic][ii].from;
    int b = e[ic][ii].to;

    ii++;
    if (dsf.merge(a, b).second) {
      ne[a].push_back(b);
      ne[b].push_back(a);
      result += tl;
      num++;
    }
  }
  cout << result << endl;

  vector<int> vis(k + 1, -1);
  vis[0] = 0;
  queue<int> tc;
  tc.push(0);
  vector<pair<int,int> > tt;
  while (!tc.empty()) {
    int c = tc.front();
    tc.pop();
    for (int i = 0; i < (int)ne[c].size(); ++i) {
      if (vis[ne[c][i]] == -1) {
        vis[ne[c][i]] = c;
        tt.push_back(make_pair(ne[c][i], c));
        tc.push(ne[c][i]);
      }
    }
  }
  for (int i = 0; i < (int)tt.size(); ++i) {
    printf("%d %d\n", tt[i].first, tt[i].second);
  }
  return 0;
}
