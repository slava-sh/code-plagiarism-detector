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

vector < pair <int, int> > gr[5011];
int a[5011], i, n, m, b[5], k1, k2, k3;
const int INF = pow (10,9)+7;
int mini = INF, s, t;

void dk(int v, int p)
{
    set < pair <int, int> > q;
    int i, j, cur, to, len, d[5050];
            for (j=1; j<=n; j++) d[j]=INF;
            d[v]=0;
            q.insert(make_pair(d[v], v));
            while (q.size()>0)
            {
                cur=q.begin()->second;
                q.erase(q.begin());
                for (j=0; j<gr[cur].size(); j++)
                {
                    to=gr[cur][j].first;
                    len=gr[cur][j].second;
                    if (d[to]>d[cur]+len)
                    {
                        q.erase(make_pair(d[to], to));
                        d[to]=d[cur]+len;
                        q.insert (make_pair(d[to], to));
                    }
                }
            }
        for (j=1; j<=n; j++)
        if (a[j]==3-p)
        {
            //cout << j << endl;
            if (mini>d[j])
            {
                s=v;
                t=j;
                mini=d[j];
            }
        }
}

int main ()
{
    //freopen ("input.txt", "r", stdin);
    freopen ("secure.in", "r", stdin);
    ofstream cout("secure.out");
    scanf ("%d %d", &n, &m);
    for (i=1; i<=n; i++) scanf ("%d", &a[i]);
    for (i=1; i<=n; i++) b[a[i]]++;
    for (i=1; i<=m; i++)
    {
        scanf ("%d %d %d", &k1, &k2, &k3);
        gr[k1].push_back(make_pair(k2, k3));
        gr[k2].push_back(make_pair(k1, k3));
    }
    if (b[1]>b[2])
    {
        for (i=1; i<=n; i++) if (a[i]==1) dk(i, 1);
        if (mini!=INF) { cout << s << " " << t << " " << mini << endl; return 0; }
    }
    else
    {
        for (i=1; i<=n; i++) if (a[i]==2) dk(i, 2);
        if (mini!=INF) { cout << t << " " << s << " " << mini << endl; return 0; }
    }
        cout << "-1" << endl;
    return 0;
}
