#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

#define SZ 2000007
using namespace std;

int tree[(1<<22) + 7];
int MaxVal=(1<<22);
int bitMask;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int find(int cumFre){
    int idx = 0; // this var is result of function
    int ret=MaxVal;
    while ((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
        int tIdx = idx + bitMask; // we make midpoint of interval
        if (cumFre == tree[tIdx]) // if it is equal, we just return idx
            {
                ret=min(ret,tIdx);
            }
        else if (cumFre > tree[tIdx]){
                // if tree frequency "can fit" into cumFre,
                // then include it
            idx = tIdx; // update index
            cumFre -= tree[tIdx]; // set frequency for next loop
        }
        bitMask >>= 1; // half current interval
    }

    return ret;
}

struct Node
{
    int origin,val;
};

Node Nt[SZ+7];

int n,m;

int X[1000007] , Y[1000007];

int ar[1000007];

set<int> NotFill;
set<int> :: iterator it;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]);
    int left = 1000002;

    for(int i=0;i<=SZ;i++) {
        Nt[i].origin = -1;
        Nt[i].val = -1;
    }

    for(int i=1;i<=n;i++) Nt[i+left].origin = i , update(i+left,1);

    bool pl = true;

    for(int i=1;i<=m;i++) {
        bitMask = MaxVal;
        int Fnd = find(Y[i]);
        if(Fnd==MaxVal) {
            pl = false;
            break;
        }

        if(Nt[Fnd].val!=-1 && Nt[Fnd].val != X[i]) {
            pl = false;
            break;
        }
        update(Fnd,-1);
        Nt[left].origin = Nt[Fnd].origin;
        Nt[left].val = X[i];
        update(left,1);
        left--;

    }
    if(!pl) {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++) NotFill.insert(i);

    for(int i=1;i<=2000007;i++) {
        if(Nt[i].origin==-1) continue;
        if(read(i) - read(i-1)==1) {
            if(Nt[i].val!=-1) {
                it = NotFill.find(Nt[i].val);
                if(it==NotFill.end())
                {
                    printf("-1\n");
                    return 0;
                }
                ar[Nt[i].origin] = Nt[i].val;
                //Fill.insert(Nt[i].val);
                NotFill.erase(it);

            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(ar[i]==0) {
            if(NotFill.size()==0) {
                printf("-1\n");
                return 0;
            }
            it = NotFill.begin();

            ar[i] = *it;
            NotFill.erase(it);
        }
    }
    for(int i=1;i<=n;i++) {
        if(i!=1) printf(" ");
        printf("%d",ar[i]);
    }
    printf("\n");

    return 0;
}
