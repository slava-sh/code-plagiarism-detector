#include <iostream>
#include <algorithm>
#include <cstdio>
#include<cmath>

using namespace std;
int n, k;
int a[200000];

bool proof(int mid)
{
    bool flag = true;
    int i;
    if(mid * n > k)
        flag = false;
    int sum = a[0];
    for(i = 1; i < n; i++)
    {
        if(k - sum < mid)
        {
            flag = false;
        }
        sum = max(sum + mid, a[i]);
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
