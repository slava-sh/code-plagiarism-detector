#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen ("prizes.in", "rt", stdin);
    freopen ("prizes.out", "wt", stdout);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int k = n + m - 2;
    if (k - 2 >= 0){
        cnt++;
        k -= 2;
    }
    cnt += k / 4;
    cout << cnt;
    return 0;
}
