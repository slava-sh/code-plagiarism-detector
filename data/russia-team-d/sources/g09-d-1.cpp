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
int a[100005],i,m,k,l,j,q,x,n,ma,mi,ans=0,cur,c,txa,h;
string s;
main()
{

       freopen("fence.in","r",stdin);
       freopen("fence.out","w",stdout);
          cin>>n>>k;
          ans=n/k;
          for(i=0;i<n;i++)cin>>a[i];
          sort(a,a+n);
          
          cur=k-a[n-1];
          h=a[0];
          for(i=1;i<n;i++){
                           c=a[i]-a[i-1];
                           ans+=c;
                           h=min(h,a[i]);
          }
          txa=ans+cur;
          cout<<min(h,txa/(n-1));
          //system("pause");
          
          


}
