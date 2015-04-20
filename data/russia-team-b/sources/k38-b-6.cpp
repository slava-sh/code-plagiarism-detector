#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
ifstream cin("che.in");
ofstream cout("che.out");
int n,r,a[300001],c;
int main()
{
    cin>>n>>r;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int s=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]-a[s]>r)
        for (int j=s;j<=i-1;j++)
        {
            if ((a[i]-a[j])<=r)
            {
                c+=j-1;
                s=j;
                break;
            }
            if (i-1==j)
            {
                c+=j;
                s=j+1;
                break;
            }
        }
        else c+=s-1;

    }
    cout<<c;
    return 0;
}
