#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;

int n, hl, hr;
int val[N], a[N], b[N];
int pos[N];

bool used[N];

int compute(int r) {
  for (int i=0; i<n; i++) used[i] = 0;
  
  int horiz;
  if (r%2 == 0) horiz = 100 * r + hl - hr;
  if (r%2 == 1) horiz = 100 * (r - 1) + hl + hr;
//  printf("COMPUTE %d, horiz = %d\n", r, horiz);

  for (int i = 0; i < r; i++) {
    double x = ((hl + 100 * i) * 100 * 1000) / (double)horiz;
    int x_pos = i % 2;
//    printf("i = %d, x = %lf\n", i, x);
    bool ok = 0;
    for (int j=0; j<n; j++) {
      if (pos[j] == x_pos && a[j] <= x && x <= b[j] && !used[j]) {
        used[j] = 1;
        ok = 1;
        break;
      }
    }
  //  printf("not ok, returning 0\n");
    if (!ok) return 0;
  }

  int res = 0;
  for (int i=0; i<n; i++) if (used[i]) res += val[i];
//  printf("ok, returning %d\n", res);
  return res;

}

int compute() {
  int best = 0;
  for (int i=1; i<=n; i++) best=max(best, compute(i));
  return best;
}

int main() {
  scanf("%d%d%d",&hl,&hr,&n);
  for (int i=0; i<n; i++) {
    scanf("%d", &val[i]);
    char buf[4];
    scanf("%s",buf);
    pos[i] = (buf[0] == 'F' ? 0 : 1);
    scanf("%d%d", &a[i], &b[i]);
  }
  int best = compute();
  hl = 100-hl;
  hr = 100-hr;
  for(int i=0; i<n; i++) pos[i] = 1-pos[i];
  best = max(best, compute());
  printf("%d\n", best);
  return 0;
}

