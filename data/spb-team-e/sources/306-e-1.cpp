#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int l1,l2,r1,r2,m,n,sum1,sum2;
int main()

{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> m>> l1 >> r1 >> l2>> r2;
    int cnt1 = 0;
    int cnt2 =0;
    int cnt = 0;
    int x;
    for (int i =0 ; i < n;i++)
    {
        cin >> x;
        if (((x >= l1) && (x <=r1)))
            cnt1++;
        if (((x >= l2) && (x <=r2)))
            cnt2++;
        if  ((((x >= l1) && (x <=r1))) && (((x >= l2) && (x <=r2))))
        {
            cnt++;
            cnt1--;
            cnt2--;
        }
       // cout << cnt1<< " " << cnt2 << " " << cnt << "\n";
    }

    if (cnt %2 == 0)
    {
         sum1 = cnt / 2 + cnt1;
         sum2 = cnt / 2 + cnt2;
    }
    if (cnt %2 != 0)
    {
        sum1 = cnt / 2 + 1+ cnt1;
        sum2 = cnt / 2 + cnt2;
    }
    if (m % 2 == 0)
    {
        sum1 = min(m/2,sum1);
        sum2 = min(m/2,sum2);
    }
    else
    {
      sum1 = min(m/2+1,sum1);
      sum2 = min(m/2,sum2);
    }
    //cout << cnt << " " << cnt1 << " "<< cnt2 ;
   // cout << sum1 << " " << sum2;
    if (sum1 == sum2)
        cout << "Draw";
    else
    {
        if (sum1 > sum2)
        {
            cout << "Petya";
        }
        else
        {
            cout << "Vasya";
        }
    }
    return 0;
}
