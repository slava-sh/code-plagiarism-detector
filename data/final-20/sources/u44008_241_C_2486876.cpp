#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 1000;

struct node {
    int v, a, b;
    char c[2];
}   st[MaxN], sf[MaxN];

int hit[MaxN], hif[MaxN], ans = 0, score, n = 0, m = 0, type;
double tanx, x;

int cmp(node a, node b) {
    return a.a < b.a;
}

void calc(int k) {
    score = 0;
    int tt = 1, ff = 1;
    memset(hit, 0, sizeof(hit));
    memset(hif, 0, sizeof(hif));
    for (int j = 1; j <= k; j++) {
        if (type == 0) {
            for (tt = 1; tt <= n; tt++) if (st[tt].a <= x && st[tt].b >= x) break;
            if (tt <= n && !hit[tt]) { hit[tt] = true; score += st[tt].v;   }
            else {  score = -1; break;  }
        }   else {
            for (ff = 1; ff <= m; ff++) if (sf[ff].a <= x && sf[ff].b >= x) break;
            if (ff <= m && !hif[ff]) { hif[ff] = true;  score += sf[ff].v;  }   
            else {  score = -1; break;  }
        }
        x += 100 * tanx; type ^= 1;
    }
    if (score > ans) ans = score;
}

int main() {
    int hl, hr;
    scanf("%d%d%d", &hl, &hr, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%s%d%d", &st[i].v, st[i].c, &st[i].a, &st[i].b);
        if (st[i].c[0] == 'F') {
            sf[++m] = st[i];
            i--; n--;
        }
    }
    if (n > 0) sort(st + 1, st + n, cmp);
    if (m > 0) sort(sf + 1, sf + m, cmp);
    ans = 0;
    for (int k = 1; k <= n + m; k++) {
        if (k & 1) tanx = 100000.0 / (hl + hr + 100.0 * (k - 1));
        else tanx = 100000.0 / (hl + (100 - hr) + 100.0 * (k - 1));
        x = hl * tanx; type = 1;
        calc(k);
    }
    for (int k = 1; k <= n + m; k++) {
        if (k & 1) tanx = 100000.0 / ((100 - hl) + (100 - hr) + 100.0 * (k - 1));
        else tanx = 100000.0 / ((100 - hl) + hr + 100.0 * (k - 1));
        x = (100 - hl) * tanx; type = 0;
        calc(k);
    }
    printf("%d\n", ans);
    return 0;
}
