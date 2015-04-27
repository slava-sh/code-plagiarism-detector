#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f(vector<string> s, int n, int m, bool f) {
  int h = -1;
  int w = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') {
        h = i;
        w = j;
        break;
      }
    }
    if (h >= 0) break;
  }
  int w1 = 1;
  int h1 = 1;
  s[h][w] = '.';
  while (1) {
    bool hf = true;
    bool wf = true;
    for (int i = 0; i < w1; ++i) {
      if (!(h + h1 < n && s[h + h1][w + i] == 'X')) {
        hf = false;
      }
    }
    for (int i = 0; i < h1; ++i) {
      if (!(w + w1 < m && s[h + i][w + w1] == 'X')) {
        wf = false;
      }
    }
    if (!hf && !wf) break;
    if (hf && wf) {
      if (w1 > 1 && h1 > 1) {
        return -1;
      }
      if (f) {
        if (w1 == 1) {
          while (w + w1 < m && s[h][w + w1] == 'X') {
            for (int i = 0; i < h1; ++i) s[h+i][w+w1] = '.';
            w1++;
          }
          continue;
        }
        if (h1 == 1) { 
          while (h+h1 < n && s[h+h1][w] == 'X') {
            for (int i = 0; i < w1; ++i) s[h+h1][w+i] = '.';
            h1++;
          }
          continue;
        }
      } else {
        if (h1 == 1) { 
          while (h+h1 < n && s[h+h1][w] == 'X') {
            for (int i = 0; i < w1; ++i) s[h+h1][w+i] = '.';
            h1++;
          }
          continue;
        }
        if (w1 == 1) {
          while (w+w1 < m && s[h][w + w1] == 'X') {
            for (int i = 0; i < h1; ++i) s[h+i][w+w1] = '.';
            w1++;
          }
          continue;
        }
      }
    }
    if (hf) {
      for (int i = 0; i < w1; ++i) {
        s[h + h1][w + i] = '.';
      }
      ++h;
    }
    if (wf) {
      for (int i = 0; i < h1; ++i) {
        s[h + i][w + w1] = '.';
      }
      ++w;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') {
        return -1;
      }
    }
  }
  return h1 * w1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int a = f(s,n,m,true);
  int b = f(s,n,m,false);
  int res;
  if (a == -1 && b == -1) {
    res = -1;
  } else if (a == -1) {
    res = b;
  } else if (b == -1) {
    res = a;
  } else {
    res = min(a, b);
  }
  cout << res << endl;
  return 0;
}
