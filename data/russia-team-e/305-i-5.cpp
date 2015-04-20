#include <iostream>
#include <cstdio>
using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d;
    int ma = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] > ma)
            ma = a[i];
        if(a[i] <= d)
            b[i] = 0;
        if(a[i] > d && a[i] < 3 * d)
            b[i] = 1;
        if(a[i] >= 3 * d)
            b[i] = 2;
    }
    int i = 0;
    int max1 = 0;
    int max2 = 0;
    int ans = 0;
    while(b[i] < 2 && i <= n)
    {
        if(b[i] == 1)
        {
            if(a[i] > max1)
                max1 = a[i];
            if(max1 > max2)
                swap(max1, max2);
        }
        i++;
    }
    ans = max2;
    if(max1 + max2 - 2 * d > ans)
        ans = max1 + max2 - 2 * d;

    int qua = 0;
    if(max1 != 0)
        qua++;
    if(max2 != 0)
        qua++;
    int summ = 0;
    for(int i = 0; i < n; i++)
        if(b[i] == 2)
        {
            summ += a[i];
            qua++;
        }
    summ += max1 + max2;
    if(qua >= 1)
        summ -= 2 * (qua - 1) * d;
    ans = max(ma, ans);
    cout << max(summ, ans);
    return 0;
}
