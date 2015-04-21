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

vector<hall> graph[100000];

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
    for (int i = 0; i < num; i++){
        set<pair<int, int> > used[n];
        //for (int i = 0; i < m; i++)
        //    used[i].clear();
        queue<my> q;
        cin >> v >> u;
        u--;
        v--;
        int ans = -1;
        for (int i = 0; i < graph[v].size(); i++){
            used[v].insert(make_pair(graph[v][i].v, graph[v][i].t));
            q.push(my(graph[v][i].v, graph[v][i].t, 1));
        }
        int dist;
        pair<int, int> p;
        while (!q.empty()){
            v = q.front().v;
            dist = q.front().dist;
            t = q.front().t;
            //cout << v << " " << t << " " << dist << endl;
            if (v == u){
                ans = dist;
                break;
            }
            dist++;
            q.pop();
            for (int i = 0; i < graph[v].size(); i++)
                if (abs(graph[v][i].t - t) <= d && used[v].count(make_pair(graph[v][i].v, graph[v][i].t)) == 0){
                    q.push(my(graph[v][i].v, graph[v][i].t, dist));
                    used[v].insert(make_pair(graph[v][i].v, graph[v][i].t));
                }
        }
        cout << ans << endl;
    }
    return 0;
}
