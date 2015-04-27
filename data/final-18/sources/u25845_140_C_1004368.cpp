#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 100015;
int r[MAXN];
int a[MAXN], b[MAXN];
int c[MAXN];
int prev[MAXN], next[MAXN];
priority_queue<pair<int, int> > q;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &r[i]);
        }
        sort(r, r + n);
        int last = r[0], all = 1;
        a[0] = r[0], b[0] = 1;
        for (int i = 1; i < n; i++) {
            if (r[i] != last) {
                a[all] = r[i];
                b[all++] = 1;
                last = r[i];
            } else {
                b[all - 1]++;
            }
        }
        for (int i = all - 1; i >= 0; i--) {
            a[i + 1] = a[i];
            b[i + 1] = b[i];
        }
        /*for (int i = 0; i <= all + 2; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        int top = 0;
        int out = 0;
        while (1) {
            //if (next[next[next[0]]] > all) break;
            bool flag = true;
            for (int now = next[0], t = 2; t >= 0; t--) {
                if (now > all) {
                    flag = false;
                }
                c[out + t] = a[now];
                b[now]--;
                if (b[now] == 0) {
                    next[prev[now]] = next[now];
                    prev[next[now]] = prev[now];
                }
                now = next[now];
            }
            if (flag) {
                out += 3;
            } else {
                break;
            }
        }*/
        while (!q.empty()) q.pop();
        int out = 0;
        for (int i = 1; i <= all; i++) {
            q.push(make_pair(b[i], a[i]));
        }
        pair<int, int> pp[3];
        int v[3];
        while (q.size() >= 3) {
            for (int i = 0; i < 3; i++) {
                pp[i] = q.top();
                q.pop();
                pp[i].first--;
                v[i] = pp[i].second;
            }
            sort(v, v + 3);
            for (int i = 2; i >= 0; i--) {
                c[out++] = v[i];
            }
            for (int i = 0; i < 3; i++) {
                if (pp[i].first) {
                    q.push(pp[i]);
                }
            }
        }
        printf("%d\n", out / 3);
        for (int i = 0; i < out; i += 3) {
            printf("%d %d %d\n", c[i], c[i + 1], c[i + 2]);
        }
        /*for (int i = 0; i < all; i++) {
            printf("%d %d\n", a[i], b[i]);
        }*/
        
    }
}
