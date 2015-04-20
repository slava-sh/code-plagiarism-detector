#include <iostream>
using namespace std;

int n,m;

main()
{

   cin>>n>>m;
      
      if (n>m) swap(n,m);
          
          if (n==1 && m==1) {cout<<0<<endl; return 0;}
          if (n==1) {cout<<(m+1)/4<<endl; return 0;}
          if (n==2) {cout<<0<<endl; return 0;}
          cout<<(n+1)/4<<endl;
          
        

}
