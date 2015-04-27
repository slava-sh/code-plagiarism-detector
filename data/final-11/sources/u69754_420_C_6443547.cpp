#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef unsigned long long  LL;
using namespace std ;
typedef pair<int,int> PII;


map<int,int> e[310000];
int N,M,x,y,i,j,c[310000],T[310000];

int lowbit(int x){
    return x&-x;
}

void add(int x,int d){
    for (;x<=N;x+=lowbit(x)) T[x]+=d;
}

int get(int x){
    int res=0;
    for (;x;x-=lowbit(x)) res+=T[x];
    return res;
}

int get(int x,int y){
    return get(y)-get(x-1);
}

int main(){
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++){
        scanf("%d%d",&x,&y);
        ++c[x]; ++c[y];
        if (x<y) ++e[y][x];
        else ++e[x][y];
    }
    LL ans=0;
    for (i=1;i<=N;i++){
        LL t=0;
        for (map<int,int>::iterator it=e[i].begin();it!=e[i].end();it++){
            j=it->first;
            if (c[i]+c[j]-e[i][j]>=M) ++ans;
            if (c[i]+c[j]>=M) ++t;
        }
        if (M-c[i]>0) ans+=get(M-c[i],N)-t;
        else ans+=get(1,N)+T[0]-t;
        if (c[i]) add(c[i],1);
        else ++T[0];
    }
    printf("%I64d\n",ans);

}
