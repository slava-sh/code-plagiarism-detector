#include<iostream>
#include<fstream>
using namespace std;
int b[300001];
int f(int k,int l,int p)
    {
if(l==p)return p;
    int m;
    m=(l+p)/2;
    if(b[m]<=k)return f(k,m+1,p);
    return f(k,l,m);
    }
int main()
{
    freopen("che.in","r",stdin);
   freopen("che.out","w",stdout);
    int n, k, i, j ;
    long long s;
    s=0;
      cin>>n>>k>>b[0];
      for(i=1;i<n;i++)
      {
        cin>>b[i];
        s+=f(b[i]-k-1,0,i);
      }
    cout<<s<<endl;

return 0;
}

