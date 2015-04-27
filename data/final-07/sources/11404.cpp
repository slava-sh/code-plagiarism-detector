#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define vpii vector <pair <int, int> >
#define fi first
#define se second


vpii get(vpii &v) {
  int n = v.size();
  if (n == 1) {
    return v;
  }

  sort (v.begin(), v.end());
  int X = v[n / 2].fi; 
  vpii res;
  for (int i=0; i<n; i++)
    res.push_back(make_pair(X, v[i].se));

  vpii v1;
  for (int i=0; i < n/2; i++) {
    v1.push_back(make_pair(v[i].se, v[i].fi));
  }
  v1 = get(v1);
  for (int i=0; i < (int)v1.size(); i++) {
    res.push_back(make_pair(v1[i].se, v1[i].fi));
  }

  v1.clear();
  for (int i=n/2; i < n; i++) {
    v1.push_back(make_pair(v[i].se, v[i].fi));
  }
  v1 = get(v1);
  for (int i=0; i < (int)v1.size(); i++) {
    res.push_back(make_pair(v1[i].se, v1[i].fi));
  }
  return res;
}

int main(void) {
  int n;
  vpii v;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back(make_pair(x, y));
  }

  vpii res = get(v);

  sort(res.begin(), res.end());
  res.resize(unique(res.begin(), res.end()) - res.begin());

  printf ("%d\n", (int)res.size());
  for (int i=0; i<(int)res.size(); i++) {
    printf ("%d %d\n", res[i].fi, res[i].se);
  }


  return 0;
}
