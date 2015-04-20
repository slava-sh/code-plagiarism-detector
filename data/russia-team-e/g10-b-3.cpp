#include<fstream>
#include<iostream>
using namespace std;
long long n,i,j,ans,m,jj,j1;
long long mas[300001];

main()
{ifstream f1("che.in");
 ofstream f2("che.out");
 f1>>n>>m;
 for(i=1;i<=n;i++) f1>>mas[i];

 for(i=1;i<=n;i++)
 {j=i+(n-i+1)/2;
  jj=j;
  j1=n;




  while(true)
  {//cout<<j<<" "<<i<<endl;
   //system("pause");
   if(mas[j]-mas[i]>m)
   {//cout<<j<<" "<<jj<<" "<<j1<<endl; 
    ans+=j1-j+1; j1=j-1;
    
    jj=j;
    if(j==n) break;
    j=(jj-i+1)/2;
    cout<<j<<endl;}

   else
   {j+=(j1-j+1)/2;
    if(j==jj) break;
    jj=j;}
   if(j==i) break;}}

 f2<<ans<<endl;

}
