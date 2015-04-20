#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream in("secure.in");
ofstream out("secure.out");

typedef unsigned long long ull;
ull INF = 1000000000000ll;

int main()
{
    size_t n, m;
    in >> n >> m;

    vector <vector <pair <size_t, ull> > > graph(n);
    vector <char> types(n);

    for (size_t i = 0; i != n; ++i)
        in >> types[i];

    for (size_t i = 0; i != m; ++i)
    {
        size_t start, finish, cost;
        in >> start >> finish >> cost;
        --start;
        --finish;

        graph[start].push_back(pair <size_t, ull>(finish, cost));
        graph[finish].push_back(pair <size_t, ull>(start, cost));
    }

    in.close();

    size_t ansStart, ansEnd;
    ull ans = INF;

    vector <bool> visited(n);
    vector <ull> answer(n);
    set <pair <ull, size_t> > dej;

    for (size_t i = 0; i != n; ++i)
    {
        if (types[i] != '1')
            continue;

        visited.assign(n, false);
        answer.assign(n, INF);

        dej.insert(pair <ull, size_t>(0, i));
        for (size_t j = 0; j != n; ++j)
            if (i != j)
                dej.insert(pair <ull, size_t>(INF, j));

        while (!dej.empty() && dej.begin()->first != INF)
        {
            pair <ull, size_t> curr = *dej.begin();
            dej.erase(dej.begin());

            visited[curr.second] = true;

            for (vector <pair <size_t, ull>>::const_iterator it = graph[curr.second].begin(); it != graph[curr.second].end(); ++it)
            {
                if (!visited[it->first] && answer[it->first] > curr.first + it->second)
                {
                    set <pair <ull, size_t> >::const_iterator findRes = dej.find(make_pair(answer[it->first], it->first));
                    dej.erase(findRes);

                    answer[it->first] = curr.first + it->second;
                    dej.insert(make_pair(answer[it->first], it->first));
                }
            }
        }

        for (size_t j = 0; j != n; ++j)
            if (types[j] == '2')
            {
                if (answer[j] < ans)
                {
                    ans = answer[j];
                    ansStart = i;
                    ansEnd = j;
                }
            }
    }

    if (ans == INF)
    {
        out << "-1";
    }
    else
    {
       out << ansStart + 1 << " " << ansEnd + 1 << " " << ans;
    }

    out.close();

    return 0;
}