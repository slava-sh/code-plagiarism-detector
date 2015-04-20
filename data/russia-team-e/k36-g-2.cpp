#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int solve(int n, int m)
{
    int ans = 0;
    int k = 0;
    if(n - 1 >= 2)
        ans++;
    ans += ((n - 3)/4);
    if((n-1) % 2 == 0)
        k = 1;

    int ch = ((n-1)/2)%2;

    if(!ch)
    {
        if(m - 1 >= 2)
            ans += k;
        ans = ans + ((m-3)/4)*k;
    }
    else
    {
        ans = ans + (m-1) / 4 * k;
    }


    return ans;
}

int main()
{
    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    int ans1 = solve(n, m);
    int ans2 = solve(m, n);
    int ans = min(ans1, ans2);

    cout << ans << endl;

    return 0;
}
