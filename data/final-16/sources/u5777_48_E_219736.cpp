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

int R;
pii dp[300][300];
int CH;
int chH[500];
int chH2[500];
int chT[500];
int chT2[500];
int best[300][300];
pii rek(int h, int t){
	if(h==0&&t==0)return pii(1,0);
	if(h+t>R)return pii(-1,0);
	if(dp[h][t].first==-2)return pii(0,0);
	if(dp[h][t].first!=-3)return dp[h][t];
	dp[h][t].first=-2;
	int bRes = -1;
	int bStep = 0;
	int nh,nt;
	FOR(i,0,CH){
		nh = h-chH2[i];
		nt = t-chT2[i];
		if(nh<0||nt<0)continue;
		pii res = rek(nh+chH[i],nt+chT[i]);
		if(res.first>bRes){
			bRes = res.first;
			bStep = res.second;
		} else if(res.first==bRes){
			if(bRes==-1)bStep=max(bStep,res.second);
			else if(bRes==1)bStep = min(bStep,res.second);
		}
	}
	bStep++;
	dp[h][t]=pii(bRes,bStep);
	return dp[h][t];
}
int main(){
	int H,T;
	scanf("%d%d%d",&H,&T,&R);
	memset(dp,-1,sizeof(dp));
	CH = 0;
	int n;
	scanf("%d",&n);
	memset(chH2,0,sizeof(chH2));
	FOR(i,0,n){
		scanf("%d%d",chH+i,chT+i);
		chH2[CH++]=1+i;
	}
	scanf("%d",&n);
	memset(chT2,0,sizeof(chT2));
	FOR(i,0,n){
		scanf("%d%d",chH+CH,chT+CH);
		chT2[CH++]=1+i;
	}
	FOR(i,0,300)FOR(j,0,300)dp[i][j].first = -3;
	pii res = rek(H,T);
	if(res.first==0)printf("Draw\n");
	else if(res.first==-1)printf("Zmey\n%d\n",res.second);
	else{
		queue<pii > ac;
		memset(best,oo,sizeof(best));
		best[0][0]=0;
		ac.push(pii(0,0));
		pii nn;
		int t1,t2;
		while(!ac.empty()){
			nn = ac.front();
			ac.pop();
			FOR(i,0,CH){
				t1 = nn.first-chH[i];
				t2 = nn.second-chT[i];
				if(t1 < 0||t2 < 0)continue;
				t1+=chH2[i];
				t2+=chT2[i];
				if(t1+t2>R)continue;
				if(best[t1][t2]==oo){
					best[t1][t2]=best[nn.first][nn.second]+1;
					ac.push(pii(t1,t2));
					if(t1==H&&t2==T){
						ac = queue<pii >();
						break;
					}
				}
			}
		}
		printf("Ivan\n%d\n",best[H][T]);
	}
	return 0;
}
