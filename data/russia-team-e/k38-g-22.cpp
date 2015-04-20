#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
ifstream cin("prizes.in");
ofstream cout("prizes.out");
int  main()
{
    long long int n,m,r;
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
    cout<<(min(n,m)+1)/4;
    return 0;
}
