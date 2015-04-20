#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");
int main()
{
    long long int a[100100],n,d,maxx=0;
    cin>>n>>d;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    maxx=a[n];
    for (int i=n-1;i>=1;i--)
    {
        int max1=maxx-(2*d)+a[i];
        if (max1>maxx) maxx=max1;
    }
    cout<<maxx;
    return 0;
}
