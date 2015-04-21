#pragma comment(linker, "/stack:256000000")
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>

using namespace std;

//map<pair<int, int>, bool> used[50];
vector<pair<int, int> > edge[100001];
vector<int> used[100001];
int fs[100001];
vector<int> pr[100001];
vector<int> nx[100001];
int ds[100001];
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
        used[i].resize(edge[i].size());
    }
    for (int i = 0; i < q; i++){
        queue<pair<pair<int, int>, int> > qu;
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= n; j++){
            for (int k = 0; k < edge[j].size(); k++){
                used[j][k] = false;
            }
            ds[j] = -1;
            if (edge[j].size() > 0){
            fs[j] = 0;
            for (int k = 0; k < edge[j].size() - 1; k++){
                nx[j][k] = k + 1;
            }
            nx[j][edge[j].size() - 1] = -1;
            for (int k = 0; k < edge[j].size(); k++){
                pr[j][k] = k - 1;
            }
            }
            else{
                fs[j] = -1;
            }
        }
        bool b1 = false;
        ds[a] = 0;
        for (int y = fs[a]; y != -1; y = nx[a][y]){
            pair<int, int> p = edge[a][y];
            if (p.first == b){
                cout << "1\n";
                b1 = true;
                break;
            }
            int k = a;
            if (nx[k][y] != -1){
                pr[k][nx[k][y]] = pr[k][y];
            }
            if (pr[k][y] != -1){
                nx[k][pr[k][y]] = nx[k][y];
            }
            else{
                fs[k] = nx[k][y];
            }
            used[a][y] = true;
            qu.push(make_pair(p, 1));
        }
        while (!qu.empty() && !b1){
            pair<pair<int, int>, int > z = qu.front();
            qu.pop();
            int k = z.first.first;
            for (int y = fs[k]; y != -1; y = nx[k][y]){
                pair<int, int> p = edge[k][y];
                if (abs(p.second - z.first.second) <= d && !used[k][y] && (ds[p.first] == -1 || ds[p.first] + 1 >= z.second)){
                    if (ds[p.first] == -1){
                        ds[p.first] = z.second + 1;
                    }
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
                    used[k][y] = true;
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
