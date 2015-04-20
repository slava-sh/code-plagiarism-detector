#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,c,l;
int main()
{
    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    cin>>n>>m;
    l=n+m-2;
    for(int i=2;i<=m*m+n*n;)
    {
        if(l>=i)
        {
            c++;
        }
        if(l<i)
        {
            cout<<c;
            return 0;
        }
        i+=4;
    }
}
