#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n,m;
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);

    cin>>n>>m;
    if(n<=2 && m<=2){cout<<0;return 0;}
    if(m==1 || n==1){m=max(m,n);cout<<(m-3)/4+1;return 0;}
    cout<<1;
return 0;
}

