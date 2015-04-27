#include<iostream>
using namespace std;
#define ll long long
ll a[1000][1000];
ll mod;
char s[1000][1000];
int c[1000];
int r[1000];
int main()
{
    ll i,j,n,m,t;
    cin>>n>>m>>mod;
    a[0][0]=1;
    ll x;
    for(x=1;x<=n;++x)
    {
        for(i=0;i<=2*x;i+=2)
        {
            j=2*x-i;
            j/=2;
            a[i][j]=0;
            if(i>=2)
            {
                ll tmp=i*(i-1)/2;
                tmp=(tmp*a[i-2][j])%mod;
                a[i][j]=(a[i][j]+tmp)%mod;
            }
            if(j>=2)
            {
                ll tmp=j*(j-1)/2;
                tmp=(tmp*a[i+2][j-2])%mod;
                a[i][j]=(a[i][j]+tmp)%mod;
            }
            if(i>=1&&j>=1)
            {
                ll tmp=i*j;
                tmp=(tmp*a[i][j-1])%mod;
                a[i][j]=(a[i][j]+tmp)%mod;
            }
           // cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
        }
    }
    for(i=0;i<m;++i)
        cin>>s[i];
    for(i=0;i<n;++i)
        r[i]=c[i]=0;
    for(i=0;i<m;++i)
        for(j=0;j<n;++j)
        if(s[i][j]=='1')
    {
        r[i]++; c[j]++;
    }
    for(i=0;i<m;++i)
        if(r[i]!=2)
    {
        cout<<0;
        return 0;
    }
    int m1=0,h2=0;
    for(i=0;i<n;++i)
        if(c[i]>2)
    {
        cout<<0;
        return 0;
    }
    else{

        if(c[i]==1)
            m1++;
        else
            if(c[i]==0)
            h2++;
    }
    //cout<<m1<<" "<<h2<<endl;
    cout<<a[m1][h2];
}
