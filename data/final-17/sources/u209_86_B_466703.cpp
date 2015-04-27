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

#define TynKogep TOPCODER
#define bublic public:
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define sz size()
#define ld long double
#define ll long long
#define istr istringstream
#define re return
#define fi first
#define se second
#define mp make_pair
#define y0 y32479
#define y1 y95874

const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-9;

int n,m,c[1024][1024],u[12];
char a[1024][1024];

void dfs(int x,int y)
{
    a[x][y]='.';
    
    if (x-1>=0 && (a[x-1][y]>='0' && a[x-1][y]<='9')) u[a[x-1][y]-'0']=1;
    if (y-1>=0 && (a[x][y-1]>='0' && a[x][y-1]<='9')) u[a[x][y-1]-'0']=1;
    if (x+1<n && (a[x+1][y]>='0' && a[x+1][y]<='9')) u[a[x+1][y]-'0']=1;
    if (y+1<m && (a[x][y+1]>='0' && a[x][y+1]<='9')) u[a[x][y+1]-'0']=1;    
    
    if (x-1>=0 && c[x][y]==c[x-1][y] && a[x-1][y]!='.') dfs(x-1,y);
    if (y-1>=0 && c[x][y]==c[x][y-1] && a[x][y-1]!='.') dfs(x,y-1);
    if (x+1<n && c[x][y]==c[x+1][y] && a[x+1][y]!='.') dfs(x+1,y);
    if (y+1<m && c[x][y]==c[x][y+1] && a[x][y+1]!='.') dfs(x,y+1);
}

void dfs2(int x,int y,int col)
{
    a[x][y]=col+'0';
    if (x-1>=0 && c[x][y]==c[x-1][y] && a[x-1][y]!=col+'0') dfs2(x-1,y,col);
    if (y-1>=0 && c[x][y]==c[x][y-1] && a[x][y-1]!=col+'0') dfs2(x,y-1,col);    
    if (x+1<n && c[x][y]==c[x+1][y] && a[x+1][y]!=col+'0') dfs2(x+1,y,col);
    if (y+1<m && c[x][y]==c[x][y+1] && a[x][y+1]!=col+'0') dfs2(x,y+1,col);        
}

int main()
{
//    freopen("q.in", "rt", stdin);
//    freopen("q.out", "wt", stdout);
    cout.flags(ios::fixed);
    cout.precision(2);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%c",&a[i][0]);
        for(int j=0;j<m;j++)
        {
            scanf("%c",&a[i][j]);            
        }
    }
    
    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if (a[i][j]=='.')
    {
        bool minusone=true;
        if (i && a[i-1][j]=='.') minusone=false;
        if (j && a[i][j-1]=='.') minusone=false;        
        if (i+1<n && a[i+1][j]=='.') minusone=false;
        if (j+1<m && a[i][j+1]=='.') minusone=false;  
        if (minusone)
        {
            cout<<-1;
            return 0;
        }              
    }
        
    int k=1;
    clr(c);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if (a[i][j]=='.')    
    {
        if (i+1<n && a[i+1][j]=='.')
        {
            a[i][j]='#';
            a[i+1][j]='#';
            c[i][j]=k;
            c[i+1][j]=k;
            k++;
        }
        else 
        if (j+1<m && a[i][j+1]=='.')
        {
            a[i][j]='#';
            a[i][j+1]='#';
            c[i][j]=k;
            c[i][j+1]=k;
            k++;
        }        
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if (a[i][j]=='.')
    {
        if (i && c[i-1][j]) 
        {
            c[i][j]=c[i-1][j];
        }
        if (j && c[i][j-1])
        {
            c[i][j]=c[i][j-1];
        }
        if (i+1<n && c[i+1][j])
        {
            c[i][j]=c[i+1][j];
        }
        if (j+1<m && c[i][j+1])
        {
            c[i][j]=c[i][j+1];
        }
        a[i][j]='#';
    }    
    
/*    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)    
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
/*            cout<<endl;            
            for(int A=0;A<n;A++){
            for(int B=0;B<m;B++)
            cout<<a[A][B];
            cout<<endl;}
            cout<<endl;*/
            
            
            if (!c[i][j]) printf("#"); else
            {
                if (a[i][j]!='#')
                {
                    printf("%c",a[i][j]);
                }
                else
                {
                    clr(u);
                    dfs(i,j);
          
            
                    for(int q=0;q<10;q++)
                    if (!u[q])
                    {
                        dfs2(i,j,q);
                        break;
                    }
                    printf("%c",a[i][j]);
                }
            }
        }
        puts("");
    }    
    re 0;
}
