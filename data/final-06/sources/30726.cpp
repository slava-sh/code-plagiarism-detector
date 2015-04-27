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

char a[35][35];
int mark[35][35];

int f[35][35];
int X[28], Y[28], c[28];

int cnt[7];
int b[7][7];
int Ans[35][35];

long long ans = 0;

int p[28][2], l[28];

void get(int x, int y) {
  if (x == 14) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < 28; i++) {
      int f1 = f[p[i][0] / 100][p[i][0] % 100];
      int f2 = f[p[i][1] / 100][p[i][1] % 100];
      b[f1][f2]++;
    }
    for (int i = 0; i <= 6; i++) {
      if (b[i][i] != 1) {
        return;
      }
    }
      
    for (int i = 0; i <= 6; i++) {
      for (int j = i+1; j <= 6; j++) {
        if (b[i][j] + b[j][i] != 1) {
          return;
        }
      }
    }

    if (ans == 0)
      memcpy (Ans, f, sizeof (f));
    ans++;
    return;
  }

  for (int i=0; i <= y + 1 && i <= 6; i++)
    if (cnt[i] < 2) {
      cnt[i]++;
      c[x] = i;
      f[X[x]][Y[x]] = i;
      f[X[x]+1][Y[x]] = i;
      f[X[x]][Y[x]+1] = i;
      f[X[x]+1][Y[x]+1] = i;

      get (x + 1, max(i, y));

      cnt[i]--;
    }
}

int main(void) {
  int m, n;
  scanf("%d%d\n", &m, &n);
  for (int i=0; i<m; i++) {
    gets (a[i]);
  }

  memset(f, -1, sizeof (f));

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (a[i][j] != '.') {
        a[i][j] = 'A' <= a[i][j] && a[i][j] <= 'B' ? a[i][j] - 'A' : a[i][j] - 'a' + 2;
        int t = a[i][j];
        p[t][l[t]++] = i * 100 + j;
      }
    }
  }

  int k = 0;
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (!mark[i][j] && a[i][j] != '.') {
        mark[i][j+1] = mark[i][j] = mark[i+1][j] = mark[i+1][j+1] = 1;
        X[k] = i;
        Y[k++] = j;
      }
    }
  }

  get(0, -1);

  cout << ans * 5040 << endl;

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++)
      printf ("%c", Ans[i][j] == -1 ? (char)'.' : (char)(Ans[i][j] + '0'));
    printf ("\n");
  }

  return 0;
}
