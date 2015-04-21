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
        for(int j = i+1; j <= n; ++j){
            if(h[j] > h[i])
                continue;
            int t = cnt(h[i], h[j], i, j);
            if(t > mx){
                ans = make_pair(i, j);
                mx = t;
            }
        }
    }
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}
