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
#include <cassert>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl

int n, m;
char sol[40][40];
bool sfound=false;
char grid[40][40];
int sq[40][40];
int combo[28][2];
int cc=0;

bool good(int *p){
	int used[7][7]={{0}};
	for(int i=0; i<28; i++){
		int n1=p[combo[i][0]];
		int n2=p[combo[i][1]];
		if(used[n1][n2])
			return false;
		used[n1][n2]=used[n2][n1]=1;
	}
	if(!sfound){
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			int d=grid[i][j];
			if(d=='.'){
				continue;
			}
			int n=p[sq[i][j]];
			sol[i][j]='0'+n;
		}
			sfound=true;
	}
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf(" %s", grid[i]);
	memcpy(sol, grid, sizeof(grid));
	memset(sq, -1, sizeof(sq));
	int sqc=0;
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++){
		if(grid[i][j]!='.' && sq[i][j]==-1){
			sq[i][j]=sq[i][j+1]=sq[i+1][j]=sq[i+1][j+1]=
				sqc++;
		}
	}
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	for(int ii=0; ii<n; ii++)
	for(int jj=0; jj<m; jj++){
		if(grid[i][j]!=grid[ii][jj] || grid[i][j]=='.')
			continue;
		if((i+j)<=(ii+jj))
			continue;
		combo[cc][0]=sq[i][j];
		combo[cc][1]=sq[ii][jj];
		cc++;
	}
	debug(cc);
	assert(cc==28);
	
	int p1[14]={0,0,0,0,0,0,0,1,1,1,1,1,1,1};
	int count=0;
	do{
		{
		int z=0, o=0, bad=0;
		for(int i=0; i<14; i++){
			p1[i] ? o++ : z++;
			if(o>z)
				bad=1;
		}
		if(bad)
			continue;
		}
		int p2[7]={0,1,2,3,4,5,6};
		do{
			int p[14];
			int z=0, o=0, bad=0;
			for(int i=0; i<14; i++){
				if(!p1[i]){
					p[i]=z++;
				}else{
					p[i]=p2[o++];
					if(p[i]>=z)
						bad=1;
				}
			}
			if(!bad && good(p))
				count+=5040;
		}while(next_permutation(p2, p2+7));
	}while(next_permutation(p1+1, p1+14));
	printf("%d\n", count);
	for(int i=0; i<n; i++)
		puts(sol[i]);
	return 0;
}

