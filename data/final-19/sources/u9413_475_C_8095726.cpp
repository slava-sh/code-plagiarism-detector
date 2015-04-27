#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 1005;
const int INF = 1e9;
string s[MAXn];
int n, m;

bool go(int r, int c, int x, int y) {
	//cerr << r << " " << c << " " << x << " " << y << endl;
	for(int i = r; i < r+x; i++)
		for(int j = c; j < c+y; j++) {
			if(s[i][j] != 'X') {
				return false;
			}
		}
	for(int i = r; i < r+x; i++)
		for(int j = c; j < c+y; j++)
			s[i][j] = 'Y';
	while(true) {
		if(c + y < m) {
			bool bad = false;
			for(int i = 0; i < x; i++)
				if(s[r+i][c+y] == '.')  
					bad = true;
			if(!bad) {
				for(int i = 0; i < x; i++)
					s[r+i][c+y] = 'Y';
				c += 1;
				continue;
			}
		}
		if(r + x < n) {
			bool bad = false;
			for(int i = 0; i < y; i++)
				if(s[r+x][c+i] == '.')  
					bad = true;
			if(!bad) {
				for(int i = 0; i < y; i++)
					s[r+x][c+i] = 'Y';
				r += 1;
				continue;
			}
		}
		break;
	}
	bool ans = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'X') {
				ans = false;
				goto outer;
			}
outer:
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'Y')
				s[i][j] = 'X';
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int x = n, y = m;
	int r = -1, c = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'X') {
				x = min(x, n-i);
				y = min(y, m-j);
				for(int h = n-1; h >= i; h--)
					if(s[h][j] != 'X')
						x = min(x, h-i);
				for(int h = m-1; h >= j; h--)
					if(s[i][h] != 'X')
						y = min(y, h-j);
				r = i;
				c = j;
				goto exit;
			}
exit:
	int best = INF;
	if(go(r, c, x, 1))
		best = min(best, x);
	if(go(r, c, 1, y))
		best = min(best, y);
	//for(int i = 0; i < n; i++)
	//	cerr << s[i] << endl;
	if(c + y < m && s[r+x-1][c+y] == 'X') {
		int f = r+x-1;
		for(; f >= 0; f--)
			if(s[f][c+y] == '.')
				break;
		int nx = r+x-1-f;
		if(go(r, c, nx, y)) 
			best = min(best, nx*y);
	}
	if(r + x < n && s[r+x][c+y-1] == 'X') {
		int f = c+y-1;
		for(; f >= 0; f--)
			if(s[r+x][f] == '.')
				break;
		int ny = c+y-1-f;
		if(go(r, c, x, ny))
			best = min(best, x*ny);
	}
	if(best == INF)
		cout << -1 << endl;
	else
		cout << best << endl;
	return 0;
}
