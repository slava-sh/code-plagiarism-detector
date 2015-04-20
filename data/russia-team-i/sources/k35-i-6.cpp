#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <stdlib.h>
using namespace std;

    int a[100011],d,n,i,ras,sum=0,l;
int main(){
    ifstream cin("sochi.in");
    ofstream cout("sochi.out");
    cin>>n>>d;
    if(n==1){
        cin>>a[0];
        cout<<a[0]<<endl;
        return 0;
    }
    for (i=0;i<n;i++){
        cin>>a[i];
        a[i]=a[i]-d;
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(a[i]!=0){
                ras=a[i];
    sum+=a[i];break;}
    }
   // cout<<sum<<endl;
    for(i=n-1;i>=1;i--){
        if(a[i]!=0){
    sum+=a[i];break;}
    }
    i--;
    //cout<<sum<<endl;
    for (;i>=1;i--){
        if(a[i]>0&&abs((sum-d)-ras)>=d){
            ras=sum-d;
            sum=sum-d;
            sum+=a[i];
            //cout<<sum<<" "<<ras<<endl;
        }
    }
    cout<<sum<<endl;
}
