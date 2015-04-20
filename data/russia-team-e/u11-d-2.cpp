#include <iostream>
#include <stdio.h>
using namespace std;
__int64 n , k;
int binary(int left , int right)
{
    while(left <= right)
    {
               int middle = (left+right)/2;
               __int64 sum , sum1;
               sum = middle * n;
               sum1 =(middle+1)*n;
               if(sum <= k && sum1 > k)
               return middle;
               else if(sum1 < k) left = middle + 1;
               else right = middle - 1;
    }
    return -1;
    }
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    cin >> n >> k;
    int a , min=1e+9;
    for(int i = 0 ; i < n ; i ++)
    {
            cin >> a;
            if(min > a) min = a;
            }
   int t = binary(0,min);
   if(t == -1)cout << min;
   else cout << t;
    getchar();getchar();
}


