#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define INF 1000000000
#define PI 3.1415926535897932
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define SZ 1005
const int X[]={-1,0,1,0},Y[]={0,-1,0,1};
vector <bool> u;
vector <pair<int,int> > coor;
char a[SZ][SZ];
int ans[SZ][SZ];
int d[SZ][SZ],c,n,m;
bool was[SZ][SZ];
bool chk(int x,int y){return x>=0 && x<n && y>=0 && y<m;}
void dfs(int x,int y,int k)
{
  if (d[x][y]==k)coor.pb(mp(x,y));
  if (d[x][y]!=k)
  {
    if (ans[x][y]==INF)return;
    u[ans[x][y]]=true;
    return;
  }
  was[x][y]=true;
  for(int c=0;c<4;c++)
    if (chk(x+X[c],y+Y[c]) && !(was[x+X[c]][y+Y[c]] && d[x+X[c]][y+Y[c]]==k))dfs(x+X[c],y+Y[c],k);
}
int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>a[i][j],ans[i][j]=INF;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if (a[i][j]=='.' && a[i][j+1]=='.' && d[i][j]==0 && d[i][j+1]==0)d[i][j]=d[i][j+1]=++c;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if (a[i][j]=='.' && a[i+1][j]=='.' && d[i][j]==0 && d[i+1][j]==0)d[i][j]=d[i+1][j]=++c;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if (a[i][j]=='.' && d[i][j]==0)
      {
        bool can=false;
        for(int c=0;c<4;c++)
          if (chk(i+X[c],j+Y[c]) && a[i+X[c]][j+Y[c]]=='.')
          {
            can=true;
            d[i][j]=d[i+X[c]][j+Y[c]];
            break;
          }
        if (!can)
        {
          cout<<-1;
          return 0;
        }
      }
  //for(int i=0;i<n;i++,cout<<endl)
    //for(int j=0;j<m;j++)cout<<d[i][j]<<" ";
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if (a[i][j]=='.' && ans[i][j]==INF)
      {
        coor.clear();
        u.clear();
        u.resize(10);
        dfs(i,j,d[i][j]);
        //cout<<coor.size()<<endl;
        for(int c=0;c<10;c++)
          if (!u[c])
          {
            for(int t=0;t<coor.size();t++) ans[coor[t].f][coor[t].s]=c;
            break;
          }
      }
  for(int i=0;i<n;i++,cout<<endl)
    for(int j=0;j<m;j++)
      if (ans[i][j]==INF)cout<<'#';
      else cout<<char(ans[i][j]+'0');
  return 0;
}