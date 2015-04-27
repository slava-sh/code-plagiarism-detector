#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 0
#define nmax 511
int n,m,mod;
char a[nmax][nmax];
int d[nmax];
int f[nmax][nmax];
long long ans;
int c[3];
int call(int x, int y){

    if (x==0 && y==0) return 1;
    if (f[x][y]>-1) return f[x][y];
    long long res=0;
    if (x>=2){
        long long tmp=(long long)x*(x-1)*call(x-2,y+2)/2;
        int value= tmp%mod;
        res=(res+value)%mod;
    }
    if (x>=1 && y>=1){
        long long tmp= (long long) x*y*call(x-1,y);
        int value= tmp%mod;
        res=(res+value)%mod;
    }
    if (y>=2){
        long long tmp= (long long) y*(y-1)*call(x,y-2)/2;
        int value= tmp%mod;
        res=(res+value)%mod;
    }
    f[x][y]=res;
    //printf("Call[%3d][%3d]:%4d\n",x,y,f[x][y]);
    return res;
}
int main(){
    cin>>n>>m>>mod;
    FOR(i,1,m){
        scanf("%s",a[i]+1);
        FOR(j,1,n) if (a[i][j]=='1') d[j]++;
        //printf("%s\n",a[i]+1);
    }
    FOR(i,1,n) c[d[i]]++;
    FOR(i,0,n) FOR(j,0,n) f[i][j]=-1;
    ans=call(c[0],c[1]);
    cout<<ans<<endl;
    return 0;
}
