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
int a[100005],b[100005],i,m,ans,k,l,j,q,x,n,ma,mi,d;
string s;

main()
{

       freopen("sochi.in","r",stdin);
       freopen("sochi.out","w",stdout);
          cin>>n>>d;
          
          for(i=0;i<n;i++)cin>>a[i];
          

          sort(a,a+n);
          reverse(a,a+n);
          
          for(i=0;i<n;i++)
          {
                  if(a[i]>2*d){ans+=a[i]-2*d;continue;}
                  break;
          }
          ans+=2*d;
          
          
          
          cout<<ans;


}
