#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>


 
using namespace std;
 
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

char buf[1100][1100];
int cr[1100000];
int cc[1100000];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int fid[1100][1100];
		bool pos[11];
bool vis1[1100][1100];
bool vis2[1100][1100];
int main(){
	memset(fid,-1,sizeof(fid));
	memset(vis1,false,sizeof(vis1));
	memset(vis2,false,sizeof(vis2));
	int R,C,N=0;
	scanf("%d%d",&R,&C);
	FOR(i,0,R)scanf("%s",buf[i]);
	FOR(r,0,R)FOR(c,0,C)if(buf[r][c]=='.'&&fid[r][c]==-1){
		if(r+1<R&&buf[r+1][c]!='#'){
			if(fid[r+1][c]==-1){
				cr[N]=r;
				cc[N]=c;
				fid[r][c]=N++;
				fid[r+1][c]=fid[r][c];
			} else {
				fid[r][c]=fid[r+1][c];
			}
			continue;
		}
		if(c+1<C&&buf[r][c+1]!='#'){
			if(fid[r][c+1]==-1){
				cr[N]=r;
				cc[N]=c;
				fid[r][c]=N++;
				fid[r][c+1]=fid[r][c];
			} else {
				fid[r][c]=fid[r][c+1];
			}
			continue;
		}
		
		if(r>0&&buf[r-1][c]!='#'){
			fid[r][c]=fid[r-1][c];
			continue;
		}
		
		if(c>0&&buf[r][c-1]!='#'){
			fid[r][c]=fid[r][c-1];
			continue;
		}
		printf("-1\n");
		return 0;
	}
	FOR(i,0,N){
		memset(pos,0,sizeof(pos));
		queue<pii > q = queue<pii >();
		queue<pii > q2 = queue<pii >();
		q.push(pii(cr[i],cc[i]));
		vis1[cr[i]][cc[i]]=true;
		while(!q.empty()){
			pii nn = q.front();
			q2.push(nn);
			q.pop();
			int r = nn.first, c = nn.second;
			FOR(d,0,4){
				int rr = r+dr[d],cc = c+dc[d];
				if(rr<0||cc<0||rr==R||cc==C)continue;
				if(fid[rr][cc]==i){
					if(!vis1[rr][cc]){
						vis1[rr][cc]=true;
						q.push(pii(rr,cc));
					}
				} else {
					if(buf[rr][cc]>='0'&&buf[rr][cc]<='9'){
						pos[buf[rr][cc]-'0']=true;
					}
				}
			}
		}
		int uc = 0;
		while(pos[uc])++uc;
		char sc = '0'+uc;
		while(!q2.empty()){
			buf[q2.front().first][q2.front().second]=sc;
			q2.pop();
		}
	}
	FOR(i,0,R)printf("%s\n",buf[i]);
	return 0;
}
