#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
using namespace std;
int a[200000];
void qs(int q,int w){
  int e=q,r=w,t=a[q+(rand()%(w-q+1))],y;
  do{
  while(a[e]<t)e++;
  while(a[r]>t)r--;
  if(e<=r){
   y=a[e];a[e]=a[r];a[r]=y;
   e++;r--;}
  }while(e<=r);
  if(q<r)qs(q,r);
  if(e<w)qs(e,w);
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int q,w,e,r,t,r1=-1000000001;
  long long c,v,e1=0,y=((long long)1)<<62,c1;
  cin>>q>>t>>c>>v;
  for(w=0;w<q;w++){
   scanf("%d%d",&e,&r);
   a[w]=e-r1;
   r1=r;
   e1+=r-e;}
  qs(0,q-1);
  for(w=0;w<q;w++){
   c1=e1*v+c*((q-w-1)/t);
   y=min(y,c1);
   e1+=a[w];}
  cout<<y;
  return 0;}
