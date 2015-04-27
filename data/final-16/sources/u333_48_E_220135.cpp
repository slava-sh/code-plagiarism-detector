#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>       //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>      //do setprecision
#include <ctime>
using namespace std;
#define PB push_back
#define LL long long
#define ULL unsigned LL
#define LD long double

const int inf = 2000000000;
#define MR 210

int cost[2*MR][2*MR], n, m, h, t, R;
pair <int, int> t1[MR], t2[MR];

bool done[MR][MR];

queue < pair<int, int> > q;
void bfs()
{
    done[h][t] = 1;
    cost[h][t] = 0;
    q.push(make_pair(h, t));
    while(!q.empty())
    {
        pair <int, int> akt = q.front(); q.pop();
        int end = min(n, akt.first);
        for(int i = 1; i <= end; i++)
        {
            if(akt.first-i+t1[i].first + akt.second+t1[i].second > R)
                continue;
            if(!done[akt.first-i+t1[i].first][akt.second+t1[i].second])
            {
                q.push(make_pair(akt.first-i+t1[i].first, akt.second+t1[i].second));
                done[q.back().first][q.back().second] = 1;
                cost[q.back().first][q.back().second] = cost[akt.first][akt.second] + 1;
            }
        }
        end = min(m, akt.second);
        for(int i = 1; i <= end; i++)
        {
            if(akt.first+t2[i].first + akt.second-i+t2[i].second > R)
                continue;
            if(!done[akt.first+t2[i].first][akt.second-i+t2[i].second])
            {               
                q.push(make_pair(akt.first+t2[i].first, akt.second-i+t2[i].second));
                done[q.back().first][q.back().second] = 1;
                cost[q.back().first][q.back().second] = cost[akt.first][akt.second] + 1;
            }
        }
    }
}//bfs

int color[MR][MR], ile;
bool cykl;

pair <int, int> srt[MR*MR];

void dfs(int h, int t)
{   //szukamy cyklu
    color[h][t] = 1;
    int end = min(n, h);
    for(int i = 1; i <= end; i++)
    {
        if(h-i+t1[i].first + t+t1[i].second > R)
            continue;
        if(!color[h-i+t1[i].first][t+t1[i].second])
            dfs(h-i+t1[i].first, t+t1[i].second);
        else if(color[h-i+t1[i].first][t+t1[i].second] == 1)
            cykl = 1;           
    }
    end = min(m, t);
    for(int i = 1; i <= end; i++)
    {
        if(h+t2[i].first + t-i+t2[i].second > R)
            continue;
        if(!color[h+t2[i].first][t-i+t2[i].second])
            dfs(h+t2[i].first, t-i+t2[i].second);
        else if(color[h+t2[i].first][t-i+t2[i].second] == 1)
            cykl = 1;           
    }
    srt[ile++] = make_pair(h, t);   //sortowanie topologiczne
    color[h][t] = 2;
}

int main()
{
    scanf("%d%d%d", &h, &t, &R);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &t1[i].first, &t1[i].second);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &t2[i].first, &t2[i].second); 
    for(int i = 0; i <= R; i++)
        for(int j = 0; j <= R; j++)
            cost[i][j] = inf;               
    bfs();
    if(cost[0][0] < inf)
    {
        printf("Ivan\n%d\n", cost[0][0]);   
        return 0;
    }
    dfs(h, t);
    if(cykl)
    {
        printf("Draw\n");
        return 0;
    }
    //mamy graf acykliczny, wiec szukamy najdluzszej sciezki liniowo
    for(int i = 0; i <= R; i++)
        for(int j = 0; j <= R; j++)
            cost[i][j] = inf;               
    cost[h][t] = 0;
    for(int i = ile-1; i >= 0; i--)
    {
        int end = min(n, srt[i].first);
        for(int j = 1; j <= end; j++)
        {
            if(srt[i].first-j+t1[j].first + srt[i].second+t1[j].second > R)
                continue;
            if(cost[srt[i].first-j+t1[j].first][srt[i].second+t1[j].second] > cost[srt[i].first][srt[i].second]-1)
                cost[srt[i].first-j+t1[j].first][srt[i].second+t1[j].second] = cost[srt[i].first][srt[i].second]-1;
        }
        end = min(m, srt[i].second);
        for(int j = 1; j <= end; j++)
        {
            if(srt[i].first+t2[j].first + srt[i].second-j+t2[j].second > R)
                continue;
            if(cost[srt[i].first+t2[j].first][srt[i].second-j+t2[j].second] > cost[srt[i].first][srt[i].second]-1)
                cost[srt[i].first+t2[j].first][srt[i].second-j+t2[j].second] = cost[srt[i].first][srt[i].second]-1;
        }
    }
    //wyszukaj najpozniejszego momentu w jakim przegra
    int mnv = inf;
    for(int i = 0; i <= R; i++)
        for(int j = 0; j <= R; j++)
        {
            if(i + j > R)
                break;
            if(cost[i][j] < inf)
            {
                int end = min(n, i);
                for(int l = 1; l <= end; l++)
                    if(i-l+t1[l].first + j+t1[l].second > R)
                        mnv = min(mnv, cost[i][j]-1);
                end = min(m, j);
                for(int l = 1; l <= end; l++)
                    if(i+t2[l].first + j-l+t2[l].second > R)
                        mnv = min(mnv, cost[i][j]-1);
            }
        }
    printf("Zmey\n%d\n", abs(mnv));
    return 0;
}