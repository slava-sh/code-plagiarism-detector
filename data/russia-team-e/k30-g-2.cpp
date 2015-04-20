#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,c,l=1;
int main()
{
    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
   /* cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        a[i][j]=0;
    a[1][1]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(n<=m)
        {

        }
    }*/
    cin>>n>>m;
    if(n>=m && n>2) cout<<(n-3)/2+l;
    else if(m>=n && m>2) cout<<(m-3)/2+l;
    else cout<<0;
}
