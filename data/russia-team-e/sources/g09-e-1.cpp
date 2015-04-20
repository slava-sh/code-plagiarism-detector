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
map<int,int>mp,mp1[100500];
void print(int u,int t,int q)
{
     int siize=s.size()-q;
     cout<<"+";
     for(int w=u;w<t;w++)cout<<s[w];
     
     
     cout<<"(";
     for(int w=t;w<q;w++)cout<<s[w];
     
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
              for(int j=0;j<k;j++)
              {
                      cin>>x;
                      mp1[m][x]=1;
              }
          }
          int y;
          int M;
          cin>>M;getline(cin,s);
          for(i=0;i<M;i++)
          {
                       getline(cin,s); 
                       if(s[0]=='0'){cout<<"Incorrect"<<endl;continue;}
                       x=0;
                       bool flag=1; 
                       for(int j=0;j<3;j++)
                       {
                               x*=10;
                               x+=s[j]-'0';
                               y=0;
                               
                               if(!mp[x])continue;
                               
                               if(s[j+1]==0)continue;
                               
                               for(int q=j+1;q<=j+5;q++)
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
