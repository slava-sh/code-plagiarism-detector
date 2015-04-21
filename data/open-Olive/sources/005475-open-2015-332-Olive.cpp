#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cmath>
using namespace std;
int a[1000000];
int l(int w){
  return abs(a[w]-w);
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int q,w,e,r,t=-1,c=-1,v=-1;
  cin>>q;
  for(w=0;w<q;w++){
   scanf("%d",&a[w]);
   a[w]--;}
  for(w=0;w<q-1;w++)
   for(e=w+1;e<q;e++)
    if(t<l(w)+l(e)-abs(a[w]-e)-abs(a[e]-w)){
     t=l(w)+l(e)-abs(a[w]-e)-abs(a[e]-w);
     c=w;v=e;}
  if(t==-1)
   cout<<"-1 -1";
  else
   cout<<c+1<<" "<<v+1;
  return 0;}
