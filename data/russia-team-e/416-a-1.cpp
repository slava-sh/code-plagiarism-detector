#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>
#include <cstdlib>
#include <deque>
using namespace std;

int n, z[1010], a[1010],  i, j, k, temp, temp2;
set <int> q;
long long int ans=1, mod = pow (10,9)+7;

int main ()
{
    //freopen ("input.txt", "r", stdin);
    freopen ("binary.in", "r", stdin);
    ofstream cout("binary.out");
    cin >> n;
    for (i=1; i<=n; i++) cin >> z[i];
    for (i=1; i<=n; i++) a[i]=i;
    if(z[1] != 0 && z[1] != -1)
    {
        cout << "0"  << endl;
        return 0;
    }
    for (i=2; i<=n; i++)
    {
        if(z[i] != -1)
            {
            if(i+z[i]-1 > n)
                {
                    cout << "0"  << endl;
                    return 0;
                } // 0
            for (j=i; j<i+z[i]; j++)
            {
                temp = a[j];
                temp2 = a[j-i+1];
                if(temp == - temp2)
                {
                    cout << "0"  << endl;
                    return 0;
                } // 0
                for(k = 1; k <= n; k++)
                {
                    if(a[k] == temp) a[k] = temp2;
                    if(a[k] == -temp) a[k] = -temp2;
                }
            }
            j = i+z[i];
            temp = a[j];
            temp2 = a[j-i+1];
            if(temp == temp2)
            {
                cout << "0"  << endl;
                return 0;
            }
            for(k = 1; k <= n; k++)
                {
                    if(a[k] == -temp) a[k] = temp2;
                    if(a[k] == temp) a[k] = -temp2;
                }
            }
    }
    for(i = 1; i <= n; i++)
        if (a[i]>0) q.insert(a[i]);
    ans=1;
    for (i=1; i<=q.size(); i++)
    {
        ans=ans*2;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}
