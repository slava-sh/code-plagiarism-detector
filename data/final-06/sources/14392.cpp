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

typedef long long ll;

int H,W;
string board[40];
vector <vector <pair <int, int> > > square;
vector <vector <pair <int, int> > > domino;

bool used[10][10];
int rem[10];
int a[20];
int board2[40][40];
int example[40][40];

bool check(void){
    int i,j;
    
    REP(i,14) REP(j,4){
        int x = square[i][j].first;
        int y = square[i][j].second;
        board2[x][y] = a[i];
    }
    
    REP(i,7) REP(j,7) used[i][j] = false;
    REP(i,28){
        int x = board2[domino[i][0].first][domino[i][0].second];
        int y = board2[domino[i][1].first][domino[i][1].second];
        if(x > y) swap(x,y);
        if(used[x][y]) return false;
        used[x][y] = true;
    }
    
    REP(i,H) REP(j,W) example[i][j] = -1;
    REP(i,14) REP(j,4){
        int x = square[i][j].first;
        int y = square[i][j].second;
        example[x][y] = a[i];
    }
    
    return true;
}

int dfs(int pos){
    if(pos == 14){
        bool tmp = check();
        return (tmp ? 1 : 0);
    }
    int ans = 0;
    int j;
    REP(j,7) if(rem[j] > 0){
        a[pos] = j; rem[j]--; ans += dfs(pos+1); rem[j]++;
        if(rem[j] == 2) break;
    }
    return ans;
}

int main(void){
    int i,j,di,dj,k;
    
    cin >> H >> W;
    REP(i,H) cin >> board[i];
    
    REP(i,28){
        char ch = ((i < 26) ? ('a' + i) : ('A' + (i - 26)));
        vector <pair <int, int> > v;
        REP(j,H) REP(k,W) if(board[j][k] == ch) v.push_back(make_pair(j,k));
        domino.push_back(v);
    }
    
    REP(i,H) REP(j,W) if(board[i][j] != '.'){
        vector <pair <int, int> > v;
        REP(di,2) REP(dj,2){
            v.push_back(make_pair(i+di,j+dj));
            board[i+di][j+dj] = '.';
        }
        square.push_back(v);
    }
    
    REP(i,7) rem[i] = 2;
    ll ans = dfs(0);
    ans *= 5040;
    
    cout << ans << endl;
    REP(i,H){
        string s;
        REP(j,W){
            char ch = '.';
            if(example[i][j] >= 0 && example[i][j] < 7) ch = '0' + example[i][j];
            s += ch;
        }
        cout << s << endl;
    }
    
    return 0;
}
