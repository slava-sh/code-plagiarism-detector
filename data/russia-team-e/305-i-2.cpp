#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000005];
int sum,kol,it;
int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d;
    cin >> n >> d;;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int l, r, q;
    sort(a+1,a+n+1);
    it=1;
    kol=n;
    while (a[it]<=2*
      d && kol!=0) {
        kol--;
        it++;
    }
    for (int i=n-kol+1;i<=n;i++)
        sum+=a[i];
        //cout << sum;
    sum=sum-2*d*(kol-1);
    if (kol!=0)
    cout << sum;
    else
        cout << a[n];

    //for(int i = 1; i <= n; i++)
        //cout << a[i];
    return 0;
}
