#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int d,n,a,b,arr[101000],ans,now,z;

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin >> n >> d;
    b=n+1;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i=0; i<n; i++) {
        if (arr[i]>2*d) {
            a=i;
            break;
        }
    }
    for (int i=a; i<n; i++) {
        if (arr[i]>=3*d) {
            b=i;
            break;
        }
    }
    for (int i=b; i<n; i++) ans+=arr[i]-2*d;
    if (b==n+1)
        if (n>1)
            ans=max (arr[n-1], arr[n-1] + arr[n-2] - 2*d);
        else ans=arr[0];
    else{
        if (b-1 >= a) ans+=arr[b-1] - d; else ans+=d;
        if (b-2 >= a) ans+=arr[b-2] - d; else ans+=d;
    }
    //cout << b << " " << a << endl;
    cout << ans;

}
