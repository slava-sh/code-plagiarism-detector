#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main(){
    ifstream cin("socji.in");
    ofstream cout("sochi.out");
    int a[100011],d,n,i,sum=0,l;
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
    for (i=0;i<n;i++){
        if(a[i]>=d)break;
    }
    if(a[i]>=d){sum=a[i];i++;}
    for(;i<n;i++){
        if(a[i]>=d){
            sum+=a[i];
            break;
        }
    }
    i++;
    for (;i<n;i++){
        if(a[i]>=d){
            sum-=d;
            sum+=a[i];
        }
    }
    //cout<<sum<<endl;
}
