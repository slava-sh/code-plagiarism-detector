#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
long long a,n,d[300001],b=0,c,i,j,m,r,k;
queue<int > q;
main()
{
freopen("che.in","r",stdin);
freopen("che.out","w",stdout);

cin>>n>>r;
for(i=0;i<n;i++){
cin>>d[i];
q.push(d[i]);
a=q.front();
j=1;
while(j==1){
if(d[i]-a>r) {k++;q.pop();a=q.front();} else j++;
}


}
cout<<k;
      

}
