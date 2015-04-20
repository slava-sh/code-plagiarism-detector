#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("abcd.in", "r", stdin);
    //freopen("abcd.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int ans = ((a / 1000) * 10 + (a / 100) % 10) * ((a / 1000) * 10 + (a / 100) % 10);
        a %= 100;
        ans += ((a / 10) * 10 + (a) % 10) * ((a / 10) * 10 + (a) % 10);
        if (ans % 7 == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
