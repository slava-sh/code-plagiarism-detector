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
    if ((a>2) && (b>2)) {cout<<1<<endl; return 0;}
    if ((a>1) && (b>1)) {cout<<0<<endl; return 0;}
    cout<<(a+b)/4<<endl; 
    return 0;    
}
