#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
int a[100005],i,m,ans,k,l,j,q,x,n,ma,mi;
string s;
main()
{

       freopen("prizes.in","r",stdin);
       freopen("prizes.out","w",stdout);
          cin>>n>>m;
          if(n<=2 || m<=2)ans=0;else ans=1;
          if(n==1)
          {
              ans=(m+1)/4;    
          }
          if(m==1)
          {
                  ans=(n+1)/4;
          }
          
          cout<<ans;
          
}
