#include <cstdio>
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b) for (int i = (a), _n = (b); i <= _n; ++i)
#define FORD(i, a, b) for (int i = (a), _n = (b); i >= _n; --i)
#define FORE(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1000000000;

const int NMAX = 1000;

int N, M;
char T[NMAX][NMAX+1];

const int dR[] = { -1, 0, 1, 0 }, dC[] = { 0, -1, 0, 1 };

inline bool lonely(int r, int c, int pr, int pc) {
//printf("r=%d c=%d pr=%d pc=%d\n", r, c, pr, pc);
	if (T[r][c] != '.') return false;
	REP(i, 4) {
		int nr = r + dR[i], nc = c + dC[i];
		if ((nr != pr || nc != pc) && nr < N && nr >= 0 && nc < M && nc >= 0 && T[nr][nc] == '.')
			return false;
//printf("nr=%d nc=%d\n", nr, nc);
	}
	return true;
}

void process(const vector<PII>& T) {
	static bool used[10];
	fill_n(used, 10, false);
	int NN = T.size();
//printf("process: "); REP(i, NN) printf("(%d, %d) ", T[i].FI, T[i].SE); printf("\n");
	REP(i, NN) {
		int r = T[i].FI, c = T[i].SE;
		REP(dir, 4) {
			int nr = r + dR[dir], nc = c + dC[dir];
			bool ok = true;
			if (!(nr >= 0 && nr < N && nc >= 0 && nc < M)) ok = false;
			if (ok) REP(j, NN) if (T[j].FI == nr && T[j].SE == nc) ok = false;
			if (ok && ::T[nr][nc] >= '0' && ::T[nr][nc] <= '9') used[::T[nr][nc]-'0'] = true;
		}
	}
	int col = -1;
	REP(i, 10) if (!used[i]) col = i;
	REP(i, NN) ::T[T[i].FI][T[i].SE] = col+'0';
}

int main() {
	scanf("%d%d", &N, &M);
	REP(i, N) scanf("%s", T[i]);
	REP(r, N) REP(c, M) if (T[r][c] == '.') {
		static vector<PII> tab;
		tab.clear();
		tab.PB(MP(r, c));
		if (c+1 < M && T[r][c+1] == '.') {
			tab.PB(MP(r, c+1));
			if (c+2 < M && lonely(r, c+2, r, c+1)) tab.PB(MP(r, c+2));
			if (r+1 < N && lonely(r+1, c, r, c)) tab.PB(MP(r+1, c));
			if (r+1 < N && lonely(r+1, c+1, r, c+1)) tab.PB(MP(r+1, c+1));
			process(tab);
		} else if (r+1 < N && T[r+1][c] == '.') {
			tab.PB(MP(r+1, c));
			if (c+1 < M && lonely(r, c+1, r, c)) tab.PB(MP(r, c+1));
			if (c+1 < M && lonely(r+1, c+1, r+1, c)) tab.PB(MP(r+1, c+1));
			if (r+2 < N && lonely(r+2, c, r+1, c)) tab.PB(MP(r+2, c));
			if (c-1 >= 0 && lonely(r+1, c-1, r+1, c)) tab.PB(MP(r+1, c-1));
			process(tab);
		} else {
//REP(i, N) printf("%s\n", T[i]);
			printf("%d\n", -1);
			return 0;
		}
	}
	REP(i, N) printf("%s\n", T[i]);
}
