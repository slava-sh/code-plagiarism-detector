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
    stable_sort(a+1,a+n+1);
    maxx=a[n];
    long long int sum=a[n];
    for(int i=n-1;i>=1;i--)
    {
        if (a[i]<=d*2) break;
        sum+=a[i]-d-d;
        if (sum>maxx) maxx=sum;
        else break;
    }
    cout<<maxx;
    return 0;
}