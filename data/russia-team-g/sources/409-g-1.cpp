#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int a,b;
    cin>>a>>b;
    if (a>b)
    {
        swap(a,b);
    }
    if (a==1)
    {
        cout<<(b+1)/4;
    }
    if (a==2)
    {
        cout<<0;
    }
    if (a>2)
    {
        cout<<1;
    }
    return 0;
}
