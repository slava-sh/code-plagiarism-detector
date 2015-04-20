#include <fstream>
#include <vector>

using namespace std;

ifstream in("binary.in");
ofstream out("binary.out");

vector <vector <int> > graph, newGraph;
vector <int> colors, newColors;

void fail()
{
    out << "0\n";
    in.close();
    out.close();

    exit(0);
}


void paint(int v, int color)
{
    colors[v] = color;

    for (vector <int>::const_iterator it = graph[v].begin(); it != graph[v].end(); ++it)
    {
        if (!colors[*it])
        {
            paint(*it, color);
        }
    }
}

void check(int v, int color = 1)
{
    newColors[v] = color;

    for (vector <int>::const_iterator it = newGraph[v].begin(); it != newGraph[v].end(); ++it)
    {
        if (!newColors[*it])
            check(*it, color % 2 + 1);
        if (newColors[*it] == newColors[v])
            fail();
    }
}

int main()
{
    int n;
    in >> n;

    graph.resize(n);
    colors.resize(n, 0);

    vector <pair <int, int> > badGraph;

    int curr;

    for (int i = 0; i != n; ++i)
    {
        in >> curr;

        if (i == 0)
            continue;

        if (i == 0 || curr == -1)
            continue;

        if (i + curr > n)
            fail();

        for (int j = 0; j != curr; ++j)
        {
            graph[i + j].push_back(j);
            graph[j].push_back(i + j);
        }

        if (i + curr != n)
        {
            badGraph.push_back(make_pair(i + curr, curr));
            badGraph.push_back(make_pair(curr, i + curr));
        }
    }

    int amountColors = 0;

    for (int i = 0; i != n; ++i)
        if (!colors[i])
            paint(i, ++amountColors);

    newGraph.resize(amountColors + 2);
    newColors.resize(amountColors + 2);

    for (vector <pair <int, int> >::const_iterator it = badGraph.begin(); it != badGraph.end(); ++it)
    {
        //if (colors[it->first] == colors[it->second])
        //     fail();
        newGraph[colors[it->first]].push_back(colors[it->second]);
    }

    unsigned long long answer = 1, mod = 1000000007;

    for (int i = 1; i <= amountColors; ++i)
    {
        if (!newColors[i])
        {
            check(i);
            answer = (2 * answer) % mod;
        }
    }

    out << answer;

    in.close();
    out.close();

    return 0;
}