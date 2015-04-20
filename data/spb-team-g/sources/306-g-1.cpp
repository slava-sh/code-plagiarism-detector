#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int Q = int(1e5) + 10;

long long n, a[Q], sum, ost, nad, ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i]);
    }
    sort(a, a + n);
    if(a[0] == a[n - 1])
        cout << "0";
    else
    {
        ost = a[n - 1];
        for(int i = 0; i < (n - 1); i++)
        {
            nad += (a[n - 2] - a[i]);
        }
        ans = 1;
        int i = n - 2;
        while(ost < nad)
        {
            ans++;
            nad -= i * (a[i] - a[i - 1]);
            ost += a[i];
            i--;
        }
        cout << ans;
    }
    return 0;
}
