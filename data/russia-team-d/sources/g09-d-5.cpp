
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
int a[100005],i,m,k,l,j,q,x,n,ma,mi,ans=0,cur,c,txa,h,r;
string s;
main()
{
 
       freopen("fence.in","r",stdin);
       freopen("fence.out","w",stdout);
          cin>>n>>k;
          
          for(i=0;i<n;i++)cin>>a[i];
          sort(a,a+n);
          
                    bool flag=1;
          l=0; r=a[0];
          while(l<r)
          {
                    x=l+r+1;
                    x/=2;
                    int p=a[0];
               bool flag=1;
                    
                    for(int i=1;i<n;i++)
                    {
                       if(p+max(x,a[i]-p)>k){flag=0;break  ;}
                       p+=max(x,a[i]-p);
                    }
                    if(!flag)r=x-1;else l=x;
          }
          
          
          cout<<r;
}
