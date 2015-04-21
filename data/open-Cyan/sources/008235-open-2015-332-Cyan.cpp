#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cmath>
using namespace std;
double i=((double)1)/(((long long)1)<<40);
int *a[100000],*s[100000],d[100000],er1,er2;
bool error=0;
int l(int c,int v){
  int w,e=1,r=1,t=a[c][0],u=0;
  if(s[c][0]<s[v][0])
   u|=1;
  if(s[c][0]>s[v][0])
   u|=2;
  double c1=s[c][0],v1=s[v][0],e1=((double)(s[c][1]-s[c][0]))/(a[c][1]-a[c][0]),r1=((double)(s[v][1]-s[v][0]))/(a[v][1]-a[v][0]);
  for(;(e<=d[c])&&(r<=d[v]);)
   if(a[c][e]<a[v][r]){
    c1=s[c][e];
    e1=((double)(s[c][e+1]-s[c][e]))/(a[c][e+1]-a[c][e]);
    v1+=r1*(a[c][e]-t);
    t=a[c][e];
    e++;
    if(c1+i<v1)
     u|=1;
    if(c1>v1+i)
     u|=2;}
    else{
     if(r==d[v])
      break;
     v1=s[v][e];
     r1=((double)(s[v][r+1]-s[v][r]))/(a[v][r+1]-a[v][r]);
     c1+=e1*(a[v][r]-t);
     t=a[v][r];
     r++;
     if(c1+i<v1)
      u|=1;
     if(c1>v1+i)
      u|=2;}
  if(s[c][d[c]]<s[v][d[v]])
   u|=1;
  if(s[c][d[c]]>s[v][d[v]])
   u|=2;
  if(u==3){
   error=1;
   er1=c;
   er2=v;
   return 0;}
  return u;
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int q,w,e,r,t,i1,i2;
  cin>>i1>>i2>>q;
  for(w=0;w<q;w++){
   scanf("%d",&d[w]);
   a[w]=new int[d[w]+1];
   s[w]=new int[d[w]+1];
   for(e=0;e<=d[w];e++)
    scanf("%d%d",&a[w][e],&s[w][e]);}
  for(e=0;e<q;e++)
   for(r=e+1;r<q;r++)
    t=l(e,r);
  if(error)
   cout<<"No\n"<<er1+1<<" "<<er2+1;
  else
   cout<<"Yes";
  return 0;}
