#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;
int b[100009], j;

int main()
{
freopen("fence.in","r",stdin);
freopen("fence.out","w",stdout);

int n,k,ans=1000000000,a[100009],an=0;
long long r=0;
cin>>n>>k;
for(int i=0;i<n;i++)
{
cin>>a[i];

if(an==0)r+=a[i];
if(k<=r)an=1;

ans=min(ans,a[i]);
}

if(an==1){
 cout<<ans;
return 0;
}
sort(a,a+n);  
ans=10000000 ;
int l;
	for (int i=0;i<n;i++)
{
if(a[j]==0)
 {
 	j++;
 	a[j]=a[j]-j;
 }
if(b[i]==0)
{ 
b[i]=a[j];
a[j]--;
}      
if(b[i]==b[i-1]&&b[i]!=0)l++;else l=0;
                  ans=min(ans,l+1);

}                
cout<<ans;
}
