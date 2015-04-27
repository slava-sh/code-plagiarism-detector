#include <cstdio>
#include <cstring>
#include <cassert>

typedef unsigned long long htype;

const int maxL = 100001;
const htype P = 301703;

int n, l;
char s[2 * maxL + 1];
htype h[2 * maxL + 1];
htype hr[2 * maxL + 1];

int main() {
  assert (freopen ("inventory.in", "r", stdin));
  assert (freopen ("inventory.out", "w", stdout));
  assert (scanf ("%d", &n) == 1);
  assert (fgets (s, maxL, stdin));
  for (int tt = 0; tt < n; ++tt) {
    assert (fgets (s, maxL, stdin));
    l = strlen (s) - 1;
    strncpy (s + l, s, l);
    h[0] = 0;
    for (int i = 0; i < 2 * l; ++i) {
      h[i + 1] = h[i] * P + s[i];
    }
    hr[2 * l] = 0;
    for (int i = 2 * l; i >= 0; --i) {
      hr[i - 1] = hr[i] * P + s[i - 1];
    }
    htype Pl = 1;
    for (int i = 0; i < l; ++i) {
      Pl *= P;
    }
    bool done = false;
    for (int i = 0; i < l; ++i) {
      if (h[i + l] - h[i] * Pl == hr[i] - hr[i + l] * Pl) {
        printf ("%d\n", i);
        done = true;
        break;
      }
    }
    if (!done) {
      printf ("%d\n", -1);
    }
  }
  return 0;
}
