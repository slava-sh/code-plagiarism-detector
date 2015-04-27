#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

char grid[1001][1001];
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i=0; i<m; i++){
		scanf(" %s", grid[i]);
		int c=0;
		for(int j=0; j<n-1; j++){
			if(grid[i][j]=='.' && grid[i][j+1]=='.'){
				grid[i][j]=grid[i][j+1]=c+'0'+3*(i%3);
				c=(c+1)%3;
			}else if(grid[i][j]=='.' && i>0 && grid[i-1][j]=='.'){
				grid[i][j]=grid[i-1][j]=c+'0'+3*(i%3);
				c=(c+1)%3;
			}
		}
		if(i>0 && grid[i][n-1]=='.' && grid[i-1][n-1]=='.')
			grid[i][n-1]=grid[i-1][n-1]=c+'0'+3*(i%3);
	}
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++){
		if(grid[i][j]=='.'){
			for(int d=0; d<4; d++){
				int ii=i+dx[d];
				int jj=j+dy[d];
				if(0<=ii && ii<m && 0<=jj && jj<n){
					if(grid[ii][jj]!='#'){
						grid[i][j]=grid[ii][jj];
					}
				}
			}
			if(grid[i][j]=='.'){
				puts("-1");
				return 0;
			}
		}
	}
	for(int i=0; i<m; i++)
		puts(grid[i]);
	return 0;
}
