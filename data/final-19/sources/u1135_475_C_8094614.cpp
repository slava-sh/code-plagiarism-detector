#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cfloat>
#include <ctime>
#include<cassert>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

const int INF=1e9;

int solve(vector<string>s){
	int n=sz(s),m=sz(s[0]);
	bool OK=0;
	int x=-1,y=-1;
	REP(j,m){
		REP(i,n){
			if(s[i][j]=='X'){
				x=i,y=j;
				OK=1;
				break;
			}
		}
		if(OK)break;
	}
	int W=0,H=0;
	for(int j=y;j<m;j++){
		if(s[x][j]=='X'){
			W++;
		} else break;
	}
	int k=y+W;
	if(k==m){
		H=1;
	}else{
		int steps=-1;
		for(int i=x;i<n;i++){
			if(s[i][k]=='X'){
				steps=i-x;
				break;
			}
		}
		if(steps==-1){
			H=1;
		}else{
			int cnt=0;
			for(int i=x;i<n;i++){
				if(s[i][y]=='X'){
					cnt++;
				}else{
					break;
				}
			}
			cnt-=steps;
			if(cnt<=0)return INF;
			H=cnt;
		}
	}
	vector<string>e=s;
	REP(i,n)REP(j,m)e[i][j]='.';
	for(int i=x;i<x+H;i++){
		for(int j=y;j<y+W;j++){
			e[i][j]='X';
		}
	}
	for(;;){
		if(x+H<n&&s[x+H][y]=='X'){
			for(int j=y;j<y+W;j++){
				if(s[x+H][j]=='.'){
					return INF;
				}
			}
			for(int j=y;j<y+W;j++){
				e[x+H][j]='X';
			}
			x++;
		}else if(y+W<m&&s[x][y+W]=='X'){
			for(int i=x;i<x+H;i++){
				if(s[i][y+W]=='.'){
					return INF;
				}
			}
			for(int i=x;i<x+H;i++){
				e[i][y+W]='X';
			}
			y++;
		}else{
			break;
		}
	}
	if(s==e)return W*H;
	else return INF;
}

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<string>s(n),t(m,string(n,' '));
	REP(i,n)cin>>s[i];
	REP(i,n)REP(j,m)t[j][i]=s[i][j];
	int res=min(solve(s),solve(t));
	if(res==INF)res=-1;
	cout<<res<<endl;
	return 0;
}