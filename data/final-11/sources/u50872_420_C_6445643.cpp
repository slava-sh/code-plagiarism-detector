//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>
#include<vector>
#include <algorithm>
using namespace std;
typedef long long ll;

#define mod 1000000007
#define N 300010

vector<int> e[N];
pair<int,int> a[N];
int f[N];
int main() {
    int n, m,x,y;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) a[i].first=0,a[i].second=i;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
        a[x].first++;
        f[x]++;
        a[y].first++;
        f[y]++;
    }
    sort(a+1,a+n+1);
    int r=n;
    //for(int i=1;i<=n;i++)
        //printf("%d ",a[i].first);
    //puts("");
    ll ans=0;
    for(int i=1;i<=n;i++){
        while(r>0&&a[i].first+a[r].first>=m)
            r--;
        ans+=n-r;
        //printf("%d %d\n",i,n-r);
        if(r<i) ans--;
        int t=a[i].second;
        for(int j=0;j<e[t].size();j++){
            if(a[i].first+f[e[t][j]]==m) ans--;
            f[e[t][j]]--;

        }
        for(int j=0;j<e[t].size();j++){
            f[e[t][j]]++;
        }
    }
    printf("%I64d\n",ans/2);
    return 0;
}
