#pragma comment(linker, "/STACK:16777216")
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 

using namespace std; 

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

#define bublic public
#define TynKogep TOPCODER 
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define sz size()  
#define ld long double
#define ll long long
#define mp make_pair
#define istr istringstream

const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-9;

int u[700][700],g[700][700],a[700][2],b[700][2],n,m,R,h,t,q[400000][2],qb,qe,uu[400000],r[700][700];
//vector <int> v[200000];

int dfs(int x,int y)
{
//    cout<<x<<" "<<y<<endl;
    if (u[x][y]==2) return r[x][y];
    if (g[x][y]) return 1;
    u[x][y]=1;
    r[x][y]=0;
    
/*    for(int i=0;i<v[x].sz;i++)
    {
        if (uu[v[x][i]]==1) r[x]=1000000000;
//        cout<<x<<" "<<v[x][i]<<endl;
        r[x]=max(r[x],dfs(v[x][i])+1);
    }*/
    
        for(int i=0;i<n;i++)
        {
            if (x-i-1<0) break;
            int nx=x-i-1,ny=y;
            int zx=nx+a[i][0],zy=ny+a[i][1];   
            if (u[zx][zy]==1) r[x][y]=1000000000; else
            r[x][y]=max(r[x][y],dfs(zx,zy)+1);
        }    
        
        for(int i=0;i<m;i++)
        {
            if (y-i-1<0) break;
            int nx=x,ny=y-i-1;
            int zx=nx+b[i][0],zy=ny+b[i][1];
            if (u[zx][zy]==1) r[x][y]=1000000000; else
            r[x][y]=max(r[x][y],dfs(zx,zy)+1);            
        }        
    
    u[x][y]=2;
    return r[x][y];
}

int main()
{
//    freopen("q.in", "rt", stdin);
//    freopen("q.out", "wt", stdout);
    cout.flags(ios::fixed);
    cout.precision(2);
    cin>>h>>t>>R;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>b[i][0]>>b[i][1];
    }    
    clr(u);
    clr(g);
    qb=0;
    q[0][0]=h;
    q[0][1]=t;
    qe=1;
    u[h][t]=1;
  
    while(qb<qe)
    {
        int x=q[qb][0],y=q[qb][1];
        if (x+y==0)
        {
            cout<<"Ivan";
            cout<<endl<<u[0][0]-1;
            return 0;
        }
        if (x+y>R)
        {
            g[x][y]=1;
            qb++;
            continue;
        }
        
        for(int i=0;i<n;i++)
        {
            if (x-i-1<0) break;
            int nx=x-i-1,ny=y;
            int zx=nx+a[i][0],zy=ny+a[i][1];       
//            v[x*402+y].pb(zx*402+zy);     
            if (!u[zx][zy])
            {
                u[zx][zy]=u[x][y]+1;                
                q[qe][0]=zx;
                q[qe][1]=zy;
                qe++;
            }
        }

        for(int i=0;i<m;i++)
        {
            if (y-i-1<0) break;
            int nx=x,ny=y-i-1;
            int zx=nx+b[i][0],zy=ny+b[i][1];
//            v[x*402+y].pb(zx*402+zy);                 
            if (!u[zx][zy])
            {
                u[zx][zy]=u[x][y]+1;
                q[qe][0]=zx;
                q[qe][1]=zy;
                qe++;
            }
        }
        
        qb++;
    }
    clr(u);
    clr(r);
    int res=dfs(h,t);
    if (res>=1000000000) cout<<"Draw"; else
    {        
        cout<<"Zmey"<<endl<<res-1;
    }
//    if (res==0) cout<<"Draw";
//    if (res<0) cout<<"Zmey"<<endl<<-res-1;
//    cout<<res<<endl;
    return 0;
}
