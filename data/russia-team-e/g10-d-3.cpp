#include<fstream>
#include<algorithm>
using namespace std;
long long n,k,i,ans;
long long mas[100001];

main()
{ifstream f1("fence.in");
 ofstream f2("fence.out");
 f1>>n>>k;
 for(i=0;i<n;i++) f1>>mas[i];
 ans=mas[0];
 sort(mas,mas+n);
 ans=mas[0];

 for(i=n-2;i>=0;i--)
  if(((k-mas[i])/(n-i-1)) <ans)
   ans=(k-mas[i])/(n-i-1);

 if(ans>(k/n)) ans=k/n;
 f2<<ans<<endl;
}
