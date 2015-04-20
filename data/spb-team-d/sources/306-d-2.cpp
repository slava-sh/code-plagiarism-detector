#include <iostream>
#include <cstdio>

#define INC true
#define DEC false

using namespace std;

struct poriv
{
    int l;
    int r;
    int x;
};

struct dune
{
    int num;
    int height;
};

int main()
{
    freopen("dunes.in", "r", stdin);
    freopen("dunes.out", "w", stdout);
    int n, m, i, j, x, l, r;
    cin >> n >> m;
    poriv* k = new poriv[n];
    for(i=0; i<n; i++)
    {
        cin >> l >> r >> x;
        k[i].l=l;
        k[i].r=r;
        k[i].x=x;
    }
    dune* H=new dune[m];
    for(i=0; i<m; i++)
    {
        cin >> H[i].num;
        H[i].height=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<=m; j++)
            if(k[i].l<=H[j].num && H[j].num<=k[i].r)
            {
                if((H[j].num-k[i].l)%2==0)
                    H[j].height+=k[i].x;
                else
                    H[j].height-=k[i].x;
            }
    }
    for(i=0; i<m; i++)
        cout << H[i].height << '\n';
    return 0;
}
