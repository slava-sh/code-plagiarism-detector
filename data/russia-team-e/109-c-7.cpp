#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long li;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int INF = 1e9;
const li P = 1e9 + 7;

struct nd {
	pair<int, int> mx1, mx2;
	int pr, d;
} g[400005];

vector<int> a[400005];

void dfs(int v, int pr = -1) {
	int i, to;
	g[v].pr = pr;
	g[v].mx1 = mp(0, -1);
	g[v].mx2 = mp(0, -1);
	if (pr == -1)
		g[v].d = 0;
	else
		g[v].d = g[pr].d + 1;
	if (a[v].size() == 1 && pr != -1) {
		g[v].mx1 = mp(0, v);
		g[v].mx2 = mp(0, -1);
	}
	for (i = 0; i < a[v].size(); i++) {
		if (a[v][i] != pr) {
			to = a[v][i];
			dfs(to, v);
			if (g[to].mx2.fs + 1 > g[v].mx1.fs) {
				if (g[v].mx1.sc != g[to].mx2.sc)
					g[v].mx2 = g[v].mx1;
				g[v].mx1 = mp(g[to].mx2.fs + 1, to);
				if (g[v].mx1.sc == g[v].mx2.sc)
					g[v].mx2 = mp(-INF, -1);
			} else if (g[to].mx2.fs + 1 > g[v].mx2.fs && to != g[v].mx1.sc) {
				g[v].mx2 = mp(g[to].mx2.fs + 1, to);
			}
			if (g[to].mx1.fs + 1 > g[v].mx1.fs) {
				if (g[v].mx1.sc != g[to].mx1.sc)
					g[v].mx2 = g[v].mx1;
				g[v].mx1 = mp(g[to].mx1.fs + 1, to);
				if (g[v].mx1.sc == g[v].mx2.sc)
					g[v].mx2 = mp(-INF, -1);
			} else if (g[to].mx1.fs + 1 > g[v].mx2.fs && to != g[v].mx1.sc) {
				g[v].mx2 = mp(g[to].mx1.fs + 1, to);
			}
		}
	}
}

/*< int, int > st;
int mx = -1;
char desk[505][505];
bool used[505][505];
int w, h, n;
pair< pair< int, int >, bool > bpos;
int turtle[505][505];

int d (pair< int, int > x, pair< int, int > y)
{
	return abs (x.fs - y.fs) + abs (x.sc - y.sc);
}

void bfs ()
{
	queue< pair< int, int > > b;
	b.push (st);
	used[st.fs][st.sc] = true;
	while (!b.empty ())
	{
		pair< int, int > cur;
		cur = b.front ();
		if (desk[cur.fs][cur.sc] == 'T')
		{
			mx = max (mx, d (st, cur) + 2 * (n - 1));
			bpos = mp (cur, 0);
		}
		b.pop ();
		for (int i = -1 ; i <= 1 ; ++i)
			for (int j = -1 ; j <= 1 ; ++j)
				if (abs (i + j) == 1)
					if (cur.fs + i >= 0 && cur.fs + i < h && cur.sc + j >= 0 && cur.sc + j < w && !used[cur.fs + i][cur.sc + j])
						b.push (mp (cur.fs + i, cur.sc + j));
	}
}

inline int sgn (int n)
{
	if (n < 0)
		return -1;
	else if (n == 0)
		return 0;
	else return 1;
}

void path (pair< int, int > pos)
{
	if (turtle[pos.fs + sgn (st.fs - pos.fs)][pos.sc] > turtle[pos.fs][pos.sc + sgn (st.sc - pos.sc)])
	{
		path (mp (pos.fs + sgn (st.fs - pos.fs), pos.sc));
		cout << (sgn (st.fs - pos.fs) == -1 ? 'E' : 'W');
	}
	else
	{
		path (mp (pos.fs, pos.sc + sgn (st.sc - pos.sc)));
		cout << (sgn (st.fs - pos.fs) == -1 ? 'S' : 'N');
	}
}*/


int main() {
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	int n, i, x, y, s1, s2, ans = 0, a1, a2, a3, pp, p1;
	pair<int, int> q, q1;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	cin >> s1 >> s2;
	s1--;
	s2--;
	dfs(s1);
	i = s2;
	while (g[i].pr != s1) {
		i = g[i].pr;
	}
	pp = i;
	p1 = -1;
	i = s2;
	while (true) {
		q = g[i].mx1;
		if (q.sc == p1) {
			q = g[i].mx2;
		}
		if (q.sc != -1) {
			a1 = q.fs + g[s2].d - g[i].d;
		} else {
			a1 = g[s2].d - g[i].d;
		}
		q1 = g[g[i].pr].mx1;
		if (q1.sc == i) {
			q1 = g[g[i].pr].mx2;
		}
		if (q1.sc != -1) {
			a2 = q1.fs + g[g[i].pr].d;
		} else {
			a2 = g[g[i].pr].d;
		}
		q = g[s1].mx1;
		if (q.sc == pp)
			q = g[s1].mx2;
		if (q.sc == -1)
			a3 = 0;
		else
			a3 = q.fs;
		a2 = max(a2, a3);
		ans = max(ans, min(a1, a2));
		p1 = i;
		i = g[i].pr;
		if (i == s1)
			break;
	}
	cout << ans + 1;
	
	/*cin >> w >> h >> n;
	for (int i = 0 ; i < h ; ++i)
		for (int j = 0 ; j < w ; ++j)
		{
			cin >> desk[i][j];
			if (desk[i][j] == 'V')
				st = mp (i, j);
			used[i][j] = false;
		}
	bfs ();
	turtle[st.fs][st.sc] = 0;
	for (int i = st.fs + 1 ; i < h ; ++i)
	{
		turtle[i][st.sc] = turtle[i - 1][st.sc] + (desk[i][st.sc] == 'T');
	}
	for (int i = st.fs - 1 ; i >= 0 ; --i)
	{
		turtle[i][st.sc] = turtle[i + 1][st.sc] + (desk[i][st.sc] == 'T');
	}
	for (int i = st.sc + 1 ; i < w ; ++i)
	{
		turtle[st.fs][i] = turtle[st.fs][i - 1] + (desk[st.fs][i] == 'T');
	}
	for (int i = st.sc - 1 ; i >= 0 ; --i)
	{
		turtle[st.fs][i] = turtle[st.fs][i + 1] + (desk[st.fs][i] == 'T');
	}
	for (int i = st.fs + 1 ; i < h ; ++i)
	{
		for (int j = st.sc + 1 ; j < w ; ++j)
		{
			turtle[i][j] = max (turtle[i][j - 1], turtle[i - 1][j]) + (desk[i][j] == 'T');
		}
		for (int j = st.sc - 1 ; j >= 0 ; --j)
		{
			turtle[i][j] = max (turtle[i][j + 1], turtle[i - 1][j]) + (desk[i][j] == 'T');
		}
	}
	for (int i = st.fs - 1 ; i >= 0 ; --i)
	{
		for (int j = st.sc + 1 ; j < w ; ++j)
		{
			turtle[i][j] = max (turtle[i][j - 1], turtle[i + 1][j]) + (desk[i][j] == 'T');
		}
		for (int j = st.sc - 1 ; j >= 0 ; --j)
		{
			turtle[i][j] = max (turtle[i][j + 1], turtle[i + 1][j]) + (desk[i][j] == 'T');
		}
	}
	for (int i = 0 ; i < h ; ++i)
		for (int j = 0 ; j < w ; ++j)
		{
			if (desk[i][j] == 'T')
			{
				if ((i && desk[i - 1][j] == 'T') || (j && desk[i][j - 1] == 'T')
					|| (i + 1 < h && desk[i + 1][j] == 'T') || (j + 1 < w && desk[i][j + 1] == 'T'))
				{
					if (mx < d (mp (i, j), st) + n - turtle[i][j])
					{
						mx = d (mp (i, j), st) + n - turtle[i][j];
						bpos = mp (mp (i, j), 1);
					}
				}
			}
		}
	path (bpos.fs);
	if (bpos.sc)
	{
		int i = bpos.fs.fs, j = bpos.fs.sc;
		if (i && desk[i - 1][j] == 'T')
		{
			int k = n - turtle[i][j];
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "NS";
			}
			if (k)
				cout << "N";
			return 0;
		}
		if (j && desk[i][j - 1] == 'T')
		{
			int k = n - turtle[i][j];
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "WE";
			}
			if (k)
				cout << "W";
			return 0;
		}
		if (i + 1 < h && desk[i + 1][j] == 'T')
		{
			int k = n - turtle[i][j];
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "SN";
			}
			if (k)
				cout << "S";
			return 0;
		}
		if (j + 1 < w && desk[i][j + 1] == 'T')
		{
			int k = n - turtle[i][j];
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "EW";
			}
			if (k)
				cout << "E";
			return 0;
		}
	}
	else
	{
		int i = bpos.fs.fs, j = bpos.fs.sc;
		if (i)
		{
			int k = 2 * (n - 1);
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "NS";
			}
			if (k)
				cout << "N";
			return 0;
		}
		if (j)
		{
			int k = 2 * (n - 1);
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "WE";
			}
			if (k)
				cout << "W";
			return 0;
		}
		if (i + 1 < h)
		{
			int k = 2 * (n - 1);
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "SN";
			}
			if (k)
				cout << "S";
			return 0;
		}
		if (j + 1 < w)
		{
			int k = 2 * (n - 1);
			for (; k / 2 > 0 ; k -= 2)
			{
				cout << "EW";
			}
			if (k)
				cout << "E";
			return 0;
		}
	}*/
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

10
1 2
2 4
2 3
1 5
5 9
5 10
10 8
10 7
10 6
1 8

5
1 2
2 3
3 4
4 5
1 5

*/