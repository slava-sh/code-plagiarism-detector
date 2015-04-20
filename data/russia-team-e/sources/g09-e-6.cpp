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
long long a[100005],i,m,ans,k,l,j,q,x,n,ma,mi;
string s;
map<long long,long long>mp,mp1[int(1e4+5)];
void print(long long u,long long t,long long q)
{
     long long siize=s.size()-q;
     cout<<"+";
     for(long long w=u;w<t;w++)cout<<s[w];
     
     
     cout<<"(";
     for(long long w=t;w<q;w++)cout<<s[w];
     
     cout<<")";
     
     
     if(siize==7)
     {
             cout<<s[q]<<s[q+1]<<s[q+2]<<"-"<<s[q+3]<<s[q+4]<<"-"<<s[q+5]<<s[q+6]   <<endl; 
     }
     if(siize==6)
     {
                 
                cout<<s[q]<<s[q+1]<<"-"<<s[q+2]<<s[q+3]<<"-"<<s[q+4]<<s[q+5]<<endl; 
                 
     }
     if(siize==5)
     {
               cout<<s[q]<<s[q+1]<<s[q+2]<<"-"<<s[q+3]<<s[q+4]<<endl;  
     }
     if(siize==4)
     {
                cout<<s[q]<<s[q+1]<<"-"<<s[q+2]<<s[q+3]<<endl; 
     }
     if(siize==3)
     {
                 cout<<s[q]<<s[q+1]<<s[q+2]<<endl;
     }
}
main()
{

       freopen("numbers.in","r",stdin);
       freopen("numbers.out","w",stdout);
      
          cin>>n;
         // for(i=0;i<n;i++)cin>>a[i];
        //  sort(a,a+n);
        //  reverse(a,a+n);

          for(i=1;i<=n;i++)
          {
              cin>>m;
              mp[m]=1;
              cin>>k;
              for(long long j=0;j<k;j++)
              {
                      cin>>x;
                      mp1[m][x]=1;
              }
          }
          long long y;
          long long M;
          cin>>M;getline(cin,s);
          for(i=0;i<M;i++)
          {
                       getline(cin,s); 
                       if(s[0]=='0' || s.size()!=11){cout<<"Incorrect"<<endl;continue;}
                       x=0;
                       bool flag=1; 
                       for(long long j=0;j<3;j++)
                       {
                               x*=10;
                               x+=s[j]-'0';
                               y=0;
                               
                               if(!mp[x])continue;
                               
                               if(s[j+1]==0)continue;
                               
                               for(long long q=j+1;q<=j+5;q++)
                               {
                                       y*=10;
                                       y+=s[q]-'0';
                                      if(q<j+3)continue;
                                       
                                       if(mp1[x][y] && s[q+1]!='0'){print(0,j+1,q+1);flag=0;break;j=1000; }
                               }
                               if(flag==0)break;
                       }
                       if(flag)cout<<"Incorrect"<<endl;
          }
}
