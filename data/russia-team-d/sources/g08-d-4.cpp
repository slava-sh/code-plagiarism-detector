#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;
long long a[100005],n,d,b=0,c,i,j,m,r,k,x;

main()                                                                                                                                                                                                    
{
freopen("fence.in","r",stdin);
freopen("fence.out","w",stdout);
cin>>n>>k;
for(i=0; i<n; i++)
{
         cin>>a[i];
}
sort(a,a+n-1);
cout<<min(a[0],k/n);

}


















                                                                                                                                                              
