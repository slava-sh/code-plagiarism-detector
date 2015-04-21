#include <iostream>
#include <cstdio>

using namespace std;

int h[1000500];

int cnt(int a, int b, int l, int r){
    int res = 0;
    for(int i = l+1; i < r; ++i){
        if(h[i] < a && h[i] > b)
            ++res;
    }
    return res;
}

int a[1000500], sz = 0;

int bns(int z){
    int l = 0, r = sz;
    while(l != r){
        int m = (l + r) >> 1;
        if(a[m] < z)
            l = m + 1;
        else
            r = m;
    }
    return (sz - l);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &h[i]);
    }
    pair<int, int> ans = make_pair(-1, -1);
    int mx = 0;

    for(int i = 1; i <= n; ++i){
        sz = 0;
        for(int j = i+1; j <= n; ++j){
            if(h[j] > h[i])
                continue;
            int t = bns(h[j]);
            if(t > mx){
                ans = make_pair(i, j);
                mx = t;
            }
            a[sz++] = h[j];
        }
    }
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}
