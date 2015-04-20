#include<iostream>
#include<fstream>
using namespace std;
int b[300001];
int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    int n, k, i, j , l=2;
    long long s;
    s=0;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>b[i];
    for(i=0;i<n;i++)
    {
    for(j=l;j<n;j++)
    if(b[j]-b[i]>k){break;}
    s+=n-j;
    l=j-1;
    }
    cout<<s<<endl;
return 0;
}

