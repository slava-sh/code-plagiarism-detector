#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=100000+10;
string s[N];
int x[N],m,n,i,lastmin[N],cnt,lastplus[N];
bool wrong[N],have[N];

main()
{
 cin>>n>>m;
 for ( i=1;i<=m;i++ )
  cin>>s[i]>>x[i];
 
 for ( i=1;i<=n;i++ )
  lastmin[i]=0;
 
 for ( i=1;i<=m;i++ )
  if ( s[i]=="+" && lastmin[x[i]]!=(i-1) ) wrong[x[i]]=true;
                                      else if ( s[i]=="-" ) lastmin[x[i]]=i;
 
 for ( i=1;i<=n;i++ )
  lastplus[i]=m+1;
 
 for ( i=m;i>=1;i-- )
  if ( s[i]=="-" && lastplus[x[i]]!=(i+1) ) wrong[x[i]]=true;
                                      else if ( s[i]=="+" ) lastplus[x[i]]=i;
 
 for ( i=1;i<=m;i++ )
  {
   if ( s[i]=="+" )
    {
     have[x[i]]=true;
     cnt++;
    }
   else if ( have[x[i]] )
    {
     have[x[i]]=false;
     cnt--;
    }
   
   if ( s[i]=="-" )
    {
     if ( cnt>0 ) wrong[x[i]]=true;
    }
   if ( s[i]=="+" )
    {
     if ( cnt>1 ) wrong[x[i]]=true;
    }
  }
 
 
 cnt=0;
 for ( i=1;i<=n;i++ )
  have[i]=false;
 
 for ( i=1;i<=m;i++ )
  if ( s[i]=="+" ) s[i]="-";
               else s[i]="+";
 reverse(s+1,s+m+1);
 reverse(x+1,x+m+1);
 
 for ( i=1;i<=m;i++ )
  {
   if ( s[i]=="+" )
    {
     have[x[i]]=true;
     cnt++;
    }
   else if ( have[x[i]] )
    {
     have[x[i]]=false;
     cnt--;
    }
   
   if ( s[i]=="-" )
    {
     if ( cnt>0 ) wrong[x[i]]=true;
    }
   if ( s[i]=="+" )
    {
     if ( cnt>1 ) wrong[x[i]]=true;
    }
  }
 
 
 m=n;
 for ( i=1;i<=n;i++ )
  if ( wrong[i] ) m--;
  
 cout<<m<<endl;
 for ( i=1;i<=n;i++ )
  if ( !wrong[i] )
   cout<<i<<" ";
 cout<<endl;
 
}
