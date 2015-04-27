#include <iostream>
#include <stdio.h>
using namespace std;
int q,*s=new int[4194304];
int l(int q1){
  q1=q-q1;
  int w=1,e=0,t;
  for(t=1048576;t;t>>=1)
   if(s[(w<<1)+1]<=q1){
    q1-=s[(w<<1)+1];
    w<<=1;}
   else{
    w=(w<<1)+1;
    e+=t;}
  return e+1;
}
void k(int q,int w){
  for(q=2097151+q;q;q>>=1)
   s[q]+=w;
}
int main(){
  int w,e,r,t=1000001,*a=new int[2000002],*d=new int[1000001],*f=new int[1000001];
  for(w=0;w<4194304;w++)
   s[w]=0;
  scanf("%d%d",&q,&w);
  for(e=1;e<=q;e++){
   a[1000001+e]=e;
   k(1000001+e,1);
   d[e]=f[e]=0;}
  bool b=1;
  for(;w;w--){
   scanf("%d%d",&e,&r);
   r=l(r);
   if(d[e]==0)
    d[e]=a[r];
   if(f[a[r]]==0)
    f[a[r]]=e;
   if((d[e]!=a[r])||(f[a[r]]!=e)){
    b=0;break;}
   k(r,-1);
   a[t]=a[r];
   k(t,1);
   t--;}
  if(b==0)
   cout<<-1;
  else{
   w=1;
   for(e=1;e<=q;e++){
    if(f[e]==0){
     for(;d[w];w++);
     f[e]=w;
     w++;}
    printf("%d ",f[e]);}}
  //system("PAUSE");
  return 0;}
