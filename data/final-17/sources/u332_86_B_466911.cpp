#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

int n,m;
char a[1100][1100];
int used[1100][1100];
int ind[1100][1100];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
vector <pair<int,int> > nv;

vector <pair<int,int> > dm[1000000];
int v=0;

/*void dfs(int x,int y,vector <pair<int,int> > cur){
	if (used[x][y]||a[x][y]=='#') return;
	used[x][y]=1;
	if (cur.size()==2){
		int u[10];
		memset(u,0,sizeof(u));
		for (int i=0; i<cur.size(); i++){
			for (int j=0; j<4; j++)
				if (a[cur[i].first+dx[j]][cur[i].second+dy[j]]!='.')
					u[a[cur[i].first+dx[j]][cur[i].second+dy[j]]-'0']=1;
		}
		int gd=0;
		for (int i=0; i<10; i++)
			if (!u[i]){
				gd=i;
				break;
			}
		for (int i=0; i<cur.size(); i++){
			a[cur[i].first][cur[i].second]=gd;
		}

		for (int i=0; i<4; i++){
			nv.clear();
			nv.push_back(make_pair())
		}

		cur.clear();
	} else
	{
		for (int i=0; i<4; i++){
			nv=cur;
			nv.push_back(make_pair(x+dx[i],y+dy[i]));
			dfs(x+dx[i],y+dy[i],nv);
		}
	}
}*/

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	for (int i=0; i<1100; i++)
		for (int j=0; j<1100; j++)
			a[i][j]='#';
	scanf("%d%d\n",&n,&m);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			scanf("%c",&a[i][j]);
		}
		scanf("\n");
	}

	/*for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i][j]=='.'){
				vector <pair<int,int> > tk;
				tk.push_back(make_pair(i,j));
				dfs(i,j,tk);
			}*/


	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			if (a[i][j]=='.'){
				int u[10];
				memset(u,0,sizeof(u));
				if (a[i][j+1]=='.'){
					for (int k=0; k<4; k++)
						if (a[i+dx[k]][j+dy[k]]!='.'&&a[i+dx[k]][j+dy[k]]!='#')
							u[a[i+dx[k]][j+dy[k]]-'0']=1;
					for (int k=0; k<4; k++)
						if (a[i+dx[k]][j+1+dy[k]]!='.'&&a[i+dx[k]][j+1+dy[k]]!='#')
							u[a[i+dx[k]][j+1+dy[k]]-'0']=1;

					int gd=0;
					for (int i=0; i<10; i++)
						if (!u[i]){
							gd=i;
							break;
						}
					v++;
					dm[v].push_back(make_pair(i,j));
					dm[v].push_back(make_pair(i,j+1));
					a[i][j]=gd+'0';
					used[i][j]=1;
					ind[i][j]=v;
					a[i][j+1]=gd+'0';
					used[i][j+1]=1;
					ind[i][j+1]=v;
					j++;
				} else
				{
					for (int k=0; k<4; k++)
						if (a[i+dx[k]][j+dy[k]]!='.'&&a[i+dx[k]][j+dy[k]]!='#')
							u[a[i+dx[k]][j+dy[k]]-'0']=1;
					int gd=0;
					for (int i=0; i<10; i++)
						if (!u[i]){
							gd=i;
							break;
						}
					v++;
					dm[v].push_back(make_pair(i,j));
					ind[i][j]=v;
					a[i][j]=gd+'0';
				}
			}
		}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i][j]!='.'&&a[i][j]!='#'&&dm[ind[i][j]].size()==1){
				int ok=0;
				for (int k=0; k<4; k++)
					if (a[i+dx[k]][j+dy[k]]!='#')
						ok=1;

				if (!ok){
					printf("-1\n");
					return 0;
				}

				int mn=100000;
				int num=-1;
				for (int k=0; k<4; k++)
					if (a[i+dx[k]][j+dy[k]]!='#'){
						int cur=ind[i+dx[k]][j+dy[k]];
						if (dm[cur].size()<mn){
							mn=dm[cur].size();
							num=cur;
						}
					}

				int u[10];
				memset(u,0,sizeof(u));
				for (int k=0; k<dm[num].size(); k++){
					for (int l=0; l<4; l++)
						if (a[dm[num][k].first+dx[l]][dm[num][k].second+dy[l]]!='#')
							u[a[dm[num][k].first+dx[l]][dm[num][k].second+dy[l]]-'0']=1;
				}
				for (int k=0; k<4; k++)
					if (a[i+dx[k]][j+dy[k]]!='#')
						u[a[i+dx[k]][j+dy[k]]-'0']=1;

				int col=0;
				for (int k=0; k<10; k++)
					if (!u[k]){
						col=k;
						break;
					}
				for (int k=0; k<dm[num].size(); k++)
					a[dm[num][k].first][dm[num][k].second]=col+'0';
				a[i][j]=col+'0';
				dm[num].push_back(make_pair(i,j));
				ind[i][j]=num;
			}

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++)
			printf("%c",a[i][j]);
		printf("\n");
	}

	return 0;
}