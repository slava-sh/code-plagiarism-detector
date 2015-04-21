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
    cout<<"U\n";
    fflush(stdout);
    cout.flush();
    cin>>a;
    fflush(stdout);
    cout.flush();
    if(a[0]!='N')
     return 0;}
   for(w=0;w<e;w++){
    cout<<"L\n";
    fflush(stdout);
    cout.flush();
    cin>>a;
    fflush(stdout);
    cout.flush();
    if(a[0]!='N')
     return 0;}
   e++;
   for(w=0;w<e;w++){
    cout<<"D\n";
    fflush(stdout);
    cout.flush();
    cin>>a;
    fflush(stdout);
    cout.flush();
    if(a[0]!='N')
     return 0;}
   for(w=0;w<e;w++){
    cout<<"R\n";
    fflush(stdout);
    cout.flush();
    cin>>a;
    fflush(stdout);
    cout.flush();
    if(a[0]!='N')
     return 0;}
   e++;}
  return 0;}
