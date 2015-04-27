#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define L first
#define R second
#define MP make_pair
#define PB push_back

const int maxn = 2000 + 100;
int n, m, mark[maxn][maxn], Up[maxn][maxn], tmpX, tmpY, ans = 1000000000;
char c[maxn][maxn];

void solve(int N, int M){
	if(N < 1 or M < 1)
		return ;
	memset(mark, 0, sizeof mark);
	memset(Up, 0, sizeof Up);
	int x = tmpX, y = tmpY;
	x += N - 1;
	while(true){
		mark[x][y] = M;
		Up[x][y] = N;
		if(c[x+1][y] == 'X')
			x++;
		else if(c[x][y+M] == 'X')
			y++;
		else
			break;
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(Up[i][j] > 0)
				mark[i][j] = M;
			Up[i-1][j] = max(Up[i-1][j], Up[i][j] - 1);
			mark[i][j+1] = max(mark[i][j+1], mark[i][j] - 1);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((mark[i][j] > 0 and c[i][j] == '.') or (mark[i][j] == 0 and c[i][j] == 'X'))
				return ;
	for(int i=1;i<=m;i++)
		if(mark[n+1][i] > 0)
			return ;
	for(int i=1;i<=n;i++)
		if(mark[i][m+1] > 0)
			return ;
	ans = min(ans, N * M);
}

int main(){
	ios_base::sync_with_stdio(false);
	int x = 0, y = 0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin >> c[i][j];
			if(c[i][j] == 'X' and x == 0)
				x = i, y = j;
		}
	tmpX = x, tmpY = y;
	while(c[x][y] == 'X')
		x++;
	x --;
	if(x == n)
		solve(n - tmpX + 1, 1);
	else{
		while(c[x+1][y] == '.')
			y ++;
		if(y == m+1)
			solve(x - tmpX + 1, 1);
		else{
			int xX = tmpX, yY = tmpY;
			while(c[xX][yY] == 'X')
				yY ++;
			yY --;
			solve(x - tmpX + 1, yY - y + 1);
		}
	}
	x = tmpX, y = tmpY;
	while(c[x][y] == 'X')
		y++;
	y --;
	if(y == m)
		solve(1, m - tmpY + 1);
	else{
		while(c[x][y+1] == '.')
			x ++;
		if(x == n+1)
			solve(1, y - tmpY + 1);
		else{
			int xX = tmpX, yY = tmpY;
			while(c[xX][yY] == 'X')
				xX ++;
			xX --;
			solve(xX - x + 1, y - tmpY + 1);
		}
	}
	if(ans == 1000000000)
		cout << -1 << endl;
	else
		cout << ans << endl;
}
