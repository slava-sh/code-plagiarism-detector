#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cmath>
using namespace std;
int a[1000000];
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int q,w,e,r,c1,t=0,c=-2,v=-2,y;
  cin>>q;
  for(w=0;w<q;w++)
   scanf("%d",&a[w]);
  for(e=0;e<q;e++)
   for(r=e+1;r<q;r++){
    y=0;
    for(w=0;w<e;w++){
     if(a[w]>a[e])
      y++;
     if(a[w]>a[r])
      y++;}
    for(w=e;w<=r;w++){
     if(a[w]>a[r])
      y++;
     if(a[w]<a[e])
      y++;}
    for(w=r+1;w<=q;w++){
     if(a[w]<a[r])
      y++;
     if(a[w]<a[e])
      y++;}
    w=a[e];a[e]=a[r];a[r]=w;
    for(w=0;w<e;w++){
     if(a[w]>a[e])
      y--;
     if(a[w]>a[r])
      y--;}
    for(w=e;w<=r;w++){
     if(a[w]>a[r])
      y--;
     if(a[w]<a[e])
      y--;}
    for(w=r+1;w<=q;w++){
     if(a[w]<a[r])
      y--;
     if(a[w]<a[e])
      y--;}
    w=a[e];a[e]=a[r];a[r]=w;
    if(t<y){
     t=y;
     c=e;v=r;}}
  cout<<c+1<<" "<<v+1;
  return 0;}
