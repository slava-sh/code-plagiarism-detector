#include <iostream>
#include <algorithm>
using namespace std;
__int64 a[110000];
__int64 k;
__int64 binary(__int64 left , __int64 right , __int64 son)
{
        if(right == k) return 0;
        int n = son;
        while(left <= right){
        __int64 middle = (left + right)/2;
        __int64 sum , sum1;
        sum = middle * n;
        sum1 = (middle + 1) * n;
        if(sum <= k  && sum1 > k) return middle;
        else if(sum1 < k) left = middle+1;
        else right = middle -1;
        }
}
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    __int64 MIN;
    __int64 n ;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++ )
    cin >> a[i];
    sort(a,a+n);
    MIN =a[0];
    for(int i = 0 ; i < n - 1; i ++ )
    MIN = min(MIN,binary(0,a[i],n-i));
    cout << MIN;
    getchar();
    getchar();
    }


