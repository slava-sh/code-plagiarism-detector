#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int Max_n = 100100;
int A[Max_n];

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n, len, i, minn = len + 1;
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
    int l, r;
    l = 0;
    r = minn + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        bool can;
        int use = 0;
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
