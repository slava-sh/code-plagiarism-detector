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
    for (int i=2;i<=n;i++)
    {
        for (int j=i-1;j>=1;j--)
        {
            if ((a[i]-a[j])>r)
            {
                c+=j;
                break;
            }
        }
    }
    cout<<c;
    return 0;
}
