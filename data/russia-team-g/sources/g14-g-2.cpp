#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,k;
int main(){
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    freopen("prizes.in","r",stdin);freopen("prizes.out","w",stdout);
    cin>>n>>m;
    if(min(n,m)==1){k=max(n,m);cout<<(k+1)/4;return 0;}
    k=min(n,m);
    cout<<(k+1)/4;
}
