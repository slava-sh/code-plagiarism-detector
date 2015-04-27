#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long LL;
#define N 1000505

struct Treap
{
    int nodecnt;
    int L[N] , R[N] , cnt[N];
    int key[N];
    void clear() {
        nodecnt = 0;
    }
    Treap () {clear();}
    bool hey(int A , int B) {
        return (LL)rand() * (cnt[A] + cnt[B]) < (LL)cnt[A] * RAND_MAX;
    }
    int newnode(int val) {
        nodecnt = val , L[nodecnt] = R[nodecnt] = 0;
        cnt[nodecnt] = 1 , key[nodecnt] = val;
        return nodecnt;
    }
    void pushup(int x) {
        cnt[x] = 1;
        if (L[x]) cnt[x] += cnt[L[x]] ;
        if (R[x]) cnt[x] += cnt[R[x]] ;
    }
    void merge(int& p , int x , int y) {
        if (!x || !y)
            p = x | y;
        else if ( hey(x , y) ) // key[x] < key[y]
            merge(R[x] , R[x] , y) , pushup(p = x);
        else
            merge(L[y] , x , L[y]) , pushup(p = y);
    }
    void split(int p , int& x , int& y , int size) {
        if (!size) {
            x = 0 , y = p;
            return;
        }
        if (cnt[L[p]] >= size)
            y = p , split(L[p] , x , L[y] , size) , pushup(y);
        else
            x = p , split(R[p] , R[x] , y , size - cnt[L[p]] - 1) , pushup(x);
    }
    void Build(int& p , int l , int r) {
        int mid = (l + r) >> 1;
        p = newnode(mid);
        if (l < mid) Build(L[p] , l , mid - 1);
        if (mid < r) Build(R[p] , mid + 1 , r);
        pushup(p);
    }
};
Treap T;
int n , m , a[N];
int ans[N];
bool used[N];
void work()
{
    int i , j , k , x , y , z;
    int root = 0;
    scanf("%d%d",&n,&m);
    T.Build(root , 1 , n);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&j,&k); // a[k] = j;
        T.split(root , x , z , k);
        T.split(x , x , y , k - 1); // y -> a[k]
        if (ans[y] && ans[y] != j)
            break;
        if (!ans[y]) {
            if (used[j])
                break;
            used[j] = 1 , ans[y] = j;
        }
        T.merge(x , y , x);
        T.merge(root , x , z);
    }
    if (i < m) {
        puts("-1");
        return;
    }
    j = 1;
    for (i = 1 ; i <= n ; ++ i) {
        if (!ans[i]) {
            while (used[j])
                ++ j;
            used[j] = 1 , ans[i] = j;
        }
        printf("%d%c" , ans[i] , " \n"[i == n]);
    }

}

int main()
{
    work();
    return 0;
}
