#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <cmath>
using namespace std;
char a[200001],s[200001];
int a1[200001],s1[200001];
int a2[200001],s2[200001];
int h5[200001],h[200001],f[26],f1[26];
int k(int q){
  if(f[f[q]]!=f[q])
   f[q]=k(f[q]);
  return f[q];
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int q,w,e,r,c,v,t=0,d[26];
  for(e=0;e<26;e++)
   d[e]=-1;
  cin>>q>>w;
  scanf("%s%s",a,s);
  for(e=0;e<q;e++){
   a[e]-=97;
   h5[e]=0;}
  for(e=0;e<w;e++){
   s[e]-=97;
   d[s[e]]=e;}
  for(c=0;c<26;c++){
   if(d[c]<0){
    for(e=0;e<q;e++)
     h5[e]++;
    continue;}
   for(e=0;e<w;e++)
    if(s[e]==c)
     s1[e]=1;
    else
     s1[e]=0;
   r=s2[0]=0;
   for(e=1;e<w;e++){
    while((r>0)&&(s1[r]!=s1[e]))
     r=s2[r-1];
    if(s1[r]==s1[e])
     r++;
    s2[e]=r;}
   
   for(v=0;v<26;v++){
    for(e=0;e<q;e++)
     if(a[e]==v)
      a1[e]=1;
     else
      a1[e]=0;
    r=0;
    for(e=0;e<q;e++){
     while((r>0)&&(s1[r]!=a1[e]))
      r=s2[r-1];
     if(s1[r]==a1[e])
      r++;
     if(r==w){
      h5[e-w+1]++;
      r=s2[r-1];}}}
     
     }
  bool b;
  for(e=0;e<q;e++)
   if(h5[e]==26){
    for(r=0;r<26;r++){
     f[r]=r;
     f1[r]=1;}
    for(r=0;r<26;r++){
     if(d[r]<0)
      continue;
     c=a[d[r]+e];
     if(k(r)!=k(c)){
      f1[k(r)]+=f1[k(c)];
      f[k(c)]=k(r);}}
    b=1;
    for(r=0;r<26;r++)
     if(f1[k(r)]>2){
      b=0;break;}
    if(b){
     h[t]=e;
     t++;}}
  cout<<t<<"\n";
  for(e=0;e<t;e++)
   printf("%d ",h[e]+1);
  return 0;}
