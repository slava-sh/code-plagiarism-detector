#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define N 300009
using namespace std;
long long n,p,ans;
map<int,int> mp[N];
int num[N];
int sum[N];
int main()
{
    cin>>n>>p;
    for(int i=1,ca,cb;i<=n;i++){
        scanf("%d %d",&ca,&cb);
        mp[ca][cb]++;
        mp[cb][ca]++;
        num[ca]++;
        num[cb]++;
    }
    for(int i=1;i<=n;i++)
        sum[num[i]]++;
    for(int i=n;i>=1;i--)
        sum[i]+=sum[i+1];
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(num[i]>=p)ans+=n-1;
        else{
            ans+=sum[p-num[i]];
            if(num[i]>=p-num[i])ans--;
        }
    }
    for(int i=1;i<=n;i++){
        for(map<int,int>::iterator it=mp[i].begin();it!=mp[i].end();it++){
            int k1=(*it).first;
            int pp=(*it).second;
            if(num[i]+num[k1]>=p && num[i]+num[k1]-pp<p)ans--;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
