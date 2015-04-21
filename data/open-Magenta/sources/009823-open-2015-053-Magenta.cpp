#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define sz(a) (int)a.size()

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef pair <int, int> ii;
typedef pair <ll, int> li;
typedef pair <int, ll> il;
typedef pair <ll, ll> lll;
typedef vector <ii> vii;
typedef vector <ll> vll;
typedef double db;
typedef long double ldb;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef set <int> si;
typedef set <ii> sii;
typedef set <ll> sl;
typedef set <lll> sll;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef vector <si> vsi;

const int N = (int)2e5 + 4;
const int M = (int)2e6 + 100;
const ll inf = (ll)1e9 + 7;
const ldb eps = 1e-10;

char m[4];
ii d[5001][5001];
int px[4] = {1, 0, -1, 0};
int py[4] = {0, 1, 0, -1};

bool good(int x, int y)
{
	if (x >= 0 && y >= 0 && x <= 12000 && y <= 12000)
		return 1;
	return 0;
}

/*int count(int x, int y)
{
	int ans = 0;
	for (int i = 0; i < 4; ++i)
		if (good(x + px[i], y + py[i]))
			++ans;
	return ans;
}*/

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(time(NULL));
	m[0] = 'R';
	m[1] = 'D';
	m[2] = 'L';
	m[3] = 'U';
	for (int i = 0; i <= 5000; ++i)
		for (int j = 0; j <= 5000; ++j)
			d[i][j] = mp(i, j);
	int x = 2500, y = 2500;
	d[x][y] = mp(x, y - 1);
	for (; ;)
	{
		int p = rand() % 4;
		int c = inf, s = -1;
		for (int i = 0; i < 10; p = rand() % 4)
			if (good(x + px[p], y + py[p]))
			{
				if (c > abs(x + px[p] - d[x + px[p]][y + py[p]].first) + abs(y + py[p] - d[x + px[p]][y + py[p]].second))
				{
					c = abs(x + px[p] - d[x + px[p]][y + py[p]].first) + abs(y + py[p] - d[x + px[p]][y + py[p]].second);
					s = p;
				}
				++i;
			}
		x += px[s];
		y += py[s];
		d[x][y] = mp(-(int)1e9, -(int)1e9);
		for (int i = 0; i < 4; ++i)
			if (good(x + px[i], y + py[i]) && abs(x - d[x][y].first) + abs(y - d[x][y].second) > abs(x - d[x + px[i]][y + py[i]].first) + abs(y - d[x + px[i]][y + py[i]].second))
				d[x][y] = d[x + px[i]][y + py[i]];
		cout << m[s] << '\n';
		fflush(stdout);
		char h;
		cin >> h;
		if (h == 'E')
			return 0;
		if (h == 'Y')
			return 0;
	}
	return 0;
}