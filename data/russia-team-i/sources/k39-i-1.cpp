#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int a[100002];
int main ()
{
    freopen ("sochi.in", "r", stdin);freopen ("sochi.out", "w", stdout);
    int n,k,i,s=0,d=0;
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i];
    sort(a + 1,a + n +1);
    i=n;
    while ((d!=2)&&(i>0))
    {
        if (a[i]<3*k) d++;
        s=s+a[i]-2*k;
        i--;
    }
    s=s+2*k;
    cout<<s;
}
