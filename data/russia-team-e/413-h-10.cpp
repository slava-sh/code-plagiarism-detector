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
ull INF = 1000000000000ll;

int main()
{
    //srand(218 * 12);

    //clock_t start = clock(), end;

    long long n, m;
    in >> n >> m;

    vector <char> types(n);
    vector <vector <pair <long long, ull> > > graph(n);
    vector <long long> first, second;

    for (long long i = 0; i != n; ++i)
    {
        in >> types[i];

        if (types[i] == '1')
        {
            first.push_back(i);
        }
        else if (types[i] == '2')
        {
            second.push_back(i);
        }
    }

    bool rev = false;
    
    if (second.size() < first.size())
    {
        first.swap(second);

        for (long long i = 0; i != n; ++i)
        {
            if (types[i] == '1')
            {
                types[i] = '2';
            }
            else if (types[i] == '2')
            {
                types[i] = '1';
            }
        }

        rev = true;
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

    long long ansStart, ansEnd;
    ull ans = INF;

    vector <bool> visited(n);
    vector <ull> answer(n);
    set <pair <ull, long long> > dej;

    //random_shuffle(first.begin(), first.end());

    for (vector <long long>::const_iterator it = first.begin(); it != first.end(); ++it)
    {
        visited.assign(n, false);
        answer.assign(n, INF);

        dej.insert(pair <ull, long long>(0, *it));
        /*for (long long j = 0; j != n; ++j)
            if (*it != j)
                dej.insert(pair <ull, long long>(INF, j));*/

        long long foundWay = 10000;

        while (!dej.empty() && dej.begin()->first != INF)
        {
            pair <ull, long long> curr = *dej.begin();
            dej.erase(dej.begin());

            if (types[curr.second] == '2')
            {
                dej.clear();
                foundWay = curr.second;
                break;
            }

            visited[curr.second] = true;

            for (vector <pair <long long, ull>>::const_iterator it = graph[curr.second].begin(); it != graph[curr.second].end(); ++it)
            {
                if (!visited[it->first] && types[it->first] != '1' && answer[it->first] > curr.first + it->second)
                {
                    set <pair <ull, long long> >::const_iterator findRes = dej.find(make_pair(answer[it->first], it->first));

                    if (findRes != dej.end())
                        dej.erase(findRes);

                    answer[it->first] = curr.first + it->second;
                    dej.insert(make_pair(answer[it->first], it->first));
                }
            }
        }

        /*
        for (vector <long long>::const_iterator jt = second.begin(); jt != second.end(); ++jt)
        {
            if (answer[*jt] < ans)
            {
                ans = answer[*jt];
                ansStart = *it;
                ansEnd = *jt;
            }
        }
        */

        if (foundWay != 10000 && answer[foundWay] < ans)
        {
            ans = answer[foundWay];
            ansStart = *it;
            ansEnd = foundWay;
        }

        // end = clock();

         /*
         if (end - start > 1950)
         {
            if (ans == INF)
            {
                out << "-1";
            }
            else
            {
                if (rev)
                {
                    out << ansEnd + 1 << " " << ansStart + 1 << " " << ans;
                }
                else
                {
                    out << ansStart + 1 << " " << ansEnd + 1 << " " << ans;
                }
            }

            out.close();
            return 0;
         }
         */
    }

    if (ans == INF)
    {
        out << "-1";
    }
    else if (rev)
    {
        out << ansEnd + 1 << " " << ansStart + 1 << " " << ans;
    }
    else
    {
        out << ansStart + 1 << " " << ansEnd + 1 << " " << ans;
    }

    out.close();

    return 0;
}