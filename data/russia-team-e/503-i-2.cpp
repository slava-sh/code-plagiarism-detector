#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int n,d,arr[101000],ans,now,z;

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin >> n >> d;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i=0;
     i<n; i++) {
        if (arr[i]>=2*d) {
            ans+=arr[i]-d;
            now++;
        }
        z=i;
        if (now==2) break;
     }

    for (int i=z+1; i<n; i++) ans+=arr[i]-2*d;
    cout << max(ans,arr[n-1]);
}
