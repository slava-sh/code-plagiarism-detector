#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n, r, a[300009], ind, p, q, x;
int main()
{
    ifstream cin("che.in");
    ofstream cout("che.out");
    cin>>n>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        x=2;
    for(int i=1;i<=n;i++)
    {
        if(i+1>x)
            x=i+1;
        for(;x<=n;x++)
        {
            if(a[x]-a[i]>r)
            {
                q+=(n-x+1);
                break;
            }
        }
    }
    cout<<q;
}
