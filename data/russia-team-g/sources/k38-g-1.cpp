#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
ifstream cin("prizes.in");
ofstream cout("prizes.out");
int  main()
{
    long long int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a==1)
    {
        if(b%3==3)cout<<b/4+1;
        else cout<<b/4;
    }
    else if(a==b)
    {
        if(a%4==3)cout<<b/4+1;
        else cout<<b/4;
    }
    else
    {
        long long int k;
        k=min(a,b);
        if(k%4==3)cout<<k/4+1;
        else cout<<k/4;
    }

    return 0;
}
