#pragma comment(linker, "/stack:256000000")
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>

using namespace std;

map<pair<int, int>, bool> used[50];
vector<pair<int, int> > edge[100001];
const int INF = 1e9 + 7;

int main(){
     #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif // DEBUG
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; i++){
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        edge[a].push_back(make_pair(b, t));
        edge[b].push_back(make_pair(a, t));
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        queue<pair<pair<int, int>, int> > qu;
        int a, b;
        cin >> a >> b;
        bool b1 = false;
        for (auto p: edge[a]){
            if (p.first == b){
                cout << "1\n";
                b1 = true;
                break;
            }
            used[i][p] = true;
            qu.push(make_pair(p, 1));
            used[i][make_pair(a, p.second)] = true;
        }
        while (!qu.empty() && !b1){
            pair<pair<int, int>, int > z = qu.front();
            qu.pop();
            for (auto p: edge[z.first.first]){
                if (abs(p.second - z.first.second) <= d && !used[i][p]){
                    used[i][p] = true;
                    if (p.first == b){
                        b1 = true;
                        printf("%d\n", z.second + 1);
                        break;
                    }
                    qu.push(make_pair(p, z.second + 1));
                }
            }
        }
        if (!b1){
            printf("-1\n");
        }
    }
    return 0;
}
