#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen ("fence.in", "rt", stdin);
    freopen ("fence.out", "wt", stdout);
    int n, k;
    int a;
    cin >> n >> k;
    int r = k / n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a < r){
            r = a;
        }
    }
    cout << r;
    return 0;
}
