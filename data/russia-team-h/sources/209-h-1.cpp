#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int inf = 1000000000;

int g[5001][5001];
vector <int> fs, sc;

vector <int> tp;

int n, m;

void djikstra(int from, ofstream &cout)
{
    vector <int> d;
    vector <char> used;
    vector <int> p;
    d.assign(n + 1, inf);
    used.assign(n + 1, 0);
    p.assign(n + 1, -1);
    d[from] = 0;
    for(int i = 0; i < n; ++i)
    {
        int v = -1;
        for(int j = 1; j <= n; ++j)
            if(!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if(d[v] == inf)
            break;
        used[v] = 1;
        for(int j = 1; j <= n; ++j)
            if(d[v] + g[v][j] < d[j])
            {
                d[j] = d[v] + g[v][j];
                p[j] = v;
            }
    }
    int minans = inf;
    int anspos = -1;
    for(int i = 0; i < sc.size(); ++i)
    {
        if(d[sc[i]] < minans)
        {
            minans = d[sc[i]];
            anspos = sc[i];
        }
    }
    if(anspos == -1)
    {
        cout << -1 << endl;
        return;
    }
    int ranspos = anspos;
    int cl1;
    while(anspos != -1)
    {
        if(tp[anspos] == 1)
        {
            cl1 = anspos;
            break;
        }
        anspos = p[anspos];
    }
    cout << cl1 << " " << ranspos << " " << minans << endl;
}

int main()
{
    ifstream cin("secure.in");
    ofstream cout("secure.out");
    cin >> n >> m;
    tp.assign(n + 1, 0);
    for(int i = 1; i <= 5000; ++i)
        for(int j = 1; j <= 5000; ++j)
            g[i][j] = inf;
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        tp[i + 1] = t;
        if(t == 1)
            fs.push_back(i + 1);
        if(t == 2)
            sc.push_back(i + 1);
    }
    for(int i = 0; i < m; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g[v1][v2] = w;
        g[v2][v1] = w;
    }
    for(int i = 0; i < fs.size(); ++i)
        for(int j = 1; j < fs.size(); ++j)
        {
            int v1 = fs[i];
            int v2 = fs[j];
            g[v1][v2] = 0;
            g[v2][v1] = 0;
        }
    djikstra(fs[0], cout);
    return 0;
}
