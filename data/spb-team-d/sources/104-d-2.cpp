#include <iostream>
#include <stdio.h>

using namespace std;

long long l[1010];
long long r[1010];
long long x[1010];

int main()
{
    freopen ("dunes.in", "r", stdin);
    freopen ("dunes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i] >> x[i];
    }
    for (int i = 0; i < m; i++){
        long long y;
        long long ans = 0;
        cin >> y;
        for (int j = 0; j < n; j++){
            if (l[j] <= y && r[j] >= y){
                if (y % 2 == l[j] % 2){
                    ans += x[j];
                } else {
                    ans -= x[j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
