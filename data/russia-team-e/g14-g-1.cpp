#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,i,j,k,p,q,a[1000001];
int main(){
    freopen("prizes.in","r",stdin);freopen("prizes.out","w",stdout);
    cin>>n>>m;
    if(min(n,m)==1){cout<<(max(n,m)+1)/4;return 0;}
    k=min(n,m);
    cout<<(k+1)/4;
}
