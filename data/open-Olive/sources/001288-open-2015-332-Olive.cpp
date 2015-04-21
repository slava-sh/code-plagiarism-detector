#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cmath>
using namespace std;
int a[1000000],s[1000000],d[1000000];
int l(int w){
  return abs(a[w]-w);
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int q,w,e,r,t=0,c,v;
  cin>>q;
  for(w=0;w<q;w++){
   scanf("%d",&a[w]);
   a[w]--;}
  s[0]=0;
  for(w=1;w<q;w++)
   if(a[s[w-1]]-s[w-1]>a[w]-w)
    s[w]=s[w-1];
   else
    s[w]=w;
  d[q-1]=q-1;
  for(w=q-2;w>=0;w--)
   if(d[w+1]-a[d[w+1]]>w-a[w])
    d[w]=d[w+1];
   else
    d[w]=w;
  /*for(w=0;w<q;w++)
   cout<<s[w]<<" ";
  cout<<"\n";
  for(w=0;w<q;w++)
   cout<<d[w]<<" ";
  cout<<"\n";*/
  for(w=1;w<q-1;w++)
   if(t<l(s[w])+l(d[w+1])-abs(a[s[w]]-d[w+1])-abs(a[d[w+1]]-s[w])){
    t=l(s[w])+l(d[w+1])-abs(a[s[w]]-d[w+1])-abs(a[d[w+1]]-s[w]);
    c=s[w];v=d[w+1];}
  if(t==0)
   cout<<"-1 -1";
  else
   cout<<c+1<<" "<<v+1;
  return 0;}
