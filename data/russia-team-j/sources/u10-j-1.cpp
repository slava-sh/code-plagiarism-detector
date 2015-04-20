#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
bool isReally_index(int i, int m){
    return i >= 0 && i < m;
}
const int maxn = 505;
vector<pair<int,int> >len_i[maxn<<1];
char c[maxn][maxn];
char WENS[maxn][maxn];

void WRITE(int i, int j){
    if(WENS[i][j] == '&') return ;
    if(WENS[i][j] == 'N') WRITE(i+1,j);
    if(WENS[i][j] == 'S') WRITE(i-1,j);
    if(WENS[i][j] == 'W') WRITE(i,j+1);
    if(WENS[i][j] == 'E') WRITE(i,j-1);
    putchar(WENS[i][j]);
}

int T[maxn][maxn];
int lens[maxn][maxn];
int n,m,t;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m>>t;
    int i,j,q,I,J,l,I1,J1,I_id,J_id,max_T,TT;
    for(i = 0; i < m; i ++)
       for(j = 0; j < n; j ++){
           cin>>c[i][j];
           if(c[i][j] == 'V') I = i, J = j;
       }
    WENS[I][J] = '&';
    for(i = 0; i < m; i ++)
       for(j = 0; j < n; j ++){
           lens[i][j] = abs(i-I)+abs(j - J);
          len_i[lens[i][j]].push_back(pair<int,int>(i,j));
        }
    i = 1;
    while(!len_i[i].empty()){
        l = len_i[i].size();
        for(j = 0; j < l; j ++){
            I = len_i[i][j].first;
            J = len_i[i][j].second;
            for(q = 0; q < 4; q ++){
                I1 = I + dx[q];
                J1 = J + dy[q];
                if(isReally_index(I1,m) && isReally_index(J1,n) && lens[I1][J1] == lens[I][J] - 1)I_id = I1,J_id = J1;
            }
            max_T = 0;
            for(q = 0; q < 4; q ++){
                I1 = I + dx[q];
                J1 = J + dy[q];
                if(isReally_index(I1,m) && isReally_index(J1,n)  && lens[I1][J1] == lens[I][J] - 1 && T[I1][J1] > max_T)I_id = I1,J_id = J1, max_T = T[I1][J1];
            }
            WENS[I][J] = I_id > I ? 'N' : I_id < I ? 'S' : J_id > J ? 'W' : 'E';
            T[I][J] = T[I_id][J_id] + (c[I][J] == 'T');
        }
        i++;
    }
    int result_T = 1000000000;
    int result_I, result_J;
    for(i = 0; i < m; i ++){
       for(j = 0; j < n; j ++){
           if(c[i][j] == 'T'){
               TT = lens[i][j];
               I = t - T[i][j];
               if(I < 0)I = 0;

                for(q = 0; q < 4; q ++){
                    I1 = i + dx[q];
                    J1 = j + dy[q];
                    if(isReally_index(I1,m) && isReally_index(J1,n))I_id = I1,J_id = J1;
                }
                max_T = 0;
                for(q = 0; q < 4; q ++){
                    I1 = i + dx[q];
                    J1 = j + dy[q];
                    if(isReally_index(I1,m) && isReally_index(J1,n) && c[I1][J1] == 'T')I_id = I1,J_id = J1, max_T = T[I1][J1];
                }

               if(c[I_id][J_id] == 'T') TT += I;
               else TT += I * 2;

               if(TT < result_T) {
                   result_T = TT;
                   result_I = i;
                   result_J = j;
               }
           }
       }
    }

    WRITE(result_I,result_J);
    t -= T[result_I][result_J];
    while(t){
                for(q = 0; q < 4; q ++){
                    I1 = result_I + dx[q];
                    J1 = result_J + dy[q];
                    if(isReally_index(I1,m) && isReally_index(J1,n))I_id = I1,J_id = J1;
                }
                for(q = 0; q < 4; q ++){
                    I1 = result_I + dx[q];
                    J1 = result_J + dy[q];
                    if(isReally_index(I1,m) && isReally_index(J1,n) && c[I1][J1] == 'T')I_id = I1,J_id = J1;
                }
        t -= c[I_id][J_id] == 'T';

        putchar(result_I > I_id ? 'N' : result_I < I_id ? 'S' : result_J > J_id ? 'W' : 'E');
        result_I = I_id;
        result_J = J_id;
    }
    cout<<endl;
    return 0;
}
