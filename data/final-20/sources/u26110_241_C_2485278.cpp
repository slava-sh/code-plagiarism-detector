#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007
#define PFF pair<flt,flt>

struct Bk {
	int y,l,r,bel;
	Bk(int _y,int _l,int _r,int _bel) : y(_y), l(_l), r(_r), bel(_bel) {}
	Bk() {}
}B[MaxN];

int n,hl,hr,pt[MaxN],app[120],fl[MaxN];
int main() {
	//freopen("temp.in","r",stdin); freopen("temp.out","w",stdout);
	cin >> hl >> hr >> n; int Tot = 0;
	For(i,1,n) {
			int p,l,r,y; char f;
		scanf("%d%*c%c%d%d",&p,&f,&l,&r); pt[i] = p;
		if (f == 'T') y = 100; else y = 0; fl[i] = y == 100;
		For(j,-n,n) {
			B[++Tot] = Bk(y + 200 * j,l,r,i);
		}
	}
	PFF sPt = MP(0,hl); int ans = 0;
	For(j,-2 * n,2 * n) {
			if(j==-3){
				int z = j;
			}
		PFF nPt = MP(100000,((abs(j) & 1) ? (100 - hr) : (hr)) + 100 * j);
		flt k;
		if (nPt.SE != hl) k = 100000. / (nPt.SE - sPt.SE);
			else continue ;
		Fill(app,0);
		int tAns = 0; PII Cnt = MP(0,0);
		For(i,1,Tot) {
			flt tConv = ((flt)B[i].y - hl) * k;
			if (tConv >= B[i].l && tConv <= B[i].r) {
				++app[B[i].bel]; 
				if (app[B[i].bel] > 1) {
					tAns = -INF; break ; 
				}
				tAns += pt[B[i].bel];
				if (fl[B[i].bel]) ++Cnt.FI; else ++Cnt.SE;
			}
		}
		if (tAns == 110) {
			int z = tAns;
		}
		if (Cnt.FI + Cnt.SE == abs(j)) ans = max(ans,tAns);
	}
	cout << ans << endl;
	return 0;
}

