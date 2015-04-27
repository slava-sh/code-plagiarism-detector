// Bekzhan Bekbolatuly

#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <time.h>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define INF 1e6
#define mod 1000000007
#define abs(x) ((x)>=0?(x):-(x))
#define fi first
#define se second

typedef long long ll;

ll n,m,a[2111111],last,npr,x,y,ch,w[1111111],b[1111111],r=1;

struct item
{
    ll cnt,x;
}t[9999999];

ll gcd(ll a, ll b)
{
    if(!b)
    return a;
    return gcd(b,a%b);
}

void build(ll v, ll l, ll r)
{
    if(l==r)
    {
        t[v].cnt=a[l];
        t[v].x=-1;
        return;
    }
    ll mid=(l+r)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    t[v].cnt+=t[v*2].cnt+t[v*2+1].cnt;
}

void upd(ll v, ll l, ll r, ll x, ll y)
{
    if(l==r)
    {
        t[v].cnt^=1;
        t[v].x=y;
        return;
    }
    ll mid=(l+r)/2;
    if(x<=mid)
        upd(v*2,l,mid,x,y);
    else
        upd(v*2+1,mid+1,r,x,y);
    t[v].cnt=t[v*2].cnt+t[v*2+1].cnt;
}

void fin(ll v, ll l, ll r, ll x, ll y)
{
    if(l==r)
    {
        if(w[y]&&t[v].x==-1)
            ch=1;
        if(t[v].x!=y&&t[v].x!=-1)
            ch=1;
        if(t[v].x==-1)
        {
            b[l-(ll)INF]=y;
        }
        upd(1,1,npr,l,y);
        last--;
        upd(1,1,npr,last,y);
        return;
    }
    ll mid=(l+r)/2;
    if(t[v*2].cnt>=x)
        fin(v*2,l,mid,x,y);
    else
        fin(v*2+1,mid+1,r,x-t[v*2].cnt,y);
}

int main()
{
    cin>>n>>m;
    npr=INF+n;
    last=INF+1;
    for(ll i=INF+1;i<=npr;i++)
        a[i]=1;
    build(1,1,npr);
    for(ll i=1;i<=m;i++)
    {
        scanf("%I64d%I64d",&x,&y);
        fin(1,1,npr,y,x);
        w[x]=1;
    }
    if(ch)
    {
        cout<<-1;
        return 0;
    }
    for(ll i=1;i<=n;i++)
    {
        if(b[i]>0)
            printf("%I64d ",b[i]);
        else
        {
            while(w[r]==1)
                r++;
            printf("%I64d ",r);
            r++;
        }
    }
}
