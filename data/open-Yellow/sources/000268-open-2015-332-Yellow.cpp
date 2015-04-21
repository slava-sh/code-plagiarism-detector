#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int q,w,e,r,t=0,a[100002];
  cin>>q;
  a[0]=a[q+1]=2000000000;
  for(w=1;w<=q;w++){
   scanf("%d",&a[w]);
   if(a[w]!=a[w-1])
     t++;}
   for(cin>>w;w;w--){
    scanf("%d%d",&e,&r);
    if(a[e-1]==a[e])
     t++;
    if(a[e+1]==a[e])
     t++;
    a[e]=r;
    if(a[e-1]==a[e])
     t--;
    if(a[e+1]==a[e])
     t--;
    printf("%d\n",t);}
  return 0;}
