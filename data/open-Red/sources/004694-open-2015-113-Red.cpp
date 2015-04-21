#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> >graph[100005];

int n, m, d;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    int cnt;
    cin >> cnt;
    queue<pair<int, int> > q;
    map<pair<int, int>, int> ans;
    for(;cnt;cnt--)
    {
        int fr, to;
        cin >> fr >> to;
        fr--;to--;
        ans.clear();
        while(q.size()) q.pop();
        for(int i=0;i<graph[fr].size();i++)
        {
            q.push(make_pair(fr, graph[fr][i].second));
            ans[make_pair(fr, graph[fr][i].second)] = 1;
        }
        bool done = 0;
        while(q.size())
        {
            pair<int, int> c = q.front();
            q.pop();
            for(int i=0;i<graph[c.first].size();i++)
            {
                if(abs(c.second - graph[c.first][i].second) <= d && !ans.count(graph[c.first][i]))
                {
                    ans[graph[c.first][i]] = ans[c] + 1;
                    q.push(graph[c.first][i]);
                    if(graph[c.first][i].first == to)
                    {
                        cout << ans[c] << '\n';
                        done = 1;
                        while(q.size())
                            q.pop();
                        break;
                    }
                }
            }
        }
        if(!done)
        {
            cout << "-1\n";
        }
    }
    return 0;
}
