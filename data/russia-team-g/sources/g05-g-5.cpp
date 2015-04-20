#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a,b;
int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    cin>>a>>b;
    cout<<(a+b+1)%2<<endl;
    return 0;    
}
