#pragma comment(linker, "/stack:256000000")
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>

using namespace std;

map<pair<int, int>, bool> used[50];
vector<pair<int, int> > edge[100001];
int fs[100001];
vector<int> pr[100001];
vector<int> nx[100001];
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
    for (int i = 1; i <= n; i++){
        nx[i].resize(edge[i].size());
        pr[i].resize(edge[i].size());
    }
    for (int i = 0; i < q; i++){
        queue<pair<pair<int, int>, int> > qu;
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= n; j++){
            fs[j] = 0;
            pr[j][0] = -1;
            for (int i = 0; i < edge[j].size() - 1; i++){
                nx[j][i] = i + 1;
            }
            nx[j][edge[j].size() - 1] = -1;
            for (int i = 1; i < edge[j].size(); i++){
                pr[j][i] = i - 1;
            }
        }
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
            int k = z.first.first;
            for (int y = fs[k]; y != -1; y = nx[k][y]){
                pair<int, int> p = edge[k][y];
                if (abs(p.second - z.first.second) <= d && !used[i][p]){
                    if (p.first == b){
                        b1 = true;
                        printf("%d\n", z.second + 1);
                        break;
                    }
                    if (nx[k][y] != -1){
                        pr[k][nx[k][y]] = pr[k][y];
                    }
                    if (pr[k][y] != -1){
                        nx[k][pr[k][y]] = nx[k][y];
                    }
                    else{
                        fs[k] = nx[k][y];
                    }
                    used[i][p] = true;
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
