#include<iostream>
#include<fstream>
using namespace std;
long long n,d,i,ans,a,a1;
long long mas[100001];

main()
{ifstream f1("sochi.in");
 ofstream f2("sochi.out");
 f1>>n>>d;
 for(i=0;i<n;i++)
 {f1>>mas[i];
  if(mas[i]>2*d) {ans+=mas[i]-2*d; a++;}
  else if(mas[i]>d && a1<2) {ans+=mas[i]-d; a1++;}
}

 if(a>0) f2<<ans+(2-a1)*d<<endl;
 if(a==0)
 {for(i=0;i<n;i++)
   if(mas[i]>ans) ans=mas[i];
  f2<<ans<<endl;}
 //system("pause");
}
