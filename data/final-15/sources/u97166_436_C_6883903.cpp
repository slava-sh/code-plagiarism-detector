#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
const int N = 1005;
char a[N][15][15];
int d[N][N], mark[N], lowcost[N], pre[N];
int s[N], e[N];
int n, m, k;
void solve() {
    int ans = n*m;
    s[0] = 0, e[0] = -1;
    mark[0] = 1;
    for(int i = 0; i < k; i ++) {
        lowcost[i] = d[0][i];
        pre[i] = 0;
    }
    for(int i = 1; i < k; i ++) {
        int Min = INF, tmp = -1;
        for(int j = 0; j < k; j ++) {
            if(!mark[j] && lowcost[j] < Min) {
                Min = lowcost[j];
                tmp = j;
            }
        }
        if(Min > n*m) {
            ans += n*m;
            mark[tmp] = 1;
            s[i] = tmp;
            e[i] = -1;
        } else {
            ans += Min;
            mark[tmp] = 1;
            s[i] = tmp;
            e[i] = pre[tmp];
        }
        for(int j = 1; j < k; j ++) {
            if(!mark[j] && d[tmp][j] < lowcost[j]) {
                lowcost[j] = d[tmp][j];
                pre[j] = tmp;
            }
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i < k; i ++) {
        printf("%d %d\n", s[i]+1, e[i]+1);
    }
    puts("");
}
int main() {
    int w;
    scanf("%d%d%d%d", &n, &m, &k, &w);
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < n; j ++) {
            scanf("%s", &a[i][j]);
        }
    }
    
    for(int i = 0; i < k; i ++) {
        for(int j = i+1; j < k; j ++) {
            int cnt = 0;
            for(int s = 0; s < n; s ++) {
                for(int t = 0; t < m; t ++) {
                    if(a[i][s][t] != a[j][s][t]) cnt++;
                }
            }
            d[i][j] = d[j][i] = cnt * w;
        }
    }
    
    solve();
    
}
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
const int N = 1005;
char a[N][15][15];
int d[N][N], mark[N], lowcost[N], pre[N];
int s[N], e[N];
int n, m, k;
void solve() {
    int ans = n*m;
    s[0] = 0, e[0] = -1;
    mark[0] = 1;
    for(int i = 0; i < k; i ++) {
        lowcost[i] = d[0][i];
        pre[i] = 0;
    }
    for(int i = 1; i < k; i ++) {
        int Min = INF, tmp = -1;
        for(int j = 0; j < k; j ++) {
            if(!mark[j] && lowcost[j] < Min) {
                Min = lowcost[j];
                tmp = j;
            }
        }
        if(Min > n*m) {
            ans += n*m;
            mark[tmp] = 1;
            s[i] = tmp;
            e[i] = -1;
        } else {
            ans += Min;
            mark[tmp] = 1;
            s[i] = tmp;
            e[i] = pre[tmp];
        }
        for(int j = 1; j < k; j ++) {
            if(!mark[j] && d[tmp][j] < lowcost[j]) {
                lowcost[j] = d[tmp][j];
                pre[j] = tmp;
            }
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i < k; i ++) {
        printf("%d %d\n", s[i]+1, e[i]+1);
    }
    puts("");
}
int main() {
    int w;
    scanf("%d%d%d%d", &n, &m, &k, &w);
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < n; j ++) {
            scanf("%s", &a[i][j]);
        }
    }
    
    for(int i = 0; i < k; i ++) {
        for(int j = i+1; j < k; j ++) {
            int cnt = 0;
            for(int s = 0; s < n; s ++) {
                for(int t = 0; t < m; t ++) {
                    if(a[i][s][t] != a[j][s][t]) cnt++;
                }
            }
            d[i][j] = d[j][i] = cnt * w;
        }
    }
    
    solve();
    
}#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
const int N = 1005;
char a[N][15][15];
int d[N][N], mark[N], lowcost[N], pre[N];
int s[N], e[N];
int n, m, k;
void solve() {
    int ans = n*m;
    s[0] = 0, e[0] = -1;
    mark[0] = 1;
    for(int i = 0; i < k; i ++) {
        lowcost[i] = d[0][i];
        pre[i] = 0;
    }
    for(int i = 1; i < k; i ++) {
        int Min = INF, tmp = -1;
        for(int j = 0; j < k; j ++) {
            if(!mark[j] && lowcost[j] < Min) {
                Min = lowcost[j];
                tmp = j;
            }
        }
        if(Min > n*m) {
            ans += n*m;
            mark[tmp] = 1;
            s[i] = tmp;
            e[i] = -1;
        } else {
            ans += Min;
            mark[tmp] = 1;
            s[i] = tmp;
            e[i] = pre[tmp];
        }
        for(int j = 1; j < k; j ++) {
            if(!mark[j] && d[tmp][j] < lowcost[j]) {
                lowcost[j] = d[tmp][j];
                pre[j] = tmp;
            }
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i < k; i ++) {
        printf("%d %d\n", s[i]+1, e[i]+1);
    }
    puts("");
}
int main() {
    int w;
    scanf("%d%d%d%d", &n, &m, &k, &w);
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < n; j ++) {
            scanf("%s", &a[i][j]);
        }
    }
    
    for(int i = 0; i < k; i ++) {
        for(int j = i+1; j < k; j ++) {
            int cnt = 0;
            for(int s = 0; s < n; s ++) {
                for(int t = 0; t < m; t ++) {
                    if(a[i][s][t] != a[j][s][t]) cnt++;
                }
            }
            d[i][j] = d[j][i] = cnt * w;
        }
    }
    
    solve();
    
}
*/