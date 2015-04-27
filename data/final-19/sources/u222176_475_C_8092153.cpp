#include<cstdio>
#include<algorithm>

using namespace std;

int sum[1050][1050]={0};
char d[1050][1050]={0};

int mark[1050][1050]={0};
int way[4][2]={
	{0,1},{1,0},{0,-1},{-1,0}
};

int dfsans=0;
void dfs(int x, int y){
	dfsans++;
	mark[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+way[i][0],ny=y+way[i][1];
		if(!mark[nx][ny]&&d[nx][ny]=='X'){
			dfs(nx,ny);
		}
	}
}

int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		getchar();
		for(int j=1;j<=m;j++){
			d[i][j]=getchar();
		}
	}

	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(d[i][j]=='X'?1:0);
		}
	}

	int x0,y0;
	for(x0=1;x0<=n;x0++) for(y0=1;y0<=m;y0++) if(d[x0][y0]=='X'){goto L0;}
L0:
	if(x0>n||y0>m){puts("-1");return 0;}
	dfs(x0,y0);
	//printf("%d\n",dfsans);
	//printf("%d\n",sum[n][m]);
	if(dfsans!=sum[n][m]){puts("-1");return 0;}

	unsigned int ans=0xFFFFFFFFLL;
	for(int i=x0;i<=n;i++){
		for(int j=y0;j<=m;j++){
			int x=i-x0+1,y=j-y0+1;
			unsigned int area=x*y;
			if(sum[i][j]-sum[x0-1][j]-sum[i][y0-1]+sum[x0-1][y0-1]!=area){
				continue;
			}
			int cnt=area;
			int cx=x0,cy=y0;
			while(1){
				int R,D;
				int nx,ny;
				nx=cx+1;ny=cy;
				D=sum[nx+x-1][ny+y-1]-sum[nx-1][ny+y-1]-sum[nx+x-1][ny-1]+sum[nx-1][ny-1]==area;
				nx=cx;ny=cy+1;
				R=sum[nx+x-1][ny+y-1]-sum[nx-1][ny+y-1]-sum[nx+x-1][ny-1]+sum[nx-1][ny-1]==area;
				if(D&&R){break;}
				if(!(D||R)){break;}
				if(D){cnt+=y;cx+=1;}
				if(R){cnt+=x;cy+=1;}
			}
			if(sum[n][m]==cnt){
				ans=min(ans,area);
			}
		}
	}
	
	printf("%d\n",ans);

	return 0;
}

