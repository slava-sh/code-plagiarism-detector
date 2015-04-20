#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

const int MAXN = 550, MAXQ = 8 * MAXN * MAXN, INF = 1000000000;

int startx, starty, queuex[MAXQ + 100], queuey[MAXQ + 100], d1[MAXN][MAXN], d2[MAXN][MAXN], fromx[MAXN][MAXN], fromy[MAXN][MAXN];
int n, m, dx[4], dy[4], k;
char a[MAXN][MAXN];

char check(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
	dx[0] = 0;
	dy[0] = 1;
	dx[1] = 1;
	dy[1] = 0;
	dx[2] = 0;
	dy[2] = -1;
	dx[3] = -1;
	dy[3] = 0;
	cin >> m >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (a[i][j] == 'V'){
				startx = i;
				starty = j;
				a[i][j] = 'A';
			}
		}

	//---------------------------BFS1-------------------------------
	int uk1 = 0, uk2 = 0;
	queuex[uk2] = startx;
	queuey[uk2++] = starty;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d1[i][j] = INF;
	d1[startx][starty] = 0;
	while (uk1 != uk2){
		int ux = queuex[uk1], uy = queuey[uk1++];
		
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i], vy = uy + dy[i];
			if (!check(vx, vy)) continue;
			if (d1[vx][vy] == INF || d1[ux][uy] + 1 < d1[vx][vy]){
				queuex[uk2] = vx;
				queuey[uk2++] = vy;
				d1[vx][vy] = d1[ux][uy] + 1;
			}
		}
	}

	int res1 = INF, res1i, res1j;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 'T' && d1[i][j] != INF && d1[i][j] < res1)
				res1 = d1[i][j], res1i = i, res1j = j;
	//---------------------------BFS2-------------------------------
	uk1 = MAXQ / 2, uk2 = MAXQ / 2;
	queuex[uk2] = startx;
	queuey[uk2++] = starty;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d2[i][j] = INF;
	d2[startx][starty] = 0;
	while (uk1 != uk2){
		int ux = queuex[uk1], uy = queuey[uk1++];
		
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i], vy = uy + dy[i];
			if (!check(vx, vy)) continue;
			int c = a[vx][vy] == 'A';
			if (d2[vx][vy] == INF || d2[ux][uy] + c < d2[vx][vy]){
				if (c){
					queuex[uk2] = vx;
					queuey[uk2++] = vy;
				} else{
					queuex[--uk1] = vx;
					queuey[uk1] = vy;
				}
				d2[vx][vy] = d2[ux][uy] + c;
				fromx[vx][vy] = ux;
				fromy[vx][vy] = uy;
			}
		}
	}

	int res2 = INF, res2i, res2j;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 'T' && d2[i][j] != INF && d2[i][j] < res2)
				for (int k = 0; k < 4; k++){
					int nx = i + dx[k], ny = j + dy[k];
					if (!check(nx, ny)) continue;
					if (a[nx][ny] == 'T'){
						res2 = d2[i][j];
						res2i = i;
						res2j = j;
					}
				}

	assert(res1 != INF);
	int ans1 = (k - 1) * 2 + res1;

	string ans = "";

	if (res2 != INF){
		int ux = res2i, uy = res2j, temp = 0;
		while (ux != startx || uy != starty){
			temp += (a[ux][uy] == 'T');
			int vx = fromx[ux][uy], vy = fromy[ux][uy], dx = vx - ux, dy = vy - uy;
			int c = a[ux][uy] == 'A';
			if (dx == 1) ans += 'N';
			if (dx == -1) ans += 'S';
			if (dy == 1) ans += 'W';
			if (dy == -1) ans += 'E';
			ux = vx;
			uy = vy;
		}

		reverse(ans.begin(), ans.end());

		char t1, t2;
		
		for (int i = 0; i < 4; i++){
			int vx = res2i + dx[i], vy = res2j + dy[i];
			if (!check(vx, vy)) continue;
			if (a[vx][vy] == 'T'){
				if (dx[i] == 1) t1 = 'S';
				if (dx[i] == -1) t1 = 'N';
				if (dy[i] == 1) t1 = 'E';
				if (dy[i] == -1) t1 = 'W';
				break;
			}
		}

		if (t1 == 'N') t2 = 'S';
		if (t1 == 'E') t2 = 'W';
		if (t1 == 'S') t2 = 'N';
		if (t1 == 'W') t2 = 'E';

		for (int i = 0; i < k - temp; i++){
			if (i % 2)
				ans += t2;
			else
				ans += t1;
		}
	}

	if (res2 == INF || ans1 < ans.length()){
		ans = "";
		int ux = res1i, uy = res1j;
		while (ux != startx || uy != starty){
			for (int i = 0; i < 4; i++){
				int vx = ux + dx[i], vy = uy + dy[i];
				if (!check(vx, vy)) continue;
				if (d1[vx][vy] == d1[ux][uy] - 1){
					if (dx[i] == 1) ans += 'N';
					if (dx[i] == -1) ans += 'S';
					if (dy[i] == 1) ans += 'W';
					if (dy[i] == -1) ans += 'E';
					ux = vx;
					uy = vy;
					break;
				}
			}
		}

		reverse(ans.begin(), ans.end());
		
		char t1 = ans.back(), t2;
		if (t1 == 'N') t2 = 'S';
		if (t1 == 'E') t2 = 'W';
		if (t1 == 'S') t2 = 'N';
		if (t1 == 'W') t2 = 'E';
		for (int i = 1; i < k; i++){
			ans += t2;
			ans += t1;
		}
	}
	cout << ans;
	return 0;
}