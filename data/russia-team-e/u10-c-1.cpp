#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 200002;
int S[maxn];
bool f[maxn];
vector<int>A[maxn];
vector<int>a[maxn];
int father[maxn];
int len[maxn];
int INDEX = maxn - 2;
int DEL(int u){
    int M = 0;
    for(int i = 0; i < a[u].size(); i ++)
        M = max(M,DEL(a[u][i]));
    S[len[u]] --;
    len[u] = 0;
    return M + 1;
}
int find_max_way(int u, int L){
    if(u == 0) return 0;
    int M = 0;
    for(int i = 0; i < a[u].size(); i ++){
        if(len[a[u][i]] == 0)continue ;
        M = max(M,DEL(a[u][i]));
    }
    M += L;
    S[len[u]] --; len[u] = 0;
    while(INDEX > 0 && S[INDEX] == 0)INDEX --;
    M = min(INDEX,M);
    M = max(M,find_max_way(father[u],L + 1));
    return M;
}
void make_graph(int u){
    for(int i = 0; i < A[u].size(); i ++){
        int v = A[u][i];
        if(f[v]) continue;
        a[u].push_back(v);
        f[v] = true;
        father[v] = u;
        len[v] = len[u] + 1;
        S[len[v]] ++;
        make_graph(v);
    }
}
int main(){
    freopen("dwarfs.in","r",stdin);
    freopen("dwarfs.out","w",stdout);

    int n,i,u,v,result = 0;
    cin>>n;
    for(i = 1; i < n; i ++){
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    cin>>u>>v;
    f[u] = true;
    len[u] = 1;
    S[1] = 1;
    make_graph(u);
    result = find_max_way(v,1);
    cout<<result<<endl;
    return 0;
}
