#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 1010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,x,y,an;
int a[N][N],f1[N][N],f2[N][N];
char p[N][N];
inline int cal(int x,int y,int lx,int ly) {
	x--,y--;
	return a[x+lx][y+ly]-a[x][y+ly]-a[x+lx][y]+a[x][y];
}
inline void ju(int lx,int ly) {
	int x,y;
	For(x,1,n)For(y,1,m) if (p[x][y]=='X') goto yy2;
	yy2:;
	int s=cal(x,y,lx,ly);
	if (s!=lx*ly) return;
	for (;;) {
		int f1,f2;
		f1=f2=0;
		if (x+lx<=n&&cal(x+1,y,lx,ly)==lx*ly) f1=1;
		if (y+ly<=m&&cal(x,y+1,lx,ly)==lx*ly) f2=1;
		if (f1&&f2) return;
		if (!f1&&!f2) break;
		if (f1) x++,s+=ly;
		else y++,s+=lx;
	}
	if (s==a[n][m]) an=min(an,lx*ly);
}
int main() {
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",p[i]+1);
	For(i,1,n)For(j,1,m) a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(p[i][j]=='X');
	For(i,1,n)for (j=m;j;j--) if (p[i][j]=='X') {
		if (f1[i][j+1]) f1[i][j]=f1[i][j+1];
		else f1[i][j]=j;
	}
	For(j,1,m)for (i=n;i;i--) if (p[i][j]=='X') {
		if (f2[i+1][j]) f2[i][j]=f2[i+1][j];
		else f2[i][j]=i;
	}
	{
		For(x,1,n)For(y,1,m) if (p[x][y]=='X') goto yy1;
		yy1:;
		an=N*N;
		{
			int A=f2[x][y],lx=A-x+1,ly=1;
			For(i,y,f1[x][y]) if (f2[A][i]>A) {
				ly=f1[x][y]-i+1;
				break;
			}
			ju(lx,ly);
		}
		{
			int A=f1[x][y],ly=A-y+1,lx=1;
			For(i,x,f2[x][y]) if (f1[i][A]>A) {
				lx=f2[x][y]-i+1;
				break;
			}
			ju(lx,ly);
		}
	}
	if (an==N*N) printf("-1\n");
	else printf("%d\n",an);
	return 0;
}
