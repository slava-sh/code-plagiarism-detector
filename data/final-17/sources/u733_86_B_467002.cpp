#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

#define MAXV 1000010
int parent[MAXV],rank[MAXV];

struct UnionFind{

    UnionFind(int n){
        int i;
        REP(i,n) {parent[i] = i; rank[i] = 1;}
    }

    int root(int x){
        if(parent[x] != x) parent[x] = root(parent[x]);
        return parent[x];
    }
    
    int sz(int x){
        return rank[root(x)];
    }

    void connect(int x, int y){
        int rx=root(x),ry=root(y);
        if(rx == ry) return;
        if(rank[rx] > rank[ry]) {parent[ry] = rx; rank[rx] += rank[ry];}
        if(rank[rx] <= rank[ry]) {parent[rx] = ry; rank[ry] += rank[rx];}
    }
};

int H,W;
string s[1010];
char buf[1010];
bool used[1010][1010];
pair <int, int> p[1010][1010];
queue <int> q;

int sz;
pair <int, int> order[1000010];

vector <pair <int, int> > comp[1000010];

void bfs(int sx, int sy){
    int i;
    
    q.push(sx); q.push(sy); used[sx][sy] = true;
    order[sz] = make_pair(sx,sy); sz++;
    
    p[sx][sy] = make_pair(-1,-1);
    
    while(!q.empty()){
        int x = q.front(); q.pop(); int y = q.front(); q.pop();
        REP(i,4){
            int x2 = x + dx[i], y2 = y + dy[i];
            if(x2 >= 0 && x2 < H && y2 >= 0 && y2 < W && !used[x2][y2]){
                used[x2][y2] = true;
                q.push(x2); q.push(y2);
                p[x2][y2] = make_pair(x,y);
                order[sz] = make_pair(x2,y2); sz++;
            }
        }
    }
}

void color(int id){
    int i,j;
    
    int mask = 0;
    REP(i,comp[id].size()){
        int x = comp[id][i].first, y = comp[id][i].second;
        REP(j,4){
            int x2 = x + dx[j], y2 = y + dy[j];
            if(x2 >= 0 && x2 < H && y2 >= 0 && y2 < W && s[x2][y2] >= '0' && s[x2][y2] <= '9'){
                int d = s[x2][y2] - '0';
                mask |= (1<<d);
            }
        }
    }
    
    REP(i,10) if(!(mask&(1<<i))) break;
    char ch = '0' + i;
    
    REP(i,comp[id].size()){
        int x = comp[id][i].first, y = comp[id][i].second;
        s[x][y] = ch;
    }
}

int main(void){
    int i,j;
    
    scanf("%d%d",&H,&W);
    REP(i,H){
        scanf("%s",buf);
        s[i] = buf;
    }
    
    REP(i,H) REP(j,W) if(s[i][j] == '#') used[i][j] = true;
    REP(i,H) REP(j,W) if(!used[i][j]) bfs(i,j);
    
    reverse(order,order+sz);
    
    UnionFind uf(H*W); // x*W + y
    REP(i,sz){
        int x = order[i].first, y = order[i].second, id = x*W + y;
        if(uf.sz(id) == 1){
            if(p[x][y].first == -1){
                REP(j,4){
                    int x2 = x + dx[j], y2 = y + dy[j];
                    if(x2 >= 0 && x2 < H && y2 >= 0 && y2 < W && s[x2][y2] == '.'){
                        uf.connect(id, x2 * W + y2);
                        break;
                    }
                }
                
                if(j == 4){
                    printf("-1\n");
                    return 0;
                }
            } else {
                uf.connect(id, p[x][y].first * W + p[x][y].second);
            }
        }
    }
    
    REP(i,H) REP(j,W) if(s[i][j] != '#') comp[uf.root(i*W+j)].push_back(make_pair(i,j));
    REP(i,H) REP(j,W) if(!comp[i*W+j].empty()) color(i*W+j);
    
    REP(i,H) printf("%s\n",s[i].c_str());
    
    return 0;
}
