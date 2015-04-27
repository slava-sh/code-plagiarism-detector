#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
const double PI = acos(-1.0);
const int Max = 100010;
int A[Max],F[Max],V[Max];
int Heap[Max],id[Max],hn;
bool near(int x,int y){
    return V[x] > V[y];
}
void sink(int p){
    int q = p << 1,r = Heap[p];
    while (q <= hn){
        if (q < hn)
            q += near(Heap[q+1],Heap[q]);
        if (near(r,Heap[q]))
            break;
        id[Heap[p] = Heap[q]] = p;
        p = q,q <<= 1;
    }
    id[Heap[p] = r] = p;
}
void swim(int q){
    int p = q >> 1,r = Heap[q];
    while (p && near(r,Heap[p])){
        id[Heap[q] = Heap[p]] = q;
        q = p,p >>= 1;
    }
    id[Heap[q] = r] = q;
}
void insert(int x){
    swim(id[Heap[++hn] = x] = hn);
}
int delMin(){
    if (hn == 0) return -1;
    int x = Heap[1];
    id[Heap[1] = Heap[hn--]] = 1;
    sink(1);
    return x;
}
void dealElmt(int x,int f){
    if (f == 0)//insert
        swim(id[Heap[++hn] = x] = hn);
    else if (f == 1){//remove
        if (id[x] < hn){
            int d = Heap[hn--];
            id[Heap[id[x]] = d] = id[x];
            sink(id[x]);
            swim(id[x]);
        }else
            --hn;
    }else if (f == 2){//update
        sink(id[x]);
        swim(id[x]);
    }else{//error
        while (1);
    }
}
struct box{
    int a,b,c;
    box(){}
    box (int a,int b,int c):a(a),b(b),c(c){}
    void out(){
        printf("%d %d %d\n",a,b,c);
    }
};
box Res[Max];
int main(){
    int N;
	while (scanf("%d",&N) != EOF){
	    for (int i = 0;i < N;i++)
            scanf("%d",&A[i]);
        sort(A,A+N);
        int M = 0;
        for (int i = 0;i < N;){
            ++M;
            F[M] = A[i],V[M] = 0;
            while (i < N && A[i] == F[M])
                V[M]++,i++;
        }
        //for (int i = 1;i <= M;i++) printf("%d %d\n",F[i],V[i]);
        hn = M;
        for (int i = 1;i <= hn;i++)
            Heap[i] = i;
        for (int i = hn >> 1;i > 0;i--) sink(i);
        int nR = 0;
        while (hn >= 3){
            int a = delMin();
            int b = delMin();
            int c = delMin();
            if (a < b) swap(a,b);
            if (b < c) swap(b,c);
            if (a < b) swap(a,b);
            Res[nR] = box(F[a],F[b],F[c]);
            if (--V[a] > 0) dealElmt(a,0);
            if (--V[b] > 0) dealElmt(b,0);
            if (--V[c] > 0) dealElmt(c,0);
            ++nR;
        }
        printf("%d\n",nR);
        for (int i = 0;i < nR;i++)
            Res[i].out();
	}
	return 0;
}
