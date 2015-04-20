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
    a--;
    b--;
    if(a==0)
    {
        if(b%4==2)cout<<((b+1)/4+1);
        else cout<<((b+1)/4);
        return 0;
    }
    else if(a==b)
    {
        if(a%4==2)cout<<((b+1)/4+1);
        else cout<<((b+1)/4);
    }
    else
    {
        long long int k;
        k=min(a,b);
        if(k%4==2)cout<<(k+1)/4+1;
        else cout<<(k+1)/4;
    }

    return 0;
}
