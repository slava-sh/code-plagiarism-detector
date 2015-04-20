#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>
#include <cstdlib>
#include <deque>
using namespace std;

int n, i, a, b, f, s, p[200011], d[200011], k, ans[200011], maxi=0, q, m[200010];
vector <int> gr[200011];
vector <int> way;
vector <int> kkk;
bool check[200011];

void doit(int cur)
{
    deque <int> sz;
    sz.push_back(cur);
    for (int j=1; j<=n; j++) d[j]=n+100;
    d[cur]=0;
    while (sz.size()>0)
    {
        int v = sz.front();
        sz.pop_front();
        for (int i=0; i<gr[v].size(); i++)
        {
            int to = gr[v][i];
            if (d[to]>d[v]+1)
            {
                p[to]=v;
                d[to]=d[v]+1;
                sz.push_back(to);
            }
        }
    }
}

void dfs(int cur, int p)
{
    int k=0;
    ans[cur]=0;
    for (int i=0; i<gr[cur].size(); i++)
    {
        if ((gr[cur][i]!=p) && (check[gr[cur][i]]==false))
        {
            dfs(gr[cur][i], cur);
            ans[cur]=max(ans[cur], ans[gr[cur][i]]+1);
        }
    }
}

int main ()
{
    //freopen ("secure.in", "r", stdin);
    freopen ("dwarfs.in", "r", stdin);
    ofstream cout("dwarfs.out");

    scanf ("%d", &n);
    for (i=1; i<n; i++)
    {
        scanf ("%d %d", &a, &b);
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for (i=1; i<=n; i++) check[i]=false;
    scanf ("%d %d", &f, &s);
    doit(f);
    p[f]=f;
    k=p[s];
    while (k!=f)
    {
        way.push_back(k);
        k=p[k];
    }
    way.push_back(f);
    reverse(way.begin(), way.end());
    way.push_back(s);
    for (i=0; i<way.size(); i++) check[way[i]]=true;
    for (i=1; i<=n; i++) if (check[i]) dfs(i, i);
    q=way.size()-1;
    for (i=0; i<way.size(); i++)
    {
        kkk.push_back(ans[way[i]]+q);
        q--;
    }
    q=way.size()-1;
    for (i=0; i<=q; i++) m[i]=kkk[i];
    for (i=q-1; i>=0; i--) m[i]=max(m[i+1], m[i]);
    for (i=0; i<q; i++)
    {
        maxi=max(maxi, min(ans[way[i]]+i, m[i+1]));
    }
        cout << maxi+1 << endl;
    return 0;
}
