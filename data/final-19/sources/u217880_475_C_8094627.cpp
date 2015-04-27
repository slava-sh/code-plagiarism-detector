#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii > vii;
typedef queue<int> qi;
typedef set<int> si;

#define RE(i,b) for(int i=0; i<(int)(b); i++)
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define BREP(i,a,b) for(int i=(a)-1; i>=(b); i--)
#define FE(i,X) for(typeof((X).begin()) i=(X).begin(); i!=(X).end(); ++i)

#define INF 1000000000
#define MP make_pair
#define FI first
#define SE second

bool A[4100][4100];
int SM,SN,H,W,P=0;

bool te(int h, int w){
	int x=SM,y=SN;
	bool ok=true;
	int P2=h*w;
	RE(i,h)
	RE(j,w)
		ok&=A[x+i][y+j];
	while(1){
		if(A[x+h][y]){
			RE(j,w)
				ok&=A[x+h][y+j];
			P2+=w;
			x++;
		}else if(A[x][y+w]){
			RE(i,h)
				ok&=A[x+i][y+w];
			P2+=h;
			y++;
		}else
			break;
	}
	return ok&&P2==P;
}

int main(){
	int M,N;scanf("%d %d ",&M,&N);
	int Erg=INF;
	RE(m,M)RE(n,N){
		char c;scanf("%c ",&c);
		A[m][n]=c=='X';
		P+=A[m][n];
	}
	for(SM=0;SM<M;SM++){
		for(SN=0;SN<N;SN++)
			if(A[SM][SN])
				break;
		if(A[SM][SN])
			break;
	}
	for(H=0;H<M;H++)
		if(!A[SM+H][SN])
			break;
	for(W=0;W<N;W++)
		if(!A[SM][SN+W])
			break;
// 		printf("%d %d %d %d\n",SM,SN,H,W);
	int H2=1,i;
	for(i=0;i<H+2;i++)
		if(A[SM+i][SN+W])
			break;
	if(i<H+1)
		H2=H-i;
// 	printf("%d H2\n",H2);
	if(te(H2,W))
		Erg=min(Erg,H2*W);
	
	int W2=1,j;
	for(j=0;j<W+2;j++)
		if(A[SM+H][SN+j])
			break;
	if(j<W+1)
		W2=W-j;
// 	printf("%d W2\n",W2);
	if(te(H,W2))
		Erg=min(Erg,H*W2);
	
	if(te(H,W))
		Erg=min(Erg,H*W);
	
	printf("%d\n",Erg==INF?-1:Erg);
	return 0;
}