#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n,m;

int main()
{
  freopen ("prizes.in","r",stdin);
  freopen ("prizes.out","w",stdout);  
   cin>>n>>m;
      
      if (n>m) swap(n,m);
          
          if (n==1 && m==1) {cout<<0<<endl; return 0;}
          if (n==1) {cout<<(m+1)/4<<endl; return 0;}
          if (n==2) {cout<<0<<endl; return 0;}
          cout<<(n+1)/4<<endl;
          
        

}
