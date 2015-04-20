#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int n, k;
int a[200000];

bool proof(int mid)
{
    bool flag = true;
    int i;
    if(mid * n > k)
        flag = false;
    for(i = 1; i < n; i++)
    {
        if(k - a[i - 1] < mid)
        {
            cout <<k - a[i - 1] << " " << mid << a[i] << endl;
            flag = false;
        }
    }
    return flag;
}
int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int i, l, r, mid;
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >>  a[i];
    }
    sort(a, a + n);
    l = 0;
    r = a[0] + 1;
    while(l + 1 < r)
    {
        mid = (l + r) / 2;
        if(proof(mid))
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout << l;
    return 0;
}
