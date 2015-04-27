#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int nt = 131072;

void change (vector <int> &tree, int i, int v) {
  tree[nt - 1 + i] = v;
  int x = (nt - 1 + i) / 2;
  while (x > 0) {
    tree[x] = tree[2 * x] + tree[2 * x + 1];
    x /= 2;
  }
}

int findRes (const vector <int> &tree, int i, int L, int R, int x, int y) {
  if ((L == x) && (R == y)) {
    return tree[i];
  }
  int M = (L + R) / 2;
  if (y <= M) {
    return findRes(tree, 2 * i, L, M, x, y);
  } else {
    if (x > M) {
      return findRes(tree, 2 * i + 1, M + 1, R, x, y);
    } else {
      return findRes(tree, 2 * i, L, M, x, M) + findRes(tree, 2 * i + 1, M + 1, R, M + 1, y);
    }
  }
}

void changeAll (vector <int> &treePlus, vector <int> &treeMinus, int i, int v) {
  if (i % 2 != 0) {
    change(treePlus, i, v);
    change(treeMinus, i, -v);
  } else {
    change(treePlus, i, -v);
    change(treeMinus, i, v);
  }
}

int main () {
  freopen("signchange.in", "rt", stdin);
  freopen("signchange.out", "wt", stdout);
  vector <int> treePlus(2 * nt + 1, 0), treeMinus(2 * nt + 1, 0);
  int n;
  cin >> n;
  int x;
  for(int i = 1; i <= n; ++i) {
    cin >> x;
    changeAll(treePlus, treeMinus, i, x);
  }
  int m;
  cin >> m;
  int l, r;
  for (int i = 0; i < m; ++i) {
    cin >> x >> l >> r;
    if (x == 0) {
      changeAll(treePlus, treeMinus, l, r);
    } else {
      if (l % 2 != 0) {
        cout << findRes(treePlus, 1, 1, nt, l, r);
      } else {
        cout << findRes(treeMinus, 1, 1, nt, l, r);
      }
      cout << endl;
    }
  }
  return 0;
}
