//
//  main.cpp
//  task3
//
//  Created by Vadim Zakharenko on 07/03/15.
//  Copyright (c) 2015 Vadim Zakhrenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 111111

bool used[N] = {}, ans[N] = {};
int cnt[N], a[N], b[N], n, m;

inline void solve(){
    scanf("%d%d", &m, &n); m--;
    for(int i = 1; i <= n; i++) scanf("%d", &cnt[i]);
    int fst = m+1;
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &a[i], &b[i]);
        if (b[i] == 1 && fst == m+1) fst = i;
    }
    int any = 0;
    for(int i = 1; i <= fst-1; i++)
        if (a[i] > 0) cnt[a[i]]--; else any++;
    if (fst != m+1){
        for(int i = fst; i <= m; i++)
            if (a[i] > 0) used[a[i]] = true;
        int mn = 2e9, j = 0;
        for(int i = 1; i <= n; i++)
            if (cnt[i] - any < 1 && !used[i]){
                ans[i] = true;
                if (cnt[i] - any < mn) {
                    mn = cnt[i] - any;
                    j = i;
                }
            }
        any -= cnt[j]; cnt[j] = 0; ans[j] = false;
        for(int i = fst; i <= m; i++)
            if (a[i] > 0) cnt[a[i]]--; else any++;
    }
    for(int i = 1; i <= n; i++) if (cnt[i] - any < 1) ans[i] = true;
    for(int i = 1; i <= n; i++) if (ans[i]) putchar('Y'); else putchar('N');
    putchar('\n');
    for(int i = 1; i <= max(n, m); i++) cnt[i] = a[i] = b[i] = 0, used[i] = ans[i] = false;
}

int main(int argc, const char * argv[]) {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) solve();
    return 0;
}
