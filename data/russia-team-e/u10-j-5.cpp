#include <iostream>
#include <iomanip>
using namespace std;
const int maxn = 505;
char Ch[maxn][maxn];
char c[maxn][maxn];
int way[maxn][maxn];
int S[maxn][maxn];
int n,m,N;
pair<int,int>L[maxn*maxn];
int len = 0;

void OUT(int i, int j){
    if(c[i][j] == '&') return ;
    if(c[i][j] == 'N') OUT(i+1,j);
    if(c[i][j] == 'S') OUT(i-1,j);
    if(c[i][j] == 'W') OUT(i,j+1);
    if(c[i][j] == 'E') OUT(i,j-1);
    putchar(c[i][j]);
}

bool isReally_index(int i, int M){
    return i >= 0 && i < M;
}
void Insert_pair(pair<int,int>a){
    int i,j;
    i = a.first; j = a.second;
    if(isReally_index(i - 1,m)){
        int I = i - 1, J = j;
        if(!c[I][J] || (way[I][J] == way[i][j] + 1 && S[i][j] + (Ch[I][J] == 'T') > S[I][J])){
            S[I][J] = S[i][j] + Ch[I][J] == 'T';
            way[I][J] = way[i][j] + 1;
            if(!c[I][J]) L[len ++] = pair<int,int>(I,J);
            c[I][J] = 'N';
        }
    }

    if(isReally_index(i + 1,m)){
        int I = i + 1, J = j;
        if(!c[I][J] || (way[I][J] == way[i][j] + 1 && S[i][j] + (Ch[I][J] == 'T') > S[I][J])){
            S[I][J] = S[i][j] + Ch[I][J] == 'T';
            way[I][J] = way[i][j] + 1;
            if(!c[I][J]) L[len ++] = pair<int,int>(I,J);
            c[I][J] = 'S';
        }
    }

    if(isReally_index(j - 1,n)){
        int I = i, J = j - 1;
        if(!c[I][J] || (way[I][J] == way[i][j] + 1 && S[i][j] + (Ch[I][J] == 'T') > S[I][J])){
            S[I][J] = S[i][j] + Ch[I][J] == 'T';
            way[I][J] = way[i][j] + 1;
            if(!c[I][J]) L[len ++] = pair<int,int>(I,J);
            c[I][J] = 'W';
        }
    }

    if(isReally_index(j + 1,n)){
        int I = i, J = j + 1;
        if(!c[I][J] || (way[I][J] == way[i][j] + 1 && S[i][j] + (Ch[I][J] == 'T') > S[I][J])){
            S[I][J] = S[i][j] + (Ch[I][J] == 'T');
            way[I][J] = way[i][j] + 1;
            if(!c[I][J]) L[len ++] = pair<int,int>(I,J);
            c[I][J] = 'E';
        }
    }
}
void Insert_way(){
    for(int i = 0; i < len; i ++) Insert_pair(L[i]);
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m>>N;
    for(int i = 0; i < m; i ++)cin>>Ch[i];
    for(int i = 0; i < m; i ++)
       for(int j = 0; j < n; j ++)
          if(Ch[i][j] == 'V') L[len ++] = pair<int,int>(i,j);
    c[L[0].first][L[0].second] = '&';

    Insert_way();

    pair<int,int>Index_solve;
    int SC = 0,Way = (int)1e9,WW,NN,FF;
    for(int i = 0; i < m; i ++)
       for(int j = 0; j < n; j ++)
          if(Ch[i][j] == 'T'){
              WW = way[i][j];
              NN = n - S[i][j];
              if(NN < 0)NN = 0;
              FF = 0;
              if(isReally_index(i - 1, m) && Ch[i-1][j] == 'T')FF = true;
              if(isReally_index(i + 1, m) && Ch[i+1][j] == 'T')FF = true;
              if(isReally_index(j - 1, n) && Ch[i][j-1] == 'T')FF = true;
              if(isReally_index(j + 1, n) && Ch[i][j+1] == 'T')FF = true;
              if(FF)WW += NN;
              else WW += NN * 2;
              if(Way > WW){
                  Way = WW;
                  Index_solve = pair<int,int>(i,j);
              }
          }
    OUT(Index_solve.first,Index_solve.second);
    N = N - S[Index_solve.first][Index_solve.second];
    int i = Index_solve.first, j = Index_solve.second;
    int I,J;
    char NSWE;
    while(N){
        if(isReally_index(i-1,m))I = i - 1, J = j, NSWE = 'N';
        if(isReally_index(i+1,m))I = i + 1, J = j, NSWE = 'S';
        if(isReally_index(j-1,n))I = i, J = j - 1, NSWE = 'W';
        if(isReally_index(j+1,n))I = i, J = j + 1, NSWE = 'E';

        if(isReally_index(i-1,m) && Ch[i - 1][j] == 'T')I = i - 1, J = j, NSWE = 'N';
        if(isReally_index(i+1,m) && Ch[i + 1][j] == 'T')I = i + 1, J = j, NSWE = 'S';
        if(isReally_index(j-1,n) && Ch[i][j - 1] == 'T')I = i, J = j - 1, NSWE = 'W';
        if(isReally_index(j+1,n) && Ch[i][j + 1] == 'T')I = i, J = j + 1, NSWE = 'E';
        N -= Ch[I][J] == 'T';
        putchar(NSWE);
        i = I; j = J;
    }
    cout<<endl;
    return 0;
}
