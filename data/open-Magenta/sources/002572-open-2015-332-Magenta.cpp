#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int q,w,e,r,t;
  char a[10];
  while(1){
   e=1;
   for(w=0;w<e;w++){
    cout<<"U";
    cin>>a;
    fflush(stdout);
    if(a[0]!='N')
     return 0;}
   for(w=0;w<e;w++){
    cout<<"L";
    cin>>a;
    fflush(stdout);
    if(a[0]!='N')
     return 0;}
   e++;
   for(w=0;w<e;w++){
    cout<<"D";
    cin>>a;
    fflush(stdout);
    if(a[0]!='N')
     return 0;}
   for(w=0;w<e;w++){
    cout<<"R";
    cin>>a;
    fflush(stdout);
    if(a[0]!='N')
     return 0;}
   e++;}
  return 0;}
