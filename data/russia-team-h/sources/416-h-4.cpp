#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>
using namespace std;

int n, m, a[5100], s, t, c, i, d[5005], j, v, len, to, b[5], timer;
vector <pair <int, int> > gr[5005];
const int INF = pow (10, 9) + 7;
int mini=INF;
set < pair <int, int> > q;

int main ()
{
    freopen ("secure.in", "r", stdin);
    ofstream cout("secure.out");
    scanf ("%d %d", &n, &m);
    timer=clock();
    for (i=1; i<=n; i++) scanf ("%d", &a[i]);
    b[0]=0;
    b[1]=0;
    b[2]=0;
    for (i=1; i<=n; i++) b[a[i]]++;
    for (i=1; i<=m; i++)
    {
        scanf ("%d %d %d", &s, &t, &c);
        gr[s].push_back(make_pair(t, c));
        gr[t].push_back(make_pair(s, c));
    }
    if (b[1]<b[2])
    {
    for (i=1; i<=n; i++)
    {
        if (a[i]==1)
        {
            for (j=1; j<=n; j++) d[j]=INF;
            d[i]=0;
            q.insert (make_pair(d[i], i));
            while (q.size()>0)
            {
                v=q.begin()->second;
                q.erase(q.begin());
                for (j=0; j<gr[v].size(); j++)
                {
                    to=gr[v][j].first;
                    len=gr[v][j].second;
                    if (d[to]>d[v]+len)
                    {
                        q.erase(make_pair(d[to], to));
                        d[to]=d[v]+len;
                        q.insert(make_pair(d[to], to));
                    }
                }
            }
            for (j=1; j<=n; j++) if (a[j]==2)
            {
                if (mini>d[j])
                {
                    s=i;
                    t=j;
                    mini=d[j];
                }
            }
        }
        if (clock()-timer>=1985) break;
    }
    }
    else
    {
    for (i=1; i<=n; i++)
    {
        if (a[i]==2)
        {
            for (j=1; j<=n; j++) d[j]=INF;
            d[i]=0;
            q.insert (make_pair(d[i], i));
            while (q.size()>0)
            {
                v=q.begin()->second;
                q.erase(q.begin());
                for (j=0; j<gr[v].size(); j++)
                {
                    to=gr[v][j].first;
                    len=gr[v][j].second;
                    if (d[to]>d[v]+len)
                    {
                        q.erase(make_pair(d[to], to));
                        d[to]=d[v]+len;
                        q.insert(make_pair(d[to], to));
                    }
                }
            }
            for (j=1; j<=n; j++) if (a[j]==1)
            {
                if (mini>d[j])
                {
                    s=j;
                    t=i;
                    mini=d[j];
                }
            }
        }
        if (clock()-timer>=1985) break;
    }
    }

    if (mini==INF)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << s << " " << t << " " << mini << endl;
    return 0;
}
