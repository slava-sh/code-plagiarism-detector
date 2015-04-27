#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1024
#define NOANSWER 1123456789

using namespace std;
char map[MAXN][MAXN];
int tx,ty,cnt;
int n,m;

int ok(int,int);
int main(){
	//char map[MAXN][MAXN];
	//int tx=0,ty=0;
	int mw,mh,ans1=NOANSWER,ans2=NOANSWER;
	tx=0;cnt=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cin>>map[i][j];
			//cout<<map[i][j];
			if (map[i][j]=='X') cnt++;
			if ((!tx)&&(map[i][j]=='X')){
				tx=i;ty=j;
			}
		}
	if (tx==0){
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (((map[i][j]=='.')&&(map[i-1][j]=='X')&&(map[i][j-1]=='X'))
			   or(map[i][j]=='.')&&(map[i+1][j]=='X')&&(map[i][j+1]=='X'))
			{
				puts("-1");
				return 0;
			}
	for (mw=1;map[tx][ty+mw]=='X';mw++);
	for (mh=1;map[tx+mh][ty]=='X';mh++);
	//puts("ok");
	//cout<<mw<<' '<<mh;
	for (int i=1;i<=mw;i++)
		if(ok(i,mh)){
			ans1=i*mh;
			break;
		}
	for (int i=1;i<=mh;i++)
		if(ok(mw,i)){
			ans2=i*mw;
			break;
		}
	if (ans1>ans2) ans1=ans2;
	if (ans1==NOANSWER) puts("-1");
	else cout<<ans1<<endl;
	return 0;
}

int ok(int w,int h){
	int x=tx,y=ty,c=w*h;
	while(1){
		if ((map[x+h][y]=='X')){
			c+=w;
			x++;
		}
		else if ((map[x][y+w]=='X')){
			c+=h;
			y++;
		}
		else break;
	}
	return c==cnt;
}

