#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen ("abcd.in", "r", stdin);
    freopen ("abcd.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        long long a = 0;
        a += (x % 100) * (x % 100);
        a += (x / 100) * (x / 100);
        if (a % 7 == 1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
