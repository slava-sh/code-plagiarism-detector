#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    freopen("prizes.in","r", stdin);
    freopen("prizes.out","w", stdout);
    long long int n,m,cmin,cmax;
    cin>>n>>m;
    cmin = min(m,n);
    cmax = max(m,n);
    if (cmin == 1)
    {
        if (cmax>2)
        {
            cout<<((cmax+1) / 4);
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    if (cmin == 2)
    {
        cout<<0;
        return 0;
    }
            if ((cmin+1) % 4 != 0) cout<<(cmin+1) / 4;
                else cout<<((cmin+1) / 4)-1;


    return 0;
}