#include <iostream>
#include <cstdio>

using namespace std;
long long n,r,arr[301000],a,b,ans;
int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    cin >> n >> r;
    for (int i=0; i<n; i++) cin >> arr[i];
    a=0; b=0;
    for (int i=0; i<402000; i++)  {
        if (a<n) {
            while ((arr[b]-arr[a]<=r) && (b<n)) {
                b++;
            }
            if (arr[b]-arr[a]>r) ans+=n-b;
            a++;
        }
    }
    cout << ans;
    return 0;
}
