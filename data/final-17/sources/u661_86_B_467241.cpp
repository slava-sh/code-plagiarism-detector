#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#define ss(x)   cout<<"DEBUG : "#x" = "<<(x)<<"\n"
#define pv(i,n) ((i)>0?(i)-1:(n)-1)
#define nx(i,n) ((i)+1<(n)?(i)+1:0)
#define umap    tr1::unordered_map
#define uset    tr1::unordered_set
#define TT      template<typename T>
#define TAB     template<typename A,typename B>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
TT T abs(const T&x) {return x<0?-x:x;}
TT T sq(const T&x) {return x*x;}
TT void mil(T&a,const T&b) {if(a>b)a=b;}
TT void mal(T&a,const T&b) {if(a<b)a=b;}
TT void usort(vector<T>&a) {sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());}
TT T gcd(T a,T b) {while(b!=0){T t=a%b;a=b;b=t;}return a;}
TT pair<T,T> operator+(const pair<T,T>&a,const pair<T,T>&b) {return pair<T,T>(a.first+b.first,a.second+b.second);}
TT pair<T,T> operator-(const pair<T,T>&a,const pair<T,T>&b) {return pair<T,T>(a.first-b.first,a.second-b.second);}
TAB istream&operator>>(istream&i,pair<A,B>&v) {return i>>v.first>>v.second;}
TAB B conv(const A&i) {stringstream s;s<<i;B o;s>>o;return o;}

char mat[1024][1024];
int dr[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
char h[2][2]={'0','1','2','3'};
char s[2][3]={'4','5','6','7','8','9'};
bool good(char x){
    return x<='3'&&x>='0';
}

void york() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>mat[i]+1;
    for(int i=1;i<=n;++i){
        int p=0;
        int q=0;
        for(int j=1;j<=m;++j){
            if(mat[i][j]=='.'){
                if(j+1<=m&&mat[i][j+1]=='.'){
                    mat[i][j]=h[i&1][p];
                    mat[i][j+1]=h[i&1][p];
                    p^=1;
                }else if(j+1<=m&&isdigit(mat[i][j+1])){
                    mat[i][j]=mat[i][j+1];
                }else if(i+1<=n&&mat[i+1][j]=='.'){
                    mat[i][j]=s[q][i%3];
                    mat[i+1][j]=s[q][i%3];
                    q^=1;
                }
            }
        }
    }
    //for(int i=1;i<=n;++i)cout<<mat[i]+1<<'\n';
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(mat[i][j]=='.'){
                bool flag=false;
                for(int k=0;k<4;++k){
                    if(isdigit(mat[i+dr[k][0]][j+dr[k][1]])){
                        flag=true;
                        mat[i][j]=mat[i+dr[k][0]][j+dr[k][1]];
                    }
                }
                if(!flag){
                    cout<<-1;
                    return;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<mat[i]+1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    york();
    return 0;
}
