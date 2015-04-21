#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

struct hall{
    int v, t, num;
    hall(int v, int t, int num):v(v), t(t), num(num){}
};

struct my{
    int v, t, dist;
    my(int v, int t, int dist):v(v), t(t), dist(dist){}
};

vector<hall> graph[50000];

int main(){
    ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    int n, m, d, u, v, t;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> t;
        u--;
        v--;
        graph[u].push_back(hall(v, t, i));
        graph[v].push_back(hall(u, t, i));
    }
    int num;
    cin >> num;
    int vv;
    vector<int> vec;
    for (int i = 0; i < num; i++){
        set<int> g[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < graph[i].size(); j++)
                g[i].insert(j);
        queue<my> q;
        cin >> v >> u;
        u--;
        v--;
        int ans = -1;
        vec.clear();
        for (set<int>::iterator i = g[v].begin(); i != g[v].end(); i++){
            q.push(my(graph[v][(*i)].v, graph[v][(*i)].t, 1));
            vec.push_back(*i);
        }
        for (int i = 0; i < vec.size(); i++)
            g[v].erase(g[v].find(vec[i]));
        int dist;
        pair<int, int> p;
        while (!q.empty()){
            v = q.front().v;
            dist = q.front().dist;
            t = q.front().t;
            if (v == u){
                ans = dist;
                break;
            }
            vec.clear();
            dist++;
            q.pop();

            for (set<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
                if (abs(graph[v][*i].t - t) <= d){
                    q.push(my(graph[v][*i].v, graph[v][*i].t, dist));
                    vec.push_back(*i);
                }
            for (int i = 0; i < vec.size(); i++)
                g[v].erase(g[v].find(vec[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
