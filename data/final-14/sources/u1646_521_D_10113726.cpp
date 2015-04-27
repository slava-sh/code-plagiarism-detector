#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

const int max_n = 100000;

int main()
{
  int k, n, m;
  cin >> k >> n >> m;
  vector<long long> a(k);
  for (int i=0; i<k; i++) scanf("%lld", &a[i]);

  vector<pair<int, int> > assign(k); // keep best
  vector<vector<pair<int, int> > > add(k); // keep all
  vector<vector<pair<int, int> > > mult(k); // keep all

  for (int i=1; i<=n; i++) {
    int ty, num, value;
    scanf("%d %d %d", &ty, &num, &value);
    num --;
    if (ty == 1) {
      if (assign[num].first < value) assign[num] = pair<int, int>(value, i);
    } else if (ty == 2) {
      add[num].push_back(pair<int, int>(value, i));
    } else {
      mult[num].push_back(pair<int, int>(value, i));
    }
  }

  vector<int> add_idx(k);
  vector<int> mult_idx(k);

  set<pair<long double, int> > S;

  for (int i=0; i<k; i++) {
    if (assign[i].first > a[i]) {
      add[i].push_back(pair<int, int>(assign[i].first - a[i], assign[i].second));
    }
    sort(add[i].rbegin(), add[i].rend());
    sort(mult[i].rbegin(), mult[i].rend());
    if (add[i].size()) S.insert(pair<long double, int>(add[i][0].first * ((long double)1.0) / a[i], i*2));
    if (mult[i].size()) S.insert(pair<long double, int>(mult[i][0].first - 1, i*2+1));
  }

  int res_cnt = 0;
  vector<vector<int> > assigned(k);
  vector<vector<int> > added(k);
  vector<vector<int> > multed(k);
  for (int iter=0; iter<m; iter++) {
    if (!S.size()) break;
    set<pair<long double, int> >::iterator it = S.end();
    it --;
    if ((*it).first <= 0.0) break;
    int idx = (*it).second;
    S.erase(it);

    res_cnt ++;
    if (idx % 2 == 0) {
      if (add[idx/2][add_idx[idx/2]].second == assign[idx/2].second)
        assigned[idx/2].push_back(add[idx/2][add_idx[idx/2]].second);
      else added[idx/2].push_back(add[idx/2][add_idx[idx/2]].second);
      a[idx/2] += add[idx/2][add_idx[idx/2]].first;
      add_idx[idx/2] ++;
      if (add_idx[idx/2] < add[idx/2].size()) {
        S.insert(pair<long double, int>(add[idx/2][add_idx[idx/2]].first * ((long double)1.0) / a[idx/2], idx));
      }
    } else {
      multed[idx/2].push_back(mult[idx/2][mult_idx[idx/2]].second);
      mult_idx[idx/2] ++;
      if (mult_idx[idx/2] < mult[idx/2].size()) {
        S.insert(pair<long double, int>(mult[idx/2][mult_idx[idx/2]].first - 1, idx));
      }
    }
  }

  cout << res_cnt << endl;
  for (int i=0; i<k; i++) {
    for (int j=0; j<assigned[i].size(); j++) printf("%d ", assigned[i][j]);
    for (int j=0; j<added[i].size(); j++) printf("%d ", added[i][j]);
    for (int j=0; j<multed[i].size(); j++) printf("%d ", multed[i][j]);
  }
  printf("\n");
}
