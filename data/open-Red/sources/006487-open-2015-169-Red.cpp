#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

int mpos = 0;
char mem[50000000];
inline void *operator new(size_t n)
{
    char *res = mem + mpos;
    mpos += n;
    return (void*)res;
}
inline void operator delete(void*){}

vector< pair<int, int> > ss[50001];
set< pair<int, int> > used;
queue< pair< pair<int, int>, int > > q;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,m,d;
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++)
    {
        int u,v,t;
        cin >> u >> v >> t;
        ss[u].pb(mp(v, t));
        ss[v].pb(mp(u, t));
    }

    int qrs;
    cin >> qrs;
    while(qrs--)
    {
        int a,b;
        cin >> a >> b;
        if(!ss[a].size() || !ss[b].size())
        {
            cout << "-1\n";
            continue;
        }
        used.clear();
        while(!q.empty())
            q.pop();
        for(int i = 0; i < ss[a].size(); i++)
        {
            used.insert(mp(ss[a][i].first, ss[a][i].second));
            q.push(mp(mp(ss[a][i].first, ss[a][i].second), 1));
        }
        int ans = -1;
        while(!q.empty())
        {
            int v = q.front().first.first,
             temp = q.front().first.second,
             dist = q.front().second;
            q.pop();
            if(v == b)
            {
                ans = dist;
                break;
            }
            for(int i = 0; i < ss[v].size(); i++)
            {
                int to = ss[v][i].first,
                    to_temp = ss[v][i].second;
                if(to != a && abs(temp - to_temp) <= d &&
                   !used.insert(mp(to, to_temp)).second)
                    q.push(mp(mp(to, to_temp), dist + 1));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
