
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
long long a[300005],i,m,ans,k,l,j,q,x,n,ma,mi,R,r;
string s;
main()
{
 
       freopen("che.in","r",stdin);
       freopen("che.out","w",stdout);
       
          cin>>n>>R;
          for(i=1;i<=n;i++)cin>>a[i];
        //  a[n+1]=int (1e9+9);
           
          vector<int>::iterator low,low1;
  ans=0;
                              bool f=0;
          for(i=1;i<n;i++)
          {
                          f=0;
                              l=i+1;r=n;
                              f=0;
                              while(l<r)
                              {
                                        f=1;
                                        m=l+r+1;m/=2;
                                        if(a[m]>a[i]+R) r=m-1;
                                                            else l=m;
                              }//cout<<i<<" <--------"<<endl;
                              l++;
                            //  cout<<i<<" "<<l<<" "<<ans<<" <--------"<<endl;
                            if(a[i]+R<a[i+1])l=i+1;
                              ans+=n-l+1;
          }
           
          cout<<ans;
}
