#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int n,m,n1=1025000;
int idx[2100005];
int st=n1;
int tree_n;
int tree[6000005];
int ans[1000005];
int ans1[1000005];
bool chk[1000005];
void init(int n1){  // 초기화 : 아래에 깔리는 노드가 n1개
    tree_n=1;
    while(tree_n<n1){tree_n*=2;}
    for(int i=0;i<=2*tree_n;i++){tree[i]=0;}
}
void update(int po){  // po 번째값 업데이트
    po+=tree_n-1;
    tree[po]++;
    while(po>1){
        po=po/2;
        tree[po]=tree[po*2]+tree[po*2+1];
    }
}
void update1(int po){  // po 번째값 업데이트
    po+=tree_n-1;
    tree[po]--;
    while(po>1){
        po=po/2;
        tree[po]=tree[po*2]+tree[po*2+1];
    }
}
int query(int op,int po,int l,int r){  // a~b구간, po노드가 ㅣ~r에 대응  => po=1  l=1  r=tree_n
    if(l==r) return l;
    if(op<=tree[po*2]) return query(op,po*2,l,(l+r)/2);
    return query(op-tree[po*2],po*2+1,(l+r)/2+1,r);
}
int main(){
    scanf("%d %d",&n,&m);
    init(2050000);
    for(int i=st;i<st+n;i++){
        idx[i]=i-st+1;
        update(i);
    }
    for(int i=1;i<=m;i++){
        int in1,in2;
        scanf("%d %d",&in1,&in2);
        int id=query(in2,1,1,tree_n);
        if(ans[idx[id]]!=0 && ans[idx[id]]!=in1){
            printf("-1");
            return 0;
        }
        if(ans1[in1]!=0 && ans1[in1]!=idx[id]){
            printf("-1");
            return 0;
        }
        ans[idx[id]]=in1;
        ans1[in1]=idx[id];
        chk[in1]=true;
        if(id!=st){
            idx[st-1]=idx[id];
            st--;
            update1(id);
            update(st);
        }
    }
    int now=1;
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            for(;now<=n;now++){
                if(!chk[now]){
                    chk[now]=true;
                    printf("%d ",now);
                    break;
                }
            }
        }
        else printf("%d ",ans[i]);
    }
    return 0;
}