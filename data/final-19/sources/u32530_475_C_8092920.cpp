#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair

template<class P, class Q> inline bool mmin(P &a, Q b) { if (a > b){ a = b; return true;} return false;}
template<class P, class Q> inline bool mmax(P &a, Q b) { if (a < b){ a = b; return true;} return false;}

typedef long long LL;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAXn = 1000 + 2, INF = 1e9;
int n, m;
char ar[MAXn][MAXn], tmp[MAXn][MAXn];
char c = 'X';

int go(int x, int y, int lx, int ly)
{
//	cerr << "HEY " << x << ' ' << y << ' ' << lx << ' ' << ly << endl;
	rep(i, n) rep(j, m) tmp[i][j]='.';
	rep(i, lx) rep(j, ly)
		tmp[x+i][y+j] = c;
	while(true) {
		if(x+lx<n && ar[x+lx][y]==c) {
			rep(i, ly)
				tmp[x+lx][y+i] = c;
			++x;
		}
		else if(y+ly<m && ar[x][y+ly]==c) {
			rep(i, lx)
				tmp[x+i][y+ly] = c;
			++y;
		}
		else
			break;
	}

/*	cerr << "GEDFS " << endl;
	rep(i, n) {
		rep(j, m)
			cerr << ar[i][j] << ' ';
		cerr << endl;
	}
	cerr << "DFSG " << endl;
	rep(i, n) {
		rep(j, m)
			cerr << tmp[i][j] << ' ';
		cerr << endl;
	}*/

	rep(i, n) rep(j, m)
		if(ar[i][j]!=tmp[i][j])
			return INF;
	return lx*ly;
}

int solve()
{
	rep(i, n) rep(j, m) if(ar[i][j]==c) {

		int p = 1;
		int l=j;
		while(l<m && ar[i][l]==c)
			++l;		
		for(int x=i+1; x<n; ++x) if(l<m && ar[x][l]==c) {
//			cerr << "HI " << x << endl;
			while(x+p<n && ar[x+p][j]==c)
				++p;
			break;
		}
		int ret = go(i, j, p, l-j);

		l=i;
		while(l<n && ar[l][j]==c)
			++l;
		p = 1;
		for(int y=j+1; y<m; ++y) if(l<n && ar[l][y]==c) {
			while(y+p<m && ar[i][y+p]==c)
				++p;
			break;
		}

		return min(ret, go(i, j, l-i, p));
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	rep(i, n) rep(j, m)
		cin >> ar[i][j];

	int ans = solve();

	cout << (ans==INF ? -1 : ans) << endl;
}

