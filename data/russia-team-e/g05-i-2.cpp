#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    long long x,i,n,ans,k;
    cin>>n>>k;
    ans=(1-n)*k*2;
    for (i=0; i<n; i++)
    {
        cin>>x;
        ans+=x;
    }
    cout<<ans<<endl;    
}
