#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

struct Vertex
{
    int sonl,sonr,
        l, r;
    int res, pref, suff;
    bool leaf;
} tree[300000];
int t[100000];

void merge(int v)
{
    tree[v].pref = tree[ tree[v].sonl ].pref;
    tree[v].suff = tree[ tree[v].sonr ].suff;
    tree[v].res  = tree[ tree[v].sonl ].res + tree[ tree[v].sonr ].res -
                   (tree[ tree[v].sonl ].suff == tree[ tree[v].sonr ].pref);
}

void init(int v, int tl, int tr)
{
    tree[v].l = tl;
    tree[v].r = tr;
    tree[v].leaf = tl == tr;
    if(!tree[v].leaf)
    {
        tree[v].sonl = v * 2, tree[v].sonr = v * 2 + 1;
        int x = (tl + tr) / 2;
        init(tree[v].sonl, tl, x);
        init(tree[v].sonr, x + 1, tr);
        merge(v);
    }
    else
    {
        tree[v].res = 1;
        tree[v].pref = tree[v].suff = t[tl];
    }
}

void update(int v, int num, int val)
{
    if(tree[v].leaf)
        tree[v].pref = tree[v].suff = val;
    else
    {

        if(num <= tree[ tree[v].sonl ].r)
            update(tree[v].sonl, num, val);
        else
            update(tree[v].sonr, num, val);

        merge(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    init(1, 0, n - 1);

    int q;
    cin >> q;
    while(q--)
    {
        int p,c;
        cin >> p >> c;
        update(1, p - 1, c);
        cout << tree[1].res << '\n';
    }
    return 0;
}
