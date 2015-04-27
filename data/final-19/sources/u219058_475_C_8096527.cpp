#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
/*

4 4
XX..
XX..
XXXX
XXXX
*/

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int n, m;
string s[1007];
int minI, minJ;
const int INF = 1e9;
int cnt = 0, tot = 0;
int di, dj, curi, curj;

void goJ() {
	while (curj + dj < m) {
		bool flag = true;
		REP(i, di) if (s[curi + i][curj + dj] != 'X') {
			flag = false;
			break;
		}
		if (!flag) break;
		cnt -= di;
		++dj;
	}
}

void goI() {
	while (curi + di < n) {
		bool flag = true;
		REP(j, dj) if (s[curi + di][curj + j] != 'X') {
			flag = false;
			break;
		}
		if (!flag) break;
		cnt -= dj;
		++di;
	}
}


bool shiftJ() {
	if (curj + dj == m) return false;
	REP(i, di) if (s[curi + i][curj + dj] != 'X') return false;
	cnt -= di;
	++curj;
	return true;
}

bool shiftI() {
	if (curi + di == n) return false;
	REP(j, dj) if (s[curi + di][curj + j] != 'X') return false;
	cnt -= dj;
	++curi;
	return true;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin >> n >> m;
		REP(i, n) cin >> s[i];
		minI = minJ = INF;
		REP(i, n) REP(j, m) if (s[i][j] == 'X') {
			minI = min(i, minI);
			minJ = min(j, minJ);
			++cnt;
		}
		tot = cnt;
		if (s[minI][minJ] != 'X') {
			cout << -1 << endl;
			return 0;
		}
		di = 0;
		while (minI + di < n && s[minI + di][minJ] == 'X') ++di;
		dj = 1, curj = minJ, curi = minI;
		cnt -= di;
		while ((curi + di == n || s[curi + di][curj] == '.') && shiftJ()) ;
		
		goJ();
		while (true) {
			if (shiftI()) continue;
			if (shiftJ()) continue;
			break;
		}
		int ans = INF;
		if (cnt == 0) ans = di * dj;
		cnt = tot;
		dj = 0;
		while (minJ + dj < m && s[minI][minJ + dj] == 'X') {
			++dj;
		}
		di = 1, curi = minI, curj = minJ;
		cnt -= dj;
		while ((curj + dj == m || s[curi][curj + dj] == '.') && shiftI()) ;
		goI();
		while (true) {
			if (shiftI()) continue;
			if (shiftJ()) continue;
			break;
		} 
		if (cnt == 0) ans = min(ans, di * dj);
		if (ans == INF) {
			cout << -1 << endl;
			return 0;
		}
		cout << ans << endl;
		return 0;
}
