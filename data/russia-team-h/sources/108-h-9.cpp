#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int type[5001];
bool used[5001];
int path[5001];
const int INF = 1000000000;

struct edge{
    int s, t, w;

    edge(){
    }

    edge(int _s, int _t, int _w){
        s = _s;
        t = _t;
        w = _w;
    }

};

bool operator < (edge a, edge b){
    return (a.w < b.w) || ((a.w == b.w) && (a.t < b.t)) || ((a.w == b.w) && (a.t == b.t) && (a.s < b.s));
}

vector<edge> son[5001];
int sz[5001];
set<edge> st;

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    int n, m;
    scanf("%i%i", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%i", &type[i]);
    }
    for (int i = 0; i < m; i++){
        int u, v, w;
        scanf("%i%i%i", &u, &v, &w);
        son[u].push_back(edge(u, v, w));
		sz[u]++;
		son[v].push_back(edge(v, u, w));
		sz[v]++;
    }
	int start, finish;
    int minp = INF;
    for (int i = 1; i <= n; i++){
        if (type[i] == 1){
            for (int j = 1; j <= n; j++){
                used[j] = false;
                path[j] = INF;
            }
            used[i] = true;
            path[i] = 0;
			int g = 0;
            for (int j = 0; j < sz[i]; j++){
                st.insert(son[i][j]);
				g++;
			}
            while(g > 0){
                edge a = *st.begin();
                st.erase(a);
				g--;
                path[a.t] = min(path[a.t], path[a.s] + a.w);
				if (!used[a.t] && type[a.t] != 1){
                    used[a.t] = true;
                    for (int j = 0; j < sz[a.t]; j++){
                        st.insert(son[a.t][j]);
						g++;
                    }
                }
            }
            int mn = INF;
			int minj;
            for (int j = 1; j <= n; j++){
                if ((path[j] < mn) && (type[j] == 2)){
                    mn = path[j];
					minj = j;
				}
            }
            if (minp > mn){
                minp = mn;
				start = i;
				finish = minj;
            }
        }
    }
    if (minp == INF){
        cout << -1;
        return 0;
    }
    cout << start << " " << finish << " " << minp;
    return 0;
}
