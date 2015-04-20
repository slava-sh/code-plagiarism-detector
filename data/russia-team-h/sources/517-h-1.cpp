#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("secure.in");
ofstream out("secure.out");
const int inf = 1000000000;
int n,m,x,y,c,ox,oy,od=inf;
bool isc=false;
vector<int> g;
vector<vector<int> > D;
int main(){
    in>>n>>m;
    g.assign(n+1,0);
    c(i,1,n) in>>g[i];
    D.assign(n+1,vector<int>(n+1,inf));
    c(i,1,n) D[i][i]=0;
    c(i,1,m){
        in>>x>>y>>c;
        D[x][y]=c;D[y][x]=c;
    }
    c(k,1,n) c(i,1,n) c(j,1,n)
    if (D[i][k]<inf&&D[k][j]<inf)
        D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
    c(i,1,n) c(j,1,n)
    if (g[i]==1&&g[j]==2&&D[i][j]<od) {ox=i;oy=j;od=D[i][j];isc=true;}
    if (isc) out<<ox<<" "<<oy<<" "<<od; else out<<-1;
}
