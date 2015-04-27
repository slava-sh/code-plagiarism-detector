#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
const int N=35;
int m,n;
char ch[N][N];
int mat[N][N];
int v[N][N];
int used[N];
int c[N];
int savec[N];
int pp[N][N];
int ans;

bool Insert(int i){
    bool ret=true;
    for (int j=1;j<=i;j++)
        if (mat[i][j]){
            pp[c[i]][c[j]]++;
            if (c[i]!=c[j]) pp[c[j]][c[i]]++;
            if (pp[c[i]][c[j]]>1) ret=false;
        }
    return ret;
}

void Remove(int i){
    for (int j=1;j<=i;j++)
        if (mat[i][j]){
            pp[c[i]][c[j]]--;
            if (c[i]!=c[j]) pp[c[j]][c[i]]--;
        }
}

void dfs(int dep){
    if (dep>14){
        ans++;
        if (ans==1){
            for (int i=1;i<=14;i++) savec[i]=c[i];
        }
        return;
    }
    for (int i=0;i<7;i++)
        if (used[i]<2){
            used[i]++;
            c[dep]=i;
            bool check=Insert(dep);
            if (check) dfs(dep+1);
            Remove(dep);
            used[i]--;
            if (used[i]==0) break;
        }
}

int main(){
//    freopen("in","r",stdin);
    cin >> m >> n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin >> ch[i][j];
    memset(v,0,sizeof(v));
    memset(mat,0,sizeof(mat));
    int cnt=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (!v[i][j] && ch[i][j]!='.'){
                cnt++;
                v[i][j]=cnt;
                v[i+1][j]=cnt;
                v[i][j+1]=cnt;
                v[i+1][j+1]=cnt;
            }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (v[i][j]){
                if (i>1 && v[i-1][j] && ch[i][j]==ch[i-1][j]) mat[v[i][j]][v[i-1][j]]++;
                if (i<m && v[i+1][j] && ch[i][j]==ch[i+1][j]) mat[v[i][j]][v[i+1][j]]++;
                if (j>1 && v[i][j-1] && ch[i][j]==ch[i][j-1]) mat[v[i][j]][v[i][j-1]]++;
                if (j<n && v[i][j+1] && ch[i][j]==ch[i][j+1]) mat[v[i][j]][v[i][j+1]]++;
            }
    for (int i=1;i<=14;i++) mat[i][i]/=2;
    ans=0;
    memset(used,0,sizeof(used));
    memset(pp,0,sizeof(pp));
    dfs(1);
    cout << 1LL*ans*5040 << endl;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++)
            if (v[i][j])
                cout << savec[v[i][j]];
            else
                cout << ".";
        cout << endl;
    }
}
