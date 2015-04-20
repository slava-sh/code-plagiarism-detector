#include<fstream>
using namespace std;
long long n,k,i,ans;
long long mas[100001];
bool b;

main()
{ifstream f1("fence.in");
 ofstream f2("fence.out");
 f1>>n>>k;
 for(i=0;i<n;i++) f1>>mas[i];
 ans=mas[0];

 for(i=1;i<n;i++) if(mas[i]<ans) ans=mas[i];

 for(i=0;i<n;i++)
  if((k-mas[i])<ans)
   if(b) ans=k-mas[i];
   else b=true;

 if(ans>(k/n)) ans=k/n;
 f2<<ans<<endl;
}
