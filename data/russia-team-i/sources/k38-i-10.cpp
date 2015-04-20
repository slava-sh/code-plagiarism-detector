#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");
long long int a[100100],n,d,maxx=0;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i==1 || i==n) a[i]-=d;
        else a[i]-=(d*2);
    }
    /*sort(a+1,a+n+1);
    for (int i=n-1;i>=2;i--)
    {
    }    cin>>a[i];
        if ((a[i]-(2*d))>=d)
        {
            maxx+=(a[i]-2*d);
            cout<<maxx<<" "<<a[i]<<endl;
        }
    }
    if (a[1]-d>=d)
    {
        maxx+=(a[1]-d);
        cout<<maxx<<" "<<1<<endl;
    }*/
    for (int i=1;i<=n;i++)
    {
        if (a[i]>0) maxx+=a[i];
    }
    cout<<maxx;
    return 0;
}
