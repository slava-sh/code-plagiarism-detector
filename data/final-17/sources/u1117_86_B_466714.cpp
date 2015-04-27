//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++) 
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >= 0; i--)
#define REP(i,a) for(int i = 0; i < (a); i++)
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define For(i,a,b) for(int i = (a); i <= (b); i++)

#define sqr(x) ((x)*(x))
#define dout debug && cout 
#define ll long long
#define sz size()
#define ull unsigned long long
#define pb push_back
#define oo 1000000009
/* DEBUGGING */
bool debug = false;
/* MAIN PROGRAM */

using namespace std;

/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
string convertToString(long long a) {
    string res = ""; if (!a) return "0";
    while (a) { res = (char)(a % 10 + 48) + res;  a /= 10; }
    return res;
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}

//newstate = (newstate-1) & oldstate
/**************************CODE HERE*****************************/
#define maxn 1010
int m,n;
char s[maxn][maxn];
char p[maxn];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
bool dd[300];

void khoiphuc(int X, int Y, int row, int col, string saved) {
    int cnt = 0;
    FOR(i,X,X+row-1)
    FOR(j,Y,Y+col-1) {
        s[i][j] = saved[cnt];
        cnt++;
    }
}
bool test(int X, int Y) {
    FR(k,4)
    if (X + dx[k] >= 0 && X + dx[k] < m && Y + dy[k] >= 0 && Y + dy[k] < n)
    if (s[X+dx[k]][Y+dy[k]] == '.') return true;
    return false;
}
bool fill(int X,int Y, int row, int col, string state) {
    //validation
    if (X + row - 1 >= m) return false;
    if (Y + col - 1>= n) return false;
//    cout << "DONE" << endl;
    int cnt = 0;
    FOR(i,X,X+row-1)
    FOR(j,Y,Y+col-1) {
        if (s[i][j] != '.' && state[cnt] == 'x') return false;
        cnt++;
    }
//    cout << "DONE" << endl;
    
    string saved = "";
    FOR(i,X,X+row-1)
    FOR(j,Y,Y+col-1) saved.push_back( s[i][j] );
    
    //kiem tra xem co ton tai dinh treo ko
    cnt = 0;
    FOR(i,X,X+row-1) 
    FOR(j,Y,Y+col-1) {
        if (s[i][j] == '.' && state[cnt] == 'x') s[i][j] = 'x';
        cnt++;
    }
    
    FOR(i,X,X+row-1)
    FOR(j,Y,Y+col-1)
    FR(k,4)
    if (i + dx[k] >= 0 && i + dx[k] < m && j + dy[k] >= 0 && j + dy[k] < n) 
    if (s[i+dx[k]][j+dy[k]] == '.') 
    if (!test(i+dx[k],j+dy[k])) {
        khoiphuc(X,Y,row,col,saved);
        return false;
    }
//    cout << "DONE" << endl;
    
    FOR(kt,'0','9') dd[kt] = true;
    FOR(i,X,X+row-1)
    FOR(j,Y,Y+col-1)
    if (s[i][j] == 'x')
    FR(k,4)
    if (i + dx[k] >= 0 && i + dx[k] < m && j + dy[k] >= 0 && j + dy[k] < n) 
    if ('0' <= s[i+dx[k]][j+dy[k]] && s[i+dx[k]][j+dy[k]] <= '9') {
        dd[ s[i+dx[k]][j+dy[k]] ] = false;
    }
    
    char findChar;
    FOR(kt,'0','9')
    if (dd[kt]) {
        findChar = kt;
        break;
    }
    
    FOR(i,X,X+row-1) 
    FOR(j,Y,Y+col-1) 
    if (s[i][j] == 'x') s[i][j] = findChar;
    return true;
}
bool attempt(int X, int Y) {
    // xx
    //2
    
    if (fill(X,Y,1,2,"xx")) return true;
    if (fill(X,Y,2,1,"xx")) return true;
    
    if (fill(X,Y,1,3,"xxx")) return true;
    if (fill(X,Y,3,1,"xxx")) return true;
    if (fill(X,Y,2,2,"xxx.")) return true;
    if (fill(X,Y,2,2,"xx.x")) return true;
    if (fill(X,Y,2,2,"x.xx")) return true;
    if (Y > 0 && fill(X,Y-1,2,2,".xxx")) return true;
    
    
    if (fill(X,Y,2,3,"xxx.x.")) return true;
    
    if (Y > 0 && fill(X,Y-1,2,3,".x.xxx")) return true;
    if (fill(X,Y,3,2,"x.xxx.")) return true;
    if (Y > 0 && fill(X,Y-1,3,2,".xxx.x")) return true;
    
    //5 
    if (Y > 0 && fill(X,Y-1,3,3,".x.xxx.x.")) return true;
    
    return false;
}
int main() {
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    cin >> m >> n;
    gets(p);
    FR(i,m) gets(s[i]);
    
    //solve
    FR(i,m) FR(j,n)
    if (s[i][j] == '.') 
    if (!attempt(i,j)) {
        cout << -1 << endl;
        return 0;
    } 
    FR(i,m) puts(s[i]);
//    system("pause");
    return 0;
}

