#include <iostream>
#include <algorithm>
#include <cstdio>
#include<cmath>
#include<set>
#include<vector>

using namespace std;
set <pair <long long, int> > s;
vector<pair<int, long long> > v[6000];
#define m_p make_pair
int b[6000];
int p[6000];
long long dist[6000];
const long long INF = (long long)20000000000;
int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);

    int n, m, i, x, y, j;
    int min_i;
    long long w, min_t;
    pair<int, long long> go;
    pair<long long, int> min_p;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> b[i];
        if(b[i] == 1)
        {
            dist[i] = 0;
            p[i] = i + 1;
        }
        else
            dist[i] = INF;
        s.insert(m_p(dist[i], i));
    }
    for(i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        x--, y--;
        v[x].push_back(m_p(y, w));
        v[y].push_back(m_p(x, w));
    }
    for(i = 0; i < n; i++)
    {
        if(s.size() == 0)
            break;
        min_i = -1;
        min_p = *s.begin();
        min_i = min_p.second;
        min_t = min_p.first;
        s.erase(min_p);
        for(j = 0; j < v[min_i].size(); j++)
        {
            go = v[min_i][j];
            if(dist[go.first] > min_t + go.second)
            {
                p[go.first] = p[min_i];
                s.erase(m_p(dist[go.first], go.first ));
                dist[go.first] = min_t + go.second;
                s.insert(m_p(dist[go.first],go.first));
            }
        }
    }
    min_t = INF;
    min_i = -1;
    for(i = 0; i < n; i++)
    {
        if(dist[i] < min_t && b[i] == 2)
        {
            min_t = dist[i];
            min_i = i;
        }
    }
    if(min_t == INF)
        cout << "-1";
    else
        cout << endl << p[min_i] << " " << min_i + 1 << " " << min_t;
    return 0;
}
