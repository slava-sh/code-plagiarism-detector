#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int a[100007];

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d, w, i, sum = 0, v = 0, md = 0, an = 0;

    cin >> n >> d;
    for (i = 0; i < n; i++){
        cin >> w;
        an = max(an, w);
        if (w <= d)
            continue;
        else
        if (w < 3 * d && w > 2 * d){
            a[md] = w;
            md++;
        }
        else{
            sum += w;
            v++;

        }
    }
    sort(a, a + md);
    if (md >= 2){
        sum += (a[md - 1] + a[md - 2]);
        v += 2;
    }
    else
    if (md == 1){
        sum += a[md - 1];
        v++;
    }
    an = max(an, sum - (v - 1) * d * 2);
    cout << an;
    return 0;
}

