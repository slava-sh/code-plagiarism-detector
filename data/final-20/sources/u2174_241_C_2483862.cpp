#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define EPS 1e-8
using namespace std;

struct mir{
	int xl, xr, pt;
	mir(){}
	mir(int xl, int xr, int pt): xl(xl), xr(xr), pt(pt){}
	bool operator < (mir const &T) const{return xl < T.xl;}
};


int h1, h2, n, pt, xl, xr;
char s[5];
int a, b;
mir A[105], B[105];
int u[105], v[105], ret;

int shoot(double dx, double dy){
	int sum = 0, ok;
	double sx = 0, sy = h1;

	CLR(u, 0);
	CLR(v, 0);
	while (1){
		if (dy < 0){
			// goes down
			sx += (sy / -dy) * dx;
			sy = 0.;
			if (sx >= 100000 - EPS) break;
			ok = 0;
			FOR(i,0,b)
			if (B[i].xl <= sx + EPS&& sx <= B[i].xr + EPS){
				if (v[i]) return 0;
				sum += B[i].pt;
				v[i] = 1;
				ok = 1;
			}
			if (!ok) return 0;
		}
		else{
			// goes up
			sx += (100.0 - sy) * dx / dy;
			sy = 100;
			if (sx >= 100000 - EPS) break;
			ok = 0;
			FOR(i,0,a)
			if (A[i].xl <= sx + EPS && sx <= A[i].xr + EPS){
				if (u[i]) return 0;
				sum += A[i].pt;
				u[i] = 1;
				ok = 1;
			}
			if (!ok) return 0;
		}
		dy = -dy;
	}

	return sum;
}

int main(){
	scanf("%d%d%d", &h1, &h2, &n);
	FOR(i,0,n){
		scanf("%d%s%d%d", &pt, s, &xl, &xr);
		if (s[0] == 'T')  A[a++] = mir(xl, xr, pt);
		else B[b++] = mir(xl, xr, pt);
	}
	sort(A, A + a);
	sort(B, B + b);

	FOE(i,-n,n){
		if (i & 1) ret = max(ret, shoot(100000, (100. - h2) + i * 100 - h1));
		else ret = max(ret, shoot(100000, h2 + i * 100 - h1));
	}

	printf("%d\n", ret);
	return 0;
}
