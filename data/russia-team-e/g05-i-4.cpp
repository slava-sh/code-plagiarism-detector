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
        if (((i==0) || (i==n-1)) && (x<k)) ans+=k; 
        else if (x<2*k) ans+=2*k; 
        else ans+=x;
    }
    cout<<ans<<endl;    
}
