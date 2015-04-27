#include <iostream>
#include <fstream>
using namespace std;

//ifstream f("wow.in");
#define LE 100666
#define ll long long
#define MOD ((ll)1000000007)
#define f cin

ll fact[LE],INV[LE],p10[LE];

ll comb(int n,int k)
{
    if (n<k) return 0;
    if (k==0) return 1;
    if (n==k) return 1;

    ll result=fact[n];
    result=(result*INV[k])%MOD;
    result=(result*INV[n-k])%MOD;
    return result;
}


ll invers(ll v1,ll v2)
{
    ll x1=1,y1=0,x2=0,y2=1;

    while (v1&&v2)
    {
        if (v1>=v2)
        {
            ll D=v1/v2;
            x1-=x2*D;
            y1-=y2*D;
            v1%=v2;
        }
        else
        {
            ll D=v2/v1;
            x2-=D*x1;
            y2-=D*y1;
            v2%=v1;
        }
    }
    ll res=0;
    if (v1) res=x1;
    else res=x2;

    res%=MOD;
    if (res<0) res+=MOD;
    return res;
}

ll cif[10][LE];
string str;
ll a[LE];

int main()
{
    ll n,k,result=0;
    ll i,t;

    f>>n>>k;
    f.get();
    f>>str;
    n=str.size();
    for(i=0; i<n; ++i) a[i+1]=str[i]-'0';

    p10[0]=1;
    for(i=1; i<=n; ++i) p10[i]=(p10[i-1]*(ll)10)%MOD;
    fact[0]=1;
    for(i=1; i<=n; ++i) fact[i]=(fact[i-1]*(ll)i)%MOD;

    for(i=1; i<=n; ++i)
        INV[i]=invers(fact[i],MOD);


    for(i=n; i>=1; --i)
        ++cif[a[i]][n-i];

    for(t=1; t<=9; ++t)
        for(i=n; i>=0; --i)
        {
            cif[t][i]+=cif[t][i+1];

            ll nr=cif[t][i];

            if (a[n-i]==t)
            {
                --nr;
                result+=(((t*p10[i])%MOD)*comb(n-i-1,k))%MOD;
                result%=MOD;
            }

            if (nr==0) continue;

            nr=nr*p10[i];
            nr%=MOD;
            nr*=t;
            nr%=MOD;
            nr=nr*comb(n-i-2,k-1);
            result+=nr%MOD;
            result%=MOD;
        }

    cout<<result<<'\n';

    return 0;
}
