#include <cstdio>
#include <cstring>

int t[100005], f[100005], v[105];
int hl, hr, n;
bool used[105];
double first, last, unit, upd;

int trytry(int init) {
  int x, up = init, pt = 0;
  double loc = first;
  memset(used, false, sizeof used);
  while (loc < 100000) {
    x = loc;
    if (up) {
      if (t[x] && !used[t[x]]) {
        used[t[x]] = true;
        pt += v[t[x]];
      }
      else
        return 0;
    }
    else {
      if (f[x] && !used[f[x]]) {
        used[f[x]] = true;
        pt += v[f[x]];
      }
      else
        return 0;
    }
    up ^= 1;
    loc += unit;
  }
  return pt;
}

int main(int argc, char** argv) {
  int a, b, ac, pt;
  char c;
  
  memset(t, 0, sizeof t);
  memset(f, 0, sizeof f);
  
  scanf("%d%d%d", &hl, &hr, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%*c%c%d%d", &v[i], &c, &a, &b);
    if (c == 'T')
      for (int j = a; j <= b; j++)
        t[j] = i;
    else
      for (int j = a; j <= b; j++)
        f[j] = i;
  }
  
  ac = 0;
  for (int i = 1; i <= 105; i += 2) {
    upd = i * 100 + hl + 100 - hr;
    first = hl / upd * 100000;
    unit = 100.0 / upd * 100000;
    last = 100000.0 - (100.0 - hr) / upd * 100000;
    pt = trytry(0);
    if (ac < pt)
      ac = pt;
  }
  for (int i = 0; i <= 105; i += 2) {
    upd = i * 100 + hl + hr;
    first = hl / upd * 100000;
    unit = 100.0 / upd * 100000;
    last = 100000.0 - hr / upd * 100000;
    pt = trytry(0);
    if (ac < pt)
      ac = pt;
  }
  
  for (int i = 1; i <= 105; i += 2) {
    upd = i * 100 + (100 - hl) + hr;
    first = (100 - hl) / upd * 100000;
    unit = 100.0 / upd * 100000;
    last = 100000.0 - hr / upd * 100000;
    pt = trytry(1);
    if (ac < pt)
      ac = pt;
  }
  for (int i = 0; i <= 105; i += 2) {
    upd = i * 100 + (100.0 - hl) + (100.0 - hr);
    first = (100.0 - hl) / upd * 100000;
    unit = 100.0 / upd * 100000;
    last = 100000.0 - (100.0 - hr) / upd * 100000;
    pt = trytry(1);
    if (ac < pt)
      ac = pt;
  }
    
  printf("%d\n", ac);
  
  return 0;
}
