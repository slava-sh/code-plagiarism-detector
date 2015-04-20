#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int n,m,j,b,i,s,a,f;
pair<string, int> p[10002];
pair<string, pair<string, string> > p1[10002];
string x[10002],k,z,l;
main(){
       
freopen("numbers.in","r",stdin);      
freopen("numbers.out","w",stdout); 

cin>>n;
for(i=0;i<n;i++){
cin>>k>>s;
for(a=0;a<s;a++){
cin>>z;
p1[f+a].first=k+z;
p1[f+a].second.first=k;
p1[f+a].second.second=z;
}f+=a;
}

cin>>m;
for(i=0;i<m;i++){
cin>>x[i];
p[i].first=x[i];
p[i].second=i;
}
sort(p,p+m);
sort(p1,p1+f);

for(i=0;i<m;i++){
b=p1[j].first.size();
l=p[i].first.substr(0,b);
//cout<<"*"<<p1[j].first<<" "<<l<<"*"<<endl;
if(l!=p1[j].first){if(l>p1[j].first) {j++;i--;}else x[p[i].second]="Incorrect";continue;} else{
                   x[p[i].second]="+"+x[p[i].second];
                   x[p[i].second].insert(p1[j].second.first.size()+1,"(");
                   x[p[i].second].insert(b+2,")");
                   if(x[p[i].second][b+3]=='0') {x[p[i].second]="Incorrect";continue;}
                   if(x[p[i].second].size()-3-b<3){x[p[i].second]="Incorrect";continue;}
                   for(a=x[p[i].second].size()-2;a>b+4;a-=2){
                   x[p[i].second].insert(a,"-");
                   }}}

for(i=0;i<m;i++){
cout<<x[i]<<endl;
}
                   
}

