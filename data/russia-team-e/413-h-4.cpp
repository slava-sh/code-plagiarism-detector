#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

#include <cstdlib>
#include <ctime>

using namespace std;

ifstream in("secure.in");
ofstream out("secure.out");

typedef unsigned long long ull;
ull INF = 1000000000000ll;

int main()
{
    srand(218 * 12 / 7);

    clock_t start = clock(), end;

    size_t n, m;
    in >> n >> m;

    vector <vector <pair <size_t, ull> > > graph(n);
    vector <size_t> first, second;
    char inType;

    for (size_t i = 0; i != n; ++i)
    {
        in >> inType;

        if (inType == '1')
        {
            first.push_back(i);
        }
        else if (inType == '2')
        {
            second.push_back(i);
        }
    }

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

    random_shuffle(first.begin(), first.end());

    for (vector <size_t>::const_iterator it = first.begin(); it != first.end(); ++it)
    {
        visited.assign(n, false);
        answer.assign(n, INF);

        dej.insert(pair <ull, size_t>(0, *it));
        for (size_t j = 0; j != n; ++j)
            if (*it != j)
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

        for (vector <size_t>::const_iterator jt = second.begin(); jt != second.end(); ++jt)
        {
            if (answer[*jt] < ans)
            {
                ans = answer[*jt];
                ansStart = *it;
                ansEnd = *jt;
            }
        }

         end = clock();

         if (end - start > 1950)
         {
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