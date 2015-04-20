#include <iostream>
#include <cstdio>
using namespace std;
long long a,b;
int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    cin>>a>>b;
    if ((a>1) && (b>1)) cout<<min(a-1,b-1)/2<<endl;
    else cout<<max(a-1,b-1)/2<<endl;
    return 0;
}
