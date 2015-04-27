#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;

bool ispol[MAX_N] = {}, res[MAX_N] = {};
int kolvo[MAX_N], data[MAX_N], bas[MAX_N], x, m;

inline void solve(){
    scanf("%d%d", &m, &x);
    
    m--;
    for(int uk = 1; uk <= x; uk++)
    
    scanf("%d", &kolvo[uk]);
    int fst
    =
    m+1;
    for(int uk = 1; uk <= m; uk++)
    {  scanf("%d%d", &data[uk], &bas[uk]);  if (bas[uk] == 1 && fst == m+1) fst = uk;  }

    int any = 0;
    for(int uk = 1; uk <= fst-1; uk++) if (data[uk] > 0) kolvo[data[uk]]--;
    
    else any++;
    if (fst != m+1)
    {
        for(int uk = fst; uk <= m; uk++)   if (data[uk] > 0) ispol[data[uk]] = true;
        int mn = 2e9,
        j = 0;
        for(int uk = 1; uk <= x; uk++) if (kolvo[uk] - any < 1
        &&
        !ispol[uk])
        {
                res[uk] = true;       if (kolvo[uk] - any < mn) {
                    mn = kolvo[uk] - any;                    j = uk;
                }
            }
        any -= kolvo[j];
        kolvo[j] = 0;
        res[j] = false;
        for(int uk = fst; uk <= m; uk++)     if (data[uk] > 0) kolvo[data[uk]]--; else any++;
    }
    for(int uk = 1; uk <= x; uk++)
    if (kolvo[uk] - any < 1)
    res[uk] = true;
    
    for(int uk = 1; uk <= x; uk++)
    if (res[uk])
    putchar('Y');
    else
    putchar('N');
    
    putchar('\n');
    for(int uk = 1; uk <= max(x, m); uk++)
    kolvo[uk] = data[uk] = bas[uk] = 0,
    ispol[uk] = res[uk] = false;
}

int main(int argc, const char * argv[]) {
    int ttt; scanf("%d", &ttt); while (ttt--)
    solve();
}
