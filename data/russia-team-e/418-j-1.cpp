#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define NAME "travel"

//#define DEBUG

#ifdef DEBUG
#define eprintf(...) printf(__VA_ARGS__), fflush(stdout)
#else
#define eprintf(...)
#endif

typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define frs first
#define scn second
#define mp make_pair
#define pb push_back
#define ins insert

typedef pair<int, int> pii;

int const N = 501;

int const D = 4;
int const dy[D] = { 0,  1,  0, -1};
int const dx[D] = {-1,  0,  1,  0};
char const name[D + 1] = "WSEN";

int w, h;
int n;
int sx, sy, fx[2], fy[2], fd[2] = {-1, -1};
char field[N][N];            
int d[N][N];
int prev[N][N];

deque<pii> q;
vector<char> ans;

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d%d%d", &w, &h, &n);
	for (int i(0); i < h; ++i)
	{
		scanf(" %s", field[i]);
		for(int j(0); j < w; ++j)
		{
			if (field[i][j] == 'V')
			{
				sy = i;
				sx = j;
		   	}
			d[i][j] = -1;
		}   
	}

	q.pb(mp(sy, sx));
	d[sy][sx] = 0; 
	while (q.size())
	{
		pii v = q.front();
		q.pop_front();
		int y = v.frs;
		int x = v.scn;
		
		if (field[y][x] == 'T')
		{
			bool isCool = false;
			for (int dir(0); dir < D && !isCool; ++dir)
			{
				int ty = y + dy[dir];
				int tx = x + dx[dir];
				if (ty < 0 || tx < 0 || tx >= w || ty >= h)
					continue;
				if (field[ty][tx] == 'T')
					isCool = true;
			}
		
			if (fd[isCool] == -1)
			{
				fy[isCool] = y;
				fx[isCool] = x;
				fd[isCool] = d[y][x];
			}    
		}
		for (int dir(0); dir < D; ++dir)
		{
			int ty = y + dy[dir];
			int tx = x + dx[dir];
			if (ty < 0 || tx < 0 || tx >= w || ty >= h)
				continue;
			if (d[ty][tx] != -1)
				continue;
			d[ty][tx] = d[y][x] + 1;
			prev[ty][tx] = dir;
			q.pb(mp(ty, tx));
		}
	}
	eprintf("! F = %d: %d %d | %d: %d %d\n", fd[0], fy[0], fx[0], fd[1], fy[1], fx[1]);

	bool flag;
	if (fd[1] == -1 || fd[0] + 2 * (n - 1) < fd[1] + n - 1)
		flag = false;
	else
		flag = true;	
	eprintf("! Flag = %d\n", flag);

	int y = fy[flag];
	int x = fx[flag];
	int mv = prev[y][x];
	while (x != sx || y != sy)
	{
		ans.pb(name[prev[y][x]]);
		int ty = y - dy[prev[y][x]];
		int tx = x - dx[prev[y][x]];
		y = ty;
		x = tx;
	}
	reverse(ans.begin(), ans.end());
	
	if (!flag)
	{
		for (int i(2); i <= n; ++i)
		{
			ans.pb(name[(mv + 2) % 4]);
			ans.pb(name[mv]);
		}   
	}
	else
	{
		for (int dir(0); dir < D; ++dir)
		{
			int ty = fy[1] + dy[dir];
			int tx = fx[1] + dx[dir];
			if (ty < 0 || tx < 0 || tx >= w || ty >= h)
				continue;
			if (field[ty][tx] == 'T')
			{
				mv = dir;
				eprintf("!   cool T at %d %d\n", ty, tx);
			}   
		}
		eprintf("!   mv = %c\n", name[mv]);
		for (int i(2); i <= n; ++i)
			if (i % 2 == 0)
				ans.pb(name[mv]);
			else 
				ans.pb(name[(mv + 2) % 4]);
	}

	for (uint i(0); i < ans.size(); ++i)
		printf("%c", ans[i]);
	
	return 0;
}



























