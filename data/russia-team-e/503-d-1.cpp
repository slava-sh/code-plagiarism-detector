#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int n,k,a,b,arr[100100],x,z;



int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    a = k-arr[0];
    b = arr[0];
    x = arr[0];
    for (int i = 1; i < n; i++) {
        if (a/(n-i)<x) {
            x=a/(n-i);
        }
        if (arr[i]-x > b) {
            a-=x+(arr[i]-x-b);
            b+=x+(arr[i]-x-b);
        }
        else {
            a-=x;
            b+=x;
        }
    }
    cout << x;
    return 0;
}
