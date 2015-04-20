#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen ("prizes.in", "rt", stdin);
    freopen ("prizes.out", "wt", stdout);
    int n, m;
    cin >> n >> m;
    int k = min (n, m) - 1;
    if (k == 0){
        k = max (n, m) - 1;
    }
    int cnt = 0;
    if(k - 2 >= 0)  {
        cnt++;
        k -= 2;
    }
    cnt += (k / 4);
    cout << cnt;
    return 0;
}
