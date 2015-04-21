#include <stdio.h>
int main() {
    int n, t[100005],ans = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        if(i!= 1 && t[i] != t[i-1])
            ans++;
    }
    int q;
    scanf("%d", &q);
    for(; q > 0; q--) {
        int p, c;
        scanf("%d%d", &p, &c);
        if(p != 1 && t[p] != t[p-1]) ans--;
        if(p != n && t[p+1] != t[p]) ans--;
        t[p] = c;
        if(p != 1 && t[p] != t[p-1]) ans++;
        if(p != n && t[p+1] != t[p]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
