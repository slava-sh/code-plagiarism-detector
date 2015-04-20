#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
long long n,d,i,ans,a,a1;
long long mas[100001];

main()
{ifstream f1("sochi.in");
 ofstream f2("sochi.out");
 f1>>n>>d;
 for(i=0;i<n;i++)
  f1>>mas[i];
 sort(mas,mas+n);
  
  
 for(i=n-1;i>=0;i--)
  if(mas[i]>=3*d) {ans+=mas[i]-2*d; a++;}
  else if(mas[i]>d && a1<2) {ans+=mas[i]-d; a1++;}
 //cout<<a1<<" "<<ans<<endl;

 if(a>0) f2<<ans+(2-a1)*d<<endl;
 if(a==0) f2<<mas[n-1]<<endl;
 //system("pause");
}
