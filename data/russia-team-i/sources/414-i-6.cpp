#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = (int)1e5 + 10, INF = (int)1e9;

int a[N];
bool used[N];

bool cmp(int x, int y){
    return x > y;
}

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, mx, mx1, ans = 0, mxx = -INF, d, k = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            mxx = max(mxx, a[i]);
            if(a[i] >= 3 * d){
                ans += a[i] - 2 * d;
                used[i] = 1;
                k++;
            }
    }
    mx = 0;
    mx1 = -1;
    for(int i = 0; i < n; i++)
        if(!used[i] && a[i] - d > mx){
            mx = a[i] - d;
            mx1 = i;
        }
    if(mx1 >= 0)
        used[mx1] = 1;
    if(k)
        mx = max(mx, d);
    ans += mx;

    mx = 0;
    mx1 = -1;
    for(int i = 0; i < n; i++)
        if(!used[i] && a[i] - d > mx){
            mx = a[i] - d;
            mx1 = i;
        }
    if(mx1 >= 0)
        used[mx1] = 1;
    if(k)
        mx = max(mx, d);
    ans += mx;

    cout << max(mxx, ans) << endl;
    return 0;
}
