//tonynater - CodeForces 2014

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

#define sz(x) ((int) x.size())

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = acos(-1);
const double tau = 2*pi;
const double epsilon = 1e-9;

const int MAX_N = 11;
const int MAX_M = 11;
const int MAX_K = 1100;

int N, M, K, W;

char levels[MAX_K][MAX_N][MAX_M];

int dist[MAX_K][MAX_K];

int UF[MAX_K];
int UFsz[MAX_K];
void init_UF()
{
    for(int i = 0; i < MAX_K; i++)
        UF[i] = i, UFsz[i] = 1;
}

int root(int idx)
{
    if(UF[idx] == idx) return idx;
    else return (UF[idx] = root(UF[idx]));
}

bool merge(int idx1, int idx2)
{
    int r1 = root(idx1), r2 = root(idx2);
    int sz1 = UFsz[r1], sz2 = UFsz[r2];
    
    if(r1 == r2) return false;
    
    if(sz1 > sz2)
    {
        UF[r2] = r1;
        UFsz[r1] += sz2;
    }else
    {
        UF[r1] = r2;
        UFsz[r2] += sz1;
    }
    
    return true;
}

vector<int> adj[MAX_K];
pii edges[MAX_K*MAX_K]; int esz = 0;
int cost = 0;
void kruskall()
{
    for(int i = 0; i <= K; i++)
        for(int j = 0; j < i; j++)
            edges[esz++] = pii(dist[i][j],i*(K+1)+j);
    
    sort(edges, edges+esz);
    
    for(int i = 0; i < esz; i++)
    {
        int u = edges[i].second/(K+1);
        int v = edges[i].second%(K+1);
        
        if(merge(u,v))
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            cost += edges[i].first;
        }
    }
}

bool vis[MAX_K];
void printsoln()
{
    cout << cost << '\n';
    
    stack<pii> stk;
    stk.push(pii(0,0));
    
    while(!stk.empty())
    {
        pii u = stk.top();
        stk.pop();
        
        vis[u.first] = true;
        if(u.first > 0) cout << u.first << ' ' << u.second << '\n';
        
        for(int i = 0; i < sz(adj[u.first]); i++)
            if(!vis[adj[u.first][i]])
                stk.push(pii(adj[u.first][i], u.first));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> M >> K >> W;
    
    for(int i = 1; i <= K; i++)
        for(int j = 0; j < N; j++)
        {
            string line;
            cin >> line;
            
            for(int k = 0; k < M; k++)
                levels[i][j][k] = line[k];
        }
    
    for(int i = 1; i <= K; i++)
        for(int j = 1; j < i; j++)
            for(int k = 0; k < N; k++)
                for(int l = 0; l < M; l++)
                    if(levels[i][k][l] != levels[j][k][l])
                        ++dist[i][j],++dist[j][i];
    
    for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++)
            dist[i][j] *= W;
    
    for(int i = 1; i <= K; i++)
        dist[i][0] = dist[0][i] = N*M;
    
    init_UF();
    
    kruskall();
    
    printsoln();
    
    return 0;
}