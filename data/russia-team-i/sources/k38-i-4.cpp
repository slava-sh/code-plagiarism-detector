#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");
long long int a[100100],n,d,maxx;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=n;i>=1;i--)
    {
        int max1=maxx-(2*d)+a[i];
        if (max1>maxx) maxx=max1;
    }
    cout<<maxx;
    return 0;
}
