#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
#define N 600010
#define M 2200000
int cnt3[N],cnt2[N],cnt1[N],r,s[N],t[N],v[N],edgenum,e[M],next[M],head[N];
pair<int,int>data[N];
void add(int b,int c)
{
    e[edgenum]=c;
    next[edgenum]=head[b];
    head[b]=edgenum++;
}
void init()
{
    memset(head,0,sizeof(head));
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    memset(cnt3,0,sizeof(cnt3));
    edgenum=1;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        long long ans=0;
        init();
        for (int i=1; i<=n; ++i)
        {
            scanf("%d%d",&data[i].first,&data[i].second);
            add(data[i].first,data[i].first);
            add(data[i].second,data[i].second);
            add(data[i].first,data[i].first);
            add(data[i].second,data[i].second);
            add(data[i].second,data[i].first);
            add(data[i].first,data[i].second);
            cnt1[data[i].first]++,cnt2[data[i].second]++;
        }
        for (int i=1; i<=n; ++i)
            add(i,i);
        for (int i=1; i<=n; ++i)
            cnt1[i]+=cnt2[i],cnt2[i]=cnt1[i];
        for (int i=1; i<=n; ++i)
            cnt3[cnt1[i]]++;
        for (int i=n; i>=0; --i)
            cnt3[i]+=cnt3[i+1];
        for (int i=1; i<=n; ++i)
        {
            ans+=cnt3[max(0,m-cnt2[i])];
            for(int j=head[i]; j; j=next[j])
                if (v[e[j]]!=i)
                    v[e[j]]=i,t[s[++r]=e[j]]=1;
                else
                    t[e[j]]++;
            for (int j=1; j<=r; j++)
                if (cnt1[s[j]]+cnt2[i]>=m&&cnt1[s[j]]+cnt2[i]-t[s[j]]<m)
                    ans--;
            r=0;
        }
        printf("%I64d\n",ans/2);
    }
}
