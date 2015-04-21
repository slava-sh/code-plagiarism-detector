#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int> > > graph;

int main()
{
    int N, M;
    long long D;
    cin >> N >> M >> D;
    graph.resize(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back(make_pair(b - 1, c));
        graph[b - 1].push_back(make_pair(a - 1, c));
    }
    int Q;
    cin >> Q;
    for (int k = 0; k < Q; k++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        queue<pair<int, int> > q;
        queue<int> q1;
        bool is_good = false;
        int ans = -1;
        vector<set<int> > temp(N);
        q.push(make_pair(A, 1000000001));
        q1.push(0);
        while (q.size() > 0 && !is_good)
        {
            if (q.front().first == B)
            {
                is_good = true;
                break;
            }
            for (int i = 0; i < graph[q.front().first].size(); i++)
            {
                if (temp[graph[q.front().first][i].first].find(graph[q.front().first][i].second) == temp[graph[q.front().first][i].first].end() && (q.front().second == 1000000001 || abs(q.front().second - graph[q.front().first][i].second) <= D))
                {
                    q.push(make_pair(graph[q.front().first][i].first, graph[q.front().first][i].second));
                    q1.push(q1.front() + 1);
                    temp[graph[q.front().first][i].first].insert(graph[q.front().first][i].second);
                }
            }
            q.pop();
            q1.pop();
        }
        if (is_good)
        {
            cout << q1.front() << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
