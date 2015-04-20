#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

//#include <cstdlib>
//#include <ctime>

using namespace std;

ifstream in("secure.in");
ofstream out("secure.out");

typedef unsigned long long ull;
long long INF = 1000000000000ll;

int main()
{
    //srand(218 * 12);

    //clock_t start = clock(), end;

    long long n, m;
    in >> n >> m;

    vector <char> types(n);
    vector <vector <pair <long long, ull> > > graph(n + 2);
    vector <long long> first, second;

    for (long long i = 0; i != n; ++i)
    {
        in >> types[i];

        if (types[i] == '1')
        {
            first.push_back(i);
            graph[n].push_back(make_pair(i, 0));
            graph[i].push_back(make_pair(n, 0));
        }
        else if (types[i] == '2')
        {
            second.push_back(i);
            graph[i].push_back(make_pair(n + 1, 0));
            graph[n + 1].push_back(make_pair(i, 0));
        }
    }

    for (long long i = 0; i != m; ++i)
    {
        long long start, finish, cost;
        in >> start >> finish >> cost;
        --start;
        --finish;

        if (types[start] != '0' && types[start] == types[finish])
            continue;

        graph[start].push_back(pair <long long, ull>(finish, cost));
        graph[finish].push_back(pair <long long, ull>(start, cost));
    }

    in.close();

    vector <bool> visited(n);
    vector <ull> answer(n);
    set <pair <ull, long long> > dej;

    visited.assign(n + 2, false);
    answer.assign(n + 2, INF);

    dej.insert(pair <ull, long long>(0, n));
    answer[n] = 0;

    vector <long long> last(n + 2);

    while (!dej.empty() && dej.begin()->first != INF)
    {
        pair <ull, long long> curr = *dej.begin();
        dej.erase(dej.begin());

        visited[curr.second] = true;

        for (vector <pair <long long, ull>>::const_iterator it = graph[curr.second].begin(); it != graph[curr.second].end(); ++it)
        {
            if (!visited[it->first] && answer[it->first] > curr.first + it->second)
            {
                set <pair <ull, long long> >::const_iterator findRes = dej.find(make_pair(answer[it->first], it->first));

                if (findRes != dej.end())
                    dej.erase(findRes);

                answer[it->first] = curr.first + it->second;
                dej.insert(make_pair(answer[it->first], it->first));

                last[it->first] = curr.second;
            }
        }
    }

    if (answer[n + 1] == INF)
    {
        out << "-1";
    }
    else
    {
        long long end = last[n + 1];
        while (types[end] != '1')
            end = last[end];

        out << end + 1 << " " << last[n + 1]+ 1 << " " << answer[n + 1];
    }

    out.close();

    return 0;
}