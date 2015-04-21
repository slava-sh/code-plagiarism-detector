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
    fflush(stdout);
    cout.flush();
    cin>>a;
    if(a[0]!='N')
     return 0;}
   for(w=0;w<e;w++){
    cout<<"L";
    fflush(stdout);
    cout.flush();
    cin>>a;
    if(a[0]!='N')
     return 0;}
   e++;
   for(w=0;w<e;w++){
    cout<<"D";
    fflush(stdout);
    cout.flush();
    cin>>a;
    if(a[0]!='N')
     return 0;}
   for(w=0;w<e;w++){
    cout<<"R";
    fflush(stdout);
    cout.flush();
    cin>>a;
    if(a[0]!='N')
     return 0;}
   e++;}
  return 0;}
