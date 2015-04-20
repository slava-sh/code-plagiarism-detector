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
size_t n;

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

size_t dfs(size_t vertex, size_t depth = 1)
{
    visited[vertex] = true;
    size_t ans = depth;

    for (vector <size_t>::const_iterator it = graph[vertex].begin(); it != graph[vertex].end(); ++it)
    {
        if (!visited[*it] && (vertex != closeA || *it != closeB))
        {
            ans = max(ans, dfs(*it, depth + 1));
        }
    }

    return ans;
}

pair <size_t, size_t> count(size_t del)
{
    closeA = way[del].first;
    closeB = way[del].second;

    visited.assign(n, false);
    long long first = dfs(a);
        
    swap(closeA, closeB);
    visited.assign(n, false);
    long long second = dfs(b);

    return make_pair(first, second);
}

int main()
{
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
    pair <size_t, size_t> curr;

    curr = count(0);

    if (curr.first > curr.second)
    {
        out << curr.second;
        out.close();
        return 0;
    }

    while (right - left != 1)
    {
        middle = (left + right) / 2;
        curr = count(middle);

        if (curr.first > curr.second)
        {
            right = middle;
        }
        else
        {
            left = middle;
        }
    }

    size_t answer = 0;

    if (right != way.size())
    {
        curr = count(right);
        answer = max(answer, min(curr.first, curr.second));
    }

    curr = count(left);
    answer = max(answer, min(curr.first, curr.second));

    out << answer;
    out.close();
    
    return 0;
}