#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
ifstream cin("prizes.in");
ofstream cout("prizes.out");
int  main()
{
    long long int n,m,r,a,b;
    cin>>n>>m;
    if (n==1)
    {
        cout<<(m+1)/4;
        return 0;
    }
    if (m==1)
    {
        cout<<(n+1)/4;
        return 0;
    }
    if (n>=m)
    {
        cout<<(m+1)/4;
        return 0;
    }
    a=(n+1)/4;
    b=(m+1)/4;
    cout<<min(a,b);
    return 0;
}
