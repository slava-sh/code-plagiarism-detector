#pragma comment(linker, "/STACK:10000000000000")


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>

#define problem "tictactoe"
#define sort stable_sort
#define ll long long
#define INFll 1e18 + 7
#define mp make_pair
#define pb push_back
using namespace std;



int n, m, a[222][222], b[3][222][222][8];
vector <vector <int> > used;
int g[8][2];
string s;


void go(int x, int y, int j){
	used[x][y] = 1;
	if (x == 0 || y == 0 || x > n + 3 || y > m + 3) return;
	for (int i = 1; i <= 2; i++){
			int xx, yy;
			xx = x + g[j][0]; yy = y + g[j][1];
			if (!used[xx][yy]) go(xx, yy, j);
			if (a[xx][yy] == i) b[i][x][y][j] = 1 + b[i][xx][yy][j];
	}
}


int main()
{
	ifstream cin(problem".in");
	ofstream cout(problem".out");
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			if (s[j] == '0')
				a[i + 2][j + 2] = 1;
			else
			{
				if (s[j] == 'X')
					a[i + 2][j + 2] = 2;
			}
	}
	
	g[0][0] = 1; g[0][1] = 1;
	g[1][0] = 1; g[1][1] = 0;
	g[2][0] = 1; g[2][1] = -1;
	g[3][0] = 0; g[3][1] = 1;
	g[4][0] = 0; g[4][1] = -1;
	g[5][0] = -1; g[5][1] = 1;
	g[6][0] = -1; g[6][1] = 0;
	g[7][0] = -1; g[7][1] = -1;

	for (int k = 0; k < 8; k++){
		used.assign(222, vector <int>(222, 0));
		for (int i = 1; i < n + 3; i++){
			for (int j = 1; j < m + 3; j++){
				if (!used[i][j]) go(i, j, k);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i < n + 3; i++){
		for (int j = 1; j < m + 3; j++){
			if (a[i][j] == 0){
				bool flag = true;
				for (int k = 0; k < 4; k++){
					if (b[1][i][j][k] + b[1][i][j][7 - k] > 3){
						cout << 0;
						return 0;
					}
					if (b[2][i][j][k] + b[2][i][j][7 - k] > 3){
						ans++;
						flag = false;
						break;
					}
				}
				if (flag)
					for (int k = 0; k < 8; k++){
						if (b[2][i][j][k] == 3 && !a[i + g[7 - k][0]][j + g[7 - k][1]]){
							ans++;
							break;
						}
					}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}