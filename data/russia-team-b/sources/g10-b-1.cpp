#include<fstream>
using namespace std;
long n,i,j,ans;
long long m;
long long mas[300001];

main()
{ifstream f1("che.in");
 ofstream f2("che.out");
 f1>>n>>m;
 for(i=0;i<n;i++) f1>>mas[i];

 for(i=0;i<n-1;i++)
  for(j=n-1;j>i;j--)
   if(mas[j]-mas[i]>m) ans++;
   else break;

 f2<<ans<<endl;
}
