#include <iostream>
#include <stdio.h>
using namespace std;
__int64 a[310001];
int binary(__int64 value , int see , int left , int right){
    while(left <= right){
               int middle = (left+right)/2;
               if(a[middle] > value + see && a[middle-1] <= value + see)
               return middle;
               else
               if(a[middle] > value + see) right = middle - 1;
               else left = middle + 1;
               }
    return -1;
}
int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    __int64 sum = 0;
    int n ;
    cin >> n;
    __int64 q;
    cin >> q;
    for(int i = 0 ; i < n ; i ++)
    scanf("%u",&a[i]);
    for(int i = 0 ; i < n ; i ++)
    {
            int b = binary(a[i],q,i,n);
			if(b != -1)
			sum += n-b ;
            }
    cout << sum;
    getchar();getchar();
}


