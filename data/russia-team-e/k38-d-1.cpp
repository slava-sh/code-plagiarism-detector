#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
ifstream cin("fence.in");
ofstream cout("fence.out");
long long int a[100010],n,k,minn=10000000000,maxx=-1;
int  main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
    }
    cout<<min(minn,k-maxx);
    return 0;
}

