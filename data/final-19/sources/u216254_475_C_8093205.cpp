#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
using namespace std;
int n,a,b,c,d,k,m;
char ch;
const int MXN=1e3+5;
int in[MXN][MXN];
int zerowdol(int i,int j)
{
for(int ii=i;ii<=n;ii++)if(in[ii][j]==0)return ii;
return n+1;
}
int jedenwdol(int i,int j)
{
for(int ii=i;ii<=n;ii++)if(in[ii][j]==1)return ii;
return n+1;
}
int zerowprawo(int i,int j)
{
for(int jj=j;jj<=m;jj++)if(in[i][jj]==0)return jj;
return m+1;
}
int jedenwprawo(int i,int j)
{
for(int jj=j;jj<=m;jj++)if(in[i][jj]==1)return jj;
return m+1;
}
int res=1e9;
PII X=MP(0,0);

int sum[MXN][MXN];
int suma=0;
int q(int a,int b,int c,int d)
{
//cout<<a<<" "<<b<<" "<<c<< " "<<d<<endl;
return sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
}
int cale(int a,int b,int c,int d)
{
if((c-a+1)*(d-b+1)!=q(a,b,c,d))return 0;
return 1;
}

void sprawdz(int wys,int szer)
{
if(wys<=0)wys=1;
if(szer<=0)szer=1;

//cout<<wys<<" "<<szer<<endl;

int ILE=szer*wys;
int x=X.f;
int y=X.s;
//cout<<q(x,y,x+wys-1,y+szer-1)<<endl;

while(1)
  {
//  cout<<x<<" "<<y<<endl;
  if(cale(x,y,x+wys-1,y+szer-1)==0)return;
  if(cale(x+1,y,x+wys,y+szer-1))//wdol
    {
    x++;
    ILE+=szer;
    }
  else
    {
    if(cale(x,y+1,x+wys-1,y+szer))
      {
      y++;
      ILE+=wys;
      }
    else
      {
      break;
      }
    }
  }
//cout<<ILE<<" s "<<suma<<endl;
if(ILE==suma)
  {
  res=min(res,szer*wys);
  }
}
void solve()
{
scanf("%d%d",&n,&m);

for(int i=1;i<=n;i++)
  {
  for(int j=1;j<=m;j++)
    {
    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    
    scanf(" %c",&ch);
    if(ch=='X'){in[i][j]=1;sum[i][j]++;suma++;}
    else in[i][j]=0;
    if(ch=='X'&&X.f==0)X=MP(i,j);
    
    
    }
  }
//pierwszy ruch w prawo
int i=X.f;
int j=X.s;
int wys=zerowdol(i,j)-i;
int szer=zerowprawo(i,j)-jedenwprawo(i+wys,j);
sprawdz(wys,szer);

szer=zerowprawo(i,j)-j;
wys=zerowdol(i,j)-jedenwdol(i,j+szer);
sprawdz(wys,szer);

if(res==1000000000)puts("-1");
else printf("%d\n",res);
}
main()
{
solve();
}
