#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
const int INF = 2147483647;
const double PI = 3.141592653589793;

queue <ii> kol;
ii w,w2;
int res[700][700],h,t,R,i,j,m,n,tab[205][2],tab2[205][2],minn,vis[700][700],r[700][700],wch[700][700];
bool rem;
vector <ii> graf[700][700];

bool dfs (int a, int b) {
     //printf("%d %d\n",a,b);
     vis[a][b]=1;
     for (int i=0;i<graf[a][b].size();i++) {
         if (vis[graf[a][b][i].first][graf[a][b][i].second]==1) return true;
         if (vis[graf[a][b][i].first][graf[a][b][i].second]==0 && dfs(graf[a][b][i].first,graf[a][b][i].second)) return true;
     }
     vis[a][b]=2;
     return false;
}

int jedz () {
    int a,b,c,d,maxx=0;
    while (!kol.empty()) kol.pop();
    kol.push(ii(h,t));
    r[h][t]=0;
    while (!kol.empty()) {
          w=kol.front();
          c=w.first;
          d=w.second;
          kol.pop();
          for (i=0;i<graf[c][d].size();i++) {
              a = graf[c][d][i].first;
              b = graf[c][d][i].second;
              r[a][b]=max(r[a][b],r[c][d]+1);
              maxx=max(maxx,r[a][b]);
              wch[a][b]--;
              if (wch[a][b] == 0) kol.push(ii(a,b));
          }
    }  
    return maxx+1;                                                                                
}

int main () {
scanf ("%d %d %d",&h,&t,&R);
scanf ("%d",&n);
for (i=1;i<=n;i++) scanf ("%d %d",&tab[i][0],&tab[i][1]);
scanf ("%d",&m);
for (i=1;i<=m;i++) scanf ("%d %d",&tab2[i][0],&tab2[i][1]);
while (!kol.empty()) kol.pop();
for (i=0;i<=605;i++) for (j=0;j+i<=605;j++) {
    res[i][j]=-1;
    graf[i][j].resize(0);
    vis[i][j]=0;
    wch[i][j]=0;
    r[i][j]=-1;
}
res[h][t]=0;
kol.push(ii(h,t));
while (!kol.empty()) {
      w = kol.front();
      //printf("%d %d %d\n",w.first,w.second,res[w.first][w.second]);
      kol.pop();
      for (i=1;i<=min(w.first,n);i++) {
          w2.first = w.first - i + tab[i][0];
          w2.second = w.second + tab[i][1];
          if (res[w2.first][w2.second]==-1) {
             res[w2.first][w2.second]=res[w.first][w.second]+1;
             if (w2.first+w2.second <= R) kol.push(w2);
          }
          if (w2.first + w2.second <= R) {
             graf[w.first][w.second].pb(w2);
             wch[w2.first][w2.second]++;
          }
      }
      for (i=1;i<=min(w.second,m);i++) {
          w2.first = w.first + tab2[i][0];
          w2.second = w.second - i + tab2[i][1];
          if (res[w2.first][w2.second]==-1) {
             res[w2.first][w2.second]=res[w.first][w.second]+1;
             if (w2.first+w2.second <= R) kol.push(w2);
          }
          if (w2.first + w2.second <= R) {
             graf[w.first][w.second].pb(w2);
             wch[w2.first][w2.second]++;
          }
      }
}
if (res[0][0]!=-1) printf("Ivan\n%d\n",res[0][0]);
else if (dfs(h,t)) printf("Draw\n");
else {
     r[h][t]=0;
     printf("Zmey\n%d\n",jedz());
}
return 0;
}
