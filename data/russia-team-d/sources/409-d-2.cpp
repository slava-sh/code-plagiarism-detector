#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const long long int Max_n = 100100;
long long int A[Max_n];

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    long long int n, len, i, minn = len + 1;
    cin >> n >> len;
    for(i = 0; i < n; ++i)
    {
        cin >> A[i];
        if (A[i] < minn)
        {
            minn = A[i];
        }
    }
    sort(A, A + n);
    long long int l, r;
    l = 0;
    r = minn + 1;
    while (r - l > 1)
    {
        long long int m = (l + r) / 2;
        bool can;
        long long int use = 0;
        for (i = 0; i < n; ++i)
        {
            use=max(use,A[i]-m*(i+1));
        }
        if ((use + m * n) <= len)
        {
            can = true;
        }
        else
        {
            can = false;
        }
        if (can)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l;
    return 0;
}
