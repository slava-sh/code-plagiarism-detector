#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <utility>
#include <complex>

using namespace std;

typedef long long LL;
typedef long double LD;

#define NAME "task"

//solution

const int MAX_N = 1010;
int n, m;
int a [MAX_N][MAX_N];
int deg [MAX_N][MAX_N];
vector<pair<int, int> > buckets [5];

const int D = 4;
const int DI [] = {1, -1, 0, 0};
const int DJ [] = {0, 0, 1, -1};

void doPaint(vector<pair<int, int> > ps)
{
    #ifdef DEBUG
    cerr << "doPaint\n";
    for (int i = 0; i < ps.size(); i++)
        fprintf(stderr, "(%d %d) ", ps[i].first, ps[i].second);
    cerr << '\n';
    #endif

    vector<bool> busy(11);
    for (int u = 0; u < ps.size(); u++)
    {
        int i = ps[u].first, j = ps[u].second;
        for (int d = 0; d < D; d++)
        {
            int ci = i + DI[d], cj = j + DJ[d];
            if (!(0 <= ci && ci < n && 0 <= cj && cj < m)) continue;

            if (a[ci][cj] > 0)
                busy[a[ci][cj]] = true;
            else
            {
                deg[ci][cj]--;
                buckets[deg[ci][cj]].push_back(make_pair(ci, cj));
            }
        }
    }

    int color = 1;
    for (; busy[color]; color++);

    for (int u = 0; u < ps.size(); u++)
        a[ps[u].first][ps[u].second] = color;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        char buf [MAX_N];
        scanf("%s", &buf);
        for (int j = 0; j < m; j++)
            a[i][j] = buf[j] == '#' ? -1 : 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)        
        {
            for (int d = 0; d < D; d++)
            {
                int ci = i + DI[d], cj = j + DJ[d];
                if (0 <= ci && ci < n && 0 <= cj && cj < m && !a[ci][cj])
                    deg[i][j]++;
            }            
            buckets[deg[i][j]].push_back(make_pair(i, j));
        }
    #ifdef DEBUG
    cerr << "a\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cerr << a[i][j] << ' ';
        cerr << '\n';
    }

    cerr << "deg\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cerr << deg[i][j] << ' ';
        cerr << '\n';
    }

    cerr << "buckets\n";
    for (int d = 0; d <= 4; d++)
    {
        for (int i = 0; i < buckets[d].size(); i++)
            fprintf(stderr, "(%d %d) ", buckets[d][i].first, buckets[d][i].second);
        cerr << '\n';
    }
    #endif

    bool stop = false;                
    while (!stop)
    {
        #ifdef DEBUG
        cerr << "a\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cerr << a[i][j] << ' ';
            cerr << '\n';
        }

        cerr << "deg\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
               cerr << deg[i][j] << ' ';
            cerr << '\n';
        }
        #endif

        stop = true;
        for (int minDeg = 0; minDeg <= 4; minDeg++)
            if (!buckets[minDeg].empty())
            {
                stop = false;

                pair<int, int> cr = buckets[minDeg].back();
                buckets[minDeg].pop_back();
                if (a[cr.first][cr.second]) 
                {
                    minDeg--;
                    continue;
                }

                if (minDeg == 0)
                {
                    cout << "-1\n";
                    return 0;
                }

                vector< pair<int, int> > toPaint;
                toPaint.push_back(cr);

                pair<int, int> nb;
                for (int d = 0; d < D; d++)
                {
                    int ci = cr.first + DI[d], cj = cr.second + DJ[d];
                    if (0 <= ci && ci < n && 0 <= cj && cj < m && !a[ci][cj])
                    {
                        nb.first = ci;
                        nb.second = cj;
                    }
                }

                toPaint.push_back(nb);

                for (int d = 0; d < D; d++)
                {
                    int ci = nb.first + DI[d], cj = nb.second + DJ[d];
                    if (0 <= ci && ci < n && 0 <= cj && cj < m && !a[ci][cj] && deg[ci][cj] == 1 && (ci != cr.first || cj != cr.second))
                        toPaint.push_back(make_pair(ci, cj));
                }

                doPaint(toPaint);
                break;
            }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
            cout << (a[i][j] > 0 ? (char)(a[i][j] - 1 + '0') : '#');
        cout << '\n';
    }

    return 0;
}
