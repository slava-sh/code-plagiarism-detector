#include <algorithm>
#include <fstream>
#include <vector>
#include <functional>

using namespace std;

ifstream in("dwarfs.in");
ofstream out("dwarfs.out");

vector <bool> visited;
vector <vector <size_t> > graph;
vector <pair <size_t, size_t> > way;

size_t a, b;

size_t closeA, closeB;

bool findWay(size_t vertex)
{
    visited[vertex] = true;

    if (vertex == b)
    {
        return true;
    }

    for (vector <size_t>::const_iterator it = graph[vertex].begin(); it != graph[vertex].end(); ++it)
    {
        if (!visited[*it] && findWay(*it))
        {
            way.push_back(make_pair(vertex, *it));
            return true;
        }
    }

    return false;
}

long long dfs(size_t vertex, size_t depth = 1)
{
    visited[vertex] = true;
    long long ans = depth;

    for (vector <size_t>::const_iterator it = graph[vertex].begin(); it != graph[vertex].end(); ++it)
    {
        if (!visited[*it] && (vertex != closeA || *it != closeB))
        {
            ans = max(ans, dfs(*it, depth + 1));
        }
    }

    return ans;
}

int main()
{
    size_t n;
    in >> n;

    graph.resize(n);

    for (size_t i = 0; i != n - 1; ++i)
    {
        size_t start, finish;
        in >> start >> finish;
        --start;
        --finish;

        graph[start].push_back(finish);
        graph[finish].push_back(start);
    }

    in >> a >> b;
    --a;
    --b;

    in.close();

    visited.resize(n, false);
    findWay(a);

    reverse(way.begin(), way.end());

    size_t left = 0, right = way.size(), middle;

    closeA = way[0].first;
    closeB = way[0].second;

    visited.assign(n, false);
    long long first = dfs(a);
        
    swap(closeA, closeB);
    visited.assign(n, false);
    long long second = dfs(b);

    if (first > second)
    {
        out << second;
        out.close();
        return 0;
    }

    while (right - left != 1)
    {
        middle = (left + right) / 2;

        closeA = way[middle].first;
        closeB = way[middle].second;

        visited.assign(n, false);
        long long first = dfs(a);
        
        swap(closeA, closeB);
        visited.assign(n, false);
        long long second = dfs(b);

        if (first > second)
        {
            right = middle;
        }
        else
        {
            left = middle;
        }
    }

    long long answer = 0;

    if (right != way.size() - 1)
    {
        closeA = way[right].first;
        closeB = way[right].second;

        visited.assign(n, false);
        long long first = dfs(a);
        
        swap(closeA, closeB);
        visited.assign(n, false);
        long long second = dfs(b);

        answer = max(answer, min(first, second));
    }

    closeA = way[left].first;
    closeB = way[left].second;

    visited.assign(n, false);
    first = dfs(a);
        
    swap(closeA, closeB);
    visited.assign(n, false);
    second = dfs(b);

    answer = max(answer, min(first, second));

    out << answer;
    out.close();
    
    return 0;
}