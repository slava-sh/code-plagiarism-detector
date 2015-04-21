#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int o=30000;
int i=1,t=1,t1=0;
int s[o][13],d1[o],g[o];
long long a[o],a1[o],*d[o],h[13],d0[o],ans;
void qs(int q,int w){
  int e=q,r=w,t=g[q+(rand()%(w-q+1))],y;
  do{
  while(a[g[e]]<a[t])e++;
  while(a[g[r]]>a[t])r--;
  if(e<=r){
   y=g[e];g[e]=g[r];g[r]=y;
   e++;r--;}
  }while(e<=r);
  if(q<r)qs(q,r);
  if(e<w)qs(e,w);
}
void qs1(int q,int w){
  int e=q,r=w;
  long long t=d0[q+(rand()%(w-q+1))],y;
  do{
  while(d0[e]<t)e++;
  while(d0[r]>t)r--;
  if(e<=r){
   y=d0[e];d0[e]=d0[r];d0[r]=y;
   e++;r--;}
  }while(e<=r);
  if(q<r)qs1(q,r);
  if(e<w)qs1(e,w);
}
int k(int q){
  int c,v=0;
  for(c=i;c>0;c>>=1)
   if((c+v<t)&&(a[g[c+v]]<=q))
    v+=c;
  return g[v];
}
void l(int q,long long t,long long r,int y){
  if(q==0){
   ans=min(ans,t);
   return;}
  if(t>=ans)
   return;
  if(y==1){
   ans=min(ans,t*a1[q]);
   return;}
  int w;
  for(w=d1[q]-1;d[q][w]>=r;w--)
   l(k(a[q]/d[q][w]),t*((d[q][w]>>1)+1),d[q][w],y-1);
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int w,e,e1,r,v,t2,y;
  long long q,q1,c;
  cin>>q>>y;
  while(((q&1)==0)&&(y>0)){
   q>>=1;
   y--;}
  if((y==0)||(q==1)){
   cout<<q;
   return 0;}
  q1=ans=q;
  a[0]=1;
  g[0]=0;
  for(w=0;w<13;w++)
   s[0][w]=0;
  for(w=3;((long long)w)*((long long)w)<=q;w+=2)
   if(q%w==0){
    h[t1]=w;
    c=1;
    r=t;
    v=0;
    do{
     c*=w;
     v++;
     q/=w;
     for(e=0;e<r;e++){
      a[t]=a[e]*c;
      for(e1=0;e1<13;e1++)
       s[t][e1]=s[e][e1];
      s[t][t1]=v;
      g[t]=t;
      t++;}
    }while(q%w==0);
    t1++;}
  if(q>1){
   r=t;
   h[t1]=q;
   for(e=0;e<r;e++){
    a[t]=a[e]*q;
    for(e1=0;e1<13;e1++)
     s[t][e1]=s[e][e1];
    s[t][t1]=1;
    g[t]=t;
    t++;}
   t1++;}
  //cout<<t1<<"     ****\n";
  /*for(w=0;w<t1;w++)
   cout<<h[w]<<" ";
  cout<<"\n\n";*/
  for(w=0;w<t;w++){
   a1[w]=a[w]/2+1;
   t2=1;
   d0[0]=1;
   for(e=0;e<t1;e++){
    r=t2;
    c=1;
    for(e1=0;e1<s[w][e];e1++){
     c*=h[e];
     for(v=0;v<r;v++){
      d0[t2]=d0[v]*c;
      t2++;}}}
   qs1(0,t2-1);
   d[w]=new long long[t2];
   for(e=0;e<t2;e++)
    d[w][e]=d0[e];
   d1[w]=t2;}
  qs(0,t-1);
  for(i=1;i*2<=t;i*=2);
  /*cout<<t<<"\n";
  for(w=0;w<t;w++){
   cout<<d1[g[w]]<<"  ";
   for(e=0;e<d1[g[w]];e++)
    cout<<d[g[w]][e]<<" ";
   cout<<"\n";}*/
  l(t-1,1,2,y);
  cout<<ans;
  return 0;}
