#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int a[300100];
int j,n,r,d,l,m,k;
long long s=0;
int main(){
   ifstream cin("che.in");
   ofstream cout("che.out");
   //freopen("input.in","r",stdin);
   //freopen("output.in","w",stdout);
   cin>>n>>d;
   for(int i=0; i<n; i++){
            cin>>a[i];
       int k=a[i]-d;
       l=0;r=i;
       while(r!=l)
       {
           m=(r+l+1)/2;
           if(a[m]>=k)
            r=m-1;
           else l=m;
       }
       if(a[l]<k)
            l++;
       s+=l;
   }
   cout<<s<<endl;
  system("pause");

}
/*
4 4
1 3 5 8
*/
