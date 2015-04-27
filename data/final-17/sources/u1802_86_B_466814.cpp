#include <stdio.h>
#include <string.h>
int n,m;

char dat[1003][1003];
int grp[1003][1003];
int cnt[1000003];
int color[1000003];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

int v[11];

int vcnt,visit[1003][1003];
void checkcolor(int i, int j){
	visit[i][j] = vcnt;
	for(int k = 0;k < 4; k ++){
		int r = i + dir[k][0];
		int c = j + dir[k][1];
		if(r < 0 || c < 0 || r >= n || c >= m) continue;
		if(grp[r][c] >= 0){
			v[color[grp[r][c]]] = 1;
		}
		if(grp[r][c] == grp[i][j] && visit[r][c] != vcnt) {
			checkcolor(r,c);
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m) == 2){
		for(int i = 0;i < n;i ++){
			scanf("%s",dat[i]);
		}
		int grpcnt = 0;
		for(int i = 0;i < n;i ++) {
			for(int j = 0;j < m; j++) {
				if(dat[i][j] == '#') {
					grp[i][j] = -1;
				}
				if(dat[i][j] == '.'){
					cnt[grpcnt] = 1;
					color[grpcnt] = 10;
					grp[i][j] = grpcnt ++;
				}
			}
		}
		for(int i = 0;i < n;i ++) {
			for(int j = 0;j < m; j++) {
				if(grp[i][j] == -1) continue;
				if(cnt[grp[i][j]] == 1){
					int grpsmin = 6;
					int vmin = -1;
					for(int k = 0;k < 4;k ++){
						int r = i + dir[k][0];
						int c = j + dir[k][1];
						if(r < 0 || r >= n || c < 0 || c >= m) continue;
						if(grp[r][c] != -1) {
							if(cnt[grp[r][c]] < grpsmin) {
								grpsmin = cnt[grp[r][c]];
								vmin = grp[r][c];
							}
						}
					}
					if(vmin == -1) {
						goto final;
					}
					grp[i][j] = vmin;
					cnt[grp[i][j]] ++;
				}
			}
		}
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < m;j ++){
				if(grp[i][j] == -1) continue;
				memset(v,0,sizeof(v));
				++vcnt;
				checkcolor(i,j);
				for(int k = 0; k < 10 ;k++){
					if(v[k] == 0){
						color[grp[i][j]] = k;
						break;
					}
				}
			}
		}
		for(int i = 0;i < n;i ++) {
			for(int j = 0; j < m; j++){
				if(dat[i][j] == '.') {
					dat[i][j] = '0' + color[grp[i][j]];
				}
			}
			printf("%s\n",dat[i]);
		}
		continue;
final:
		printf("-1\n");
	}
	return 0;
}
