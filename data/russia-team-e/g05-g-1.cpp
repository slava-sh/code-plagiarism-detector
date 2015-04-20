#include <iostream>
#include <cstdio>
using namespace std;
long long a,b;
int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    cin>>a>>b;
    cout<<min(a,b)/2<<endl;
    return 0;
}
