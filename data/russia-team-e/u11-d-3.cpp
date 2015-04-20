#include <iostream>
#include <stdio.h>
using namespace std;
__int64 n , k;
int binary(__int64 left , __int64 right)
{
    while(left <= right)
    {
               __int64 middle = (left+right)/2;
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
    __int64 a , min=1e+9,max = 0;
    for(int i = 0 ; i < n ; i ++)
    {
            cin >> a;
            if(min > a) min = a;
            else if(max < a) max = a;
            }
   if(max == k) cout << "0";
   else
   {
   int t = binary(0,min);
   if(t == -1)cout << min;
   else cout << t;
   }
    getchar();getchar();
}


