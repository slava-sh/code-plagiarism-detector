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

const int mmod = 1000000007;

int inv_mod(int a, int b) {
  if (a == 1) return b;
  int div = mmod / a + 1;
  return inv_mod((a * (long long)div) % mmod, (b * (long long)div) % mmod);
}

int gop(int a, int b) {
  return (1LL*a*b) % mmod;
}

int fac[111111];

int combi(int a, int b) {
  return gop(gop(fac[a], inv_mod(fac[b], 1)), inv_mod(fac[a-b], 1));
}

int main()
{
  fac[0] = 1;
  for (int i=1; i<=100000; i++) fac[i] = (1LL * fac[i-1] * i) % mmod;

  int n, k;
  cin >> n >> k;

  string str;
  cin >> str;

  if (k == 0) {
    int sum = 0;
    for (int i=0; i<n; i++)
      sum = (sum * 10LL + (str[i]-'0')) % mmod;
    cout << sum << endl;
    return 0;
  }

  int a = n-2;
  int b = k-1;
  int mult = 0;
  for (int i=0; i<n; i++) mult += (str[i]-'0');
  int idx = n-1;
  int res = 0;
  int rr = 1;
  while (a >= b && mult >= 1) {
    int real = mult; real -= str[idx]-'0';
//    printf("+ %dC%d * %d * %d\n", a, b, real, rr);
    res = (res + gop(rr, gop(real, combi(a, b)))) % mmod;
//    printf("+ %dC%d * %d * %d\n", a+1, b+1, str[idx]-'0', rr);
    res = (res + gop(rr, gop(str[idx]-'0', combi(a+1, b+1)))) % mmod;
    a --;
    mult -= str[idx--]-'0';
    rr = (rr * 10LL) % mmod;
  }

  cout << res << endl;
}
