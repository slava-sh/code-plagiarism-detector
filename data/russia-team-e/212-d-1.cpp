#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

int n, k;
vector < int > mas;

bool check (int q) {
    //printf("!%d\n", q);     
    int zan = mas[0];
    for (int i = 1; i < n; i++) {
        //printf("  %d\n", zan);
        // мы можем получить все длины от a - zan
        int p = max(mas[i] - zan, 0);
        int delta = max(q, p);
        if (zan + delta > k)
            return false; 
        zan += delta; 

        //printf("  %d\n", zan);
    }
    return true;
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mas.pb(x);           
    }
    sort(mas.begin(), mas.end());
    int l = 0;
    int r = mas[0] + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m; 
    }

    printf("%d\n", l);

    return 0;
}