#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%I64d", &(a))
#define RLL(a, b) scanf("%I64d%I64d", &(a), &(b))
#define RLLL(a, b, c) scanf("%I64d%I64d%I64d", &(a), &(b), &(c)) 
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%I64d\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//Segment tree
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#define M (N - 1000)
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111

using namespace std;

int n, m;
int good[N], fi[N], vis[N], ms[N], now[N], x[N], ans[N];
char s[N][3];

set<int> in, out, alin, alout, alive;
queue<int> tem;

int main(){
	int t, y, z, ca = 1;
	//freopen("D:/Contest/in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	RII(n, m);
	REP(i, m) {
		scanf("%s %d", s[i], x + i);
		if (s[i][0] == '+') {
			if (vis[x[i]] == 0) fi[x[i]] = 1;
		}
		else {
			if (vis[x[i]] == 0) fi[x[i]] = -1;
		}
		vis[x[i]] = 1;
	}
	int tot = 0;
	REPP(i, 1, n) if (vis[i]) alive.insert(i); else ans[tot++] = i;
	REPP(i, 1, n) {
		if (fi[i] == -1) {
			now[i] = 1, in.insert(i);
			if (vis[i]) alin.insert(i);
		}
		else {
			now[i] = 0, out.insert(i);
			if (vis[i]) alout.insert(i);
		}
	}
	REP(i, m) {
		y = x[i];
		if (in.size()) {
			for (auto itr = alout.begin(); itr != alout.end(); ++itr) {
				if (now[*itr] == 0) tem.push(*itr);
			}
			while (!tem.empty()) alin.erase(tem.front()), alout.erase(tem.front()), alive.erase(tem.front()), tem.pop();
		}
		if (in.count(y)) {
			now[y]--;
			in.erase(y);
			out.insert(y);
			if (alive.count(y)) alin.erase(y), alout.insert(y);
		}
		else {
			now[y]++;
			in.insert(y);
			out.erase(y);
			if (alive.count(y)) alin.insert(y), alout.insert(y);
		}
	}
	//cout << in.size() << endl;
	if (in.size()) {
		for (auto itr = alout.begin(); itr != alout.end(); ++itr) {
			if (now[*itr] == 0) tem.push(*itr);
		}
		while (!tem.empty()) alin.erase(tem.front()), alout.erase(tem.front()), alive.erase(tem.front()), tem.pop();
	}
	for (auto itr = alive.begin(); itr != alive.end(); ++itr) ans[tot++] = *itr;
	PI(tot);
	sort(ans, ans + tot);
	REP(i, tot) PI(ans[i]);


	return 0;
}
