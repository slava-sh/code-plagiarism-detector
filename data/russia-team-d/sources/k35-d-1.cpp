#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>z`
#include <vector>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int a[100009],n,b[100009],k;
bool check(int x)
{
   // cout<<x<<endl;
    int i;
    bool f=true;
    for(i=0;n>i;i++)
        b[i]=a[i];
    for(i=1;n>i;i++)
    {
        if(b[i]-b[i-1]<x)
            b[i]=b[i-1]+x;
        if(b[i]>k)
            f=false;
      //  cout<<b[i]<<" ";
    }
  //  cout<<endl;
    return f;
}
int main(){
    ifstream cin("fence.in");
    ofstream cout("fence.out");
    int i,l,r,m,mi=-1;
    cin>>n>>k;
    for (i=0;i<n;i++){
        cin>>a[i];
        if(mi==-1)
            mi=a[i];
        else mi=min(a[i],mi);
    }
    sort(a,a+n);
    l=0;r=mi;
    while(r!=l)
    {
       // cout<<l<<" "<<r<<endl;
        m=(l+r+1)/2;
        if(check(m))l=m;
        else r=m-1;
    }

    cout<<l<<endl;
}
