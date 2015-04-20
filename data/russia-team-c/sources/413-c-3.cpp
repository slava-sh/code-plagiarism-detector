#include <algorithm>
#include <fstream>
#include <vector>
#include <functional>

using namespace std;

ifstream in("dwarfs.in");
ofstream out("dwarfs.out");

vector <bool> visited;
vector <vector <long long> > graph;
vector <pair <long long, long long> > way;

long long a, b;
long long closeA, closeB;
long long n;

bool findWay(long long vertex)
{
    visited[vertex] = true;

    if (vertex == b)
    {
        return true;
    }

    for (vector <long long>::const_iterator it = graph[vertex].begin(); it != graph[vertex].end(); ++it)
    {
        if (!visited[*it] && findWay(*it))
        {
            way.push_back(make_pair(vertex, *it));
            return true;
        }
    }

    return false;
}

long long dfs(long long vertex, long long depth = 1)
{
    visited[vertex] = true;
    long long ans = depth;

    for (vector <long long>::const_iterator it = graph[vertex].begin(); it != graph[vertex].end(); ++it)
    {
        if (!visited[*it] && (vertex != closeA || *it != closeB))
        {
            ans = max(ans, dfs(*it, depth + 1));
        }
    }

    return ans;
}

pair <long long, long long> count(long long del)
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

    for (long long i = 0; i != n - 1; ++i)
    {
        long long start, finish;
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

    long long left = 0, right = way.size(), middle;
    pair <long long, long long> curr;

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

    long long answer = 0;

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