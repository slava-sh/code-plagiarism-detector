#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct tree{
    int l, r, k;
}t[500500];

int a[100500];

void recalc(int v){
    t[v].k = t[v+v].k + t[v+v+1].k - (t[v+v].r == t[v+v+1].l);
    t[v].l = t[v+v].l;
    t[v].r = t[v+v+1].r;
}


void build(int v, int l, int r){
    if(l == r){
        t[v].l = a[l];
        t[v].r = a[l];
        t[v].k = 1;
    }
    else{
        int m = (l + r) >> 1;
        build(v+v, l, m);
        build(v+v+1, m+1, r);
        recalc(v);
    }
}

void update(int v, int l, int r, int pos, int nw){
    if(l == r){
        t[v].l = t[v].r = nw;
    }
    else{
        int m = (l + r) >> 1;
        if(pos <= m)
            update(v+v, l, m, pos, nw);
        else
            update(v+v+1, m+1, r, pos, nw);
        recalc(v);
    }
}

int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        int pos, nw;
        scanf("%d%d", &pos, &nw);
        update(1, 1, n, pos, nw);
        printf("%d\n", t[1].k);
    }
    return 0;
}
