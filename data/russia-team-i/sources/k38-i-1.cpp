#include <fstream>

using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");
int main()
{
    long long int a[100100],n,d,res=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    res=a[1]+a[2]-d-d;
    for(int i=3;i<=n;i++)
    {
        res=res+a[i]-d-d;
    }
    cout<<res;
return 0;
}
