#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
long long ans;
int t[600005],q[600005],p[600005],n,m,i,j,r,s[300005],T[300005],v[300005],o,e[2200005],next[2200005],head[300005],now;
struct node {int x,y;} a[600005];
void add(int a,int b,int c)
{
    e[a]=c;
    next[a]=head[b];
    head[b]=a;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        add(++o,a[i].x,a[i].x);
        add(++o,a[i].y,a[i].y);
        add(++o,a[i].x,a[i].x);
        add(++o,a[i].y,a[i].y);
        add(++o,a[i].y,a[i].x);
        add(++o,a[i].x,a[i].y);
        p[a[i].x]++; q[a[i].y]++;
    }
    for (i=1; i<=n; i++) add(++o,i,i);
    for (i=1; i<=n; i++) p[i]+=q[i],q[i]=p[i];
    for (i=1; i<=n; i++) t[p[i]]++;
    for (i=n; i>=0; i--) t[i]+=t[i+1];
    for (i=1; i<=n; i++)
    {
        ans+=t[max(0,m-q[i])];
        now=head[i];
        while (now!=0)
        {
            if (v[e[now]]!=i)
            {
                v[e[now]]=i; T[e[now]]=1;
                s[++r]=e[now];
            } else
              T[e[now]]++;
            now=next[now];
        }
        for (j=1; j<=r; j++)
            if (p[s[j]]+q[i]>=m && p[s[j]]+q[i]-T[s[j]]<m) ans--;
        r=0;
    }
    cout<<ans/2;
    return 0;
}
