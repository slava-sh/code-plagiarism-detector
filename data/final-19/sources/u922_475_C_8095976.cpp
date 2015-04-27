#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n,m,sr,sc;
string M[1000];

int sum[1001][1001];

int get_sum(int r1, int r2, int c1, int c2){
    return sum[r2 + 1][c2 + 1] - sum[r1][c2 + 1] - sum[r2 + 1][c1] + sum[r1][c1];
}

bool check(int x, int y){
    int r = sr,c = sc;
    int aux = x * y;
    
    if(get_sum(sr,sr + x - 1,sc,sc + y - 1) != aux)
        return false;
    
    bool go = true;
    
    while(go){
        go = false;
        
        if(c + y < m && M[r][c + y] == 'X'){
            go = true;
            
            if(get_sum(r,r + x - 1,c + y,c + y) != x)
                return false;
            aux += x;
            ++c;
        }else if(r + x < n && M[r + x][c] == 'X'){
            go = true;
            
            if(get_sum(r + x,r + x,c,c + y - 1) != y)
                return false;
            aux += y;
            ++r;
        }
    }
    
    return aux == sum[n][m];
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    
    for(int i = 0;i < n;++i)
        cin >> M[i];
    
    sr = sc = -1;
    
    for(int i = 0;i < n && sr == -1;++i)
        for(int j = 0;j < m && sr == -1;++j)
            if(M[i][j] == 'X'){
                sr = i;
                sc = j;
            }
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < m;++j)
            sum[i + 1][j + 1] = (M[i][j] == 'X'? 1 : 0) + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
    
    vector<int> sol;
    
    int x = n,y = m;
    
    for(int i = 0;i < m;++i){
        int cont = 0;
        
        for(int j = 0;j < n;++j)
            if(M[j][i] == 'X')
                ++cont;
        
        if(cont > 0)
            x = min(x,cont);
    }
    
    for(int i = 0;i < n;++i){
        int cont = 0;
        
        for(int j = 0;j < m;++j)
            if(M[i][j] =='X')
                ++cont;
        
        if(cont > 0)
            y = min(y,cont);
    }
    
    for(int i = 1;i <= x;++i)
        if(check(i,y)){
            sol.push_back(i * y);
            break;
        }
    
    for(int i = 1;i < y;++i)
        if(check(x,i)){
            sol.push_back(i * x);
            break;
        }
    
    if(sol.empty()) cout << "-1\n";
    else{
        sort(sol.begin(),sol.end());
        cout << sol[0] << '\n';
    }
    
    return 0;
}
