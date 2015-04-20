#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<vector<char> > vec;
vector<char> ans;
vector<vector<int> > d;
vector<pair<int, int> > t;
vector<pair<int, int> > t2;
int main()
{
	int w, h, n;
	ifstream cin("travel.in");
	ofstream cout("travel.out");
	cin >> w >> h >> n;
	vec.resize(h);
	d.resize(h);
	int x, y;
	for ( int i = 0; i < h; ++i )
	{
		vec[i].resize(w);
		d[i].assign(w, -1);
		for ( int j = 0; j < w; ++j )
		{
			cin >> vec[i][j];
			if ( vec[i][j] == 'V' )
			{
				x = i;
				y = j;
			}
			if ( vec[i][j] == 'T' )
				t.push_back(make_pair(i, j));
		}
	}
	d[x][y] = 0;
	for ( int i = x; i < h; ++i )
	{
		for ( int j = y; j < w; ++j )
		{
			if ( i == x && j == y )
				continue;
			d[i][j] = max((i - 1 >= x ? d[i - 1][j] : 0), (j - 1 >= y ? d[i][j - 1] : 0 ));
			if ( vec[i][j] == 'T' )
				d[i][j]++;
		}
	}
	for ( int i = x; i < h; ++i )
	{
		for ( int j = y; j >= 0; --j )
		{
			if ( i == x && j == y )
				continue;
			d[i][j] = max((i - 1 >= x ? d[i - 1][j] : 0), (j + 1 <= y ? d[i][j + 1] : 0 ));
			if ( vec[i][j] == 'T' )
				d[i][j]++;
		}
	}
	for ( int i = x; i >= 0; --i )
	{
		for ( int j = y; j >= 0; --j )
		{
			if ( i == x && j == y )
				continue;
			d[i][j] = max((i + 1 <= x ? d[i + 1][j] : 0), (j + 1 <= y ? d[i][j + 1] : 0 ));
			if ( vec[i][j] == 'T' )
				d[i][j]++;
		}
	}
	for ( int i = x; i >= 0; --i )
	{
		for ( int j = y; j < w; ++j )
		{
			if ( i == x && j == y )
				continue;
			d[i][j] = max((i + 1 <= x ? d[i + 1][j] : 0), (j - 1 >= y ? d[i][j - 1] : 0 ));
			if ( vec[i][j] == 'T' )
				d[i][j]++;
		}
	}
	for ( int i = 0; i < t.size(); ++i )
	{
		for ( int p = -1; p <= 1; ++p )
		{
			for ( int q = -1; q <= 1; ++q )
			{
				if ( abs(p) + abs(q) == 1 )
				{
					if ( t[i].first + p >= 0 && t[i].first + p < h && t[i].second + q >= 0 && t[i].second + q < w )
					{
						if ( vec[t[i].first + p][t[i].second + q] == 'T' )
							t2.push_back(make_pair(t[i].first, t[i].second));
					}
				}
			}
		}
	}
	const int INF = 1000 * 1000 * 1000;
	int answ = INF;
	int rx, ry, type;
	for ( int i = 0; i < t.size(); ++i )
	{
		if ( abs(x - t[i].first) + abs(y - t[i].second) + 2 * (n - 1) < answ )
		{
			answ = abs(x - t[i].first) + abs(y - t[i].second) + 2 * (n - 1);
			rx = t[i].first;
			ry = t[i].second;
			type = 1;
		}
	}
	for ( int i = 0; i < t2.size(); ++i )
	{
		if ( abs(x - t2[i].first) + abs(y - t2[i].second) + n - d[t2[i].first][t2[i].second] < answ )
		{
			answ = abs(x - t2[i].first) + abs(y - t2[i].second) + n - 1;
			rx = t2[i].first;
			ry = t2[i].second;
			type = 2;
		}
	}
	if ( type == 1 )
	{
		int dy = rx - x;
		int dx = ry - y;
		char last;
		if ( dx < 0 )
			for ( int i = 0; i < abs(dx); ++i )
			{
				last = 'W';
				cout << "W";
			}
		else
			for ( int i = 0; i < dx; ++i )
			{
				last = 'E';
				cout << "E";
			}
		if ( dy < 0 )
			for ( int i = 0; i < abs(dy); ++i )
			{
				last = 'S';
				cout << "S";
			}
		else
			for ( int i = 0; i < dy; ++i )
			{
				last = 'N';
				cout << "N";
			}
		char next;
		if ( last == 'N' )
			next = 'S';
		if ( last == 'W' )
			next = 'E';
		if ( last == 'E' )
			next = 'W';
		if ( last == 'S' )
			next = 'N';
		for ( int i = 0; i < n - 1; ++i )
			cout << next << last;
		return 0;
	}
	int px = rx, py = ry;
	int dx, dy;
	if ( rx > x )
		dx = -1;
	else
		dx = 1;
	if ( ry < y )
		dy = 1;
	else
		dy = -1;
	while ( px != x || py != y )
	{
		if ( px == x )
		{
			py = py + dy;
			if ( dy < 0 )
				ans.push_back('E');
			else
				ans.push_back('W');
			continue;
		}
		if ( py == y )
		{	
			px = px + dx;
			if ( dx < 0 )
				ans.push_back('S');
			else
				ans.push_back('N');
			continue;
		}
		if ( d[px + dx][py] > d[px][py + dy] )
		{
			px = px + dx;
			if ( dx < 0 )
				ans.push_back('S');
			else
				ans.push_back('N');
		}
		else
		{
			py = py + dy;
			if ( dy < 0 )
				ans.push_back('E');
			else
				ans.push_back('W');
		}
	}
	reverse(ans.begin(), ans.end());
	for ( int i = 0; i < ans.size(); ++i )
	{
		cout << ans[i];
	}
	int tx, ty;
	for ( int p = -1; p <= 1; ++p )
	{
		for ( int q = -1; q <= 1; ++q )
		{
			if ( abs(p) + abs(q) == 1 )
			{
				if ( rx + p >= 0 && rx + p < h && ry + q >= 0 && ry + q < w )
				{
					if ( vec[rx + p][ry + q] == 'T' )
					{
						tx = rx + p;
						ty = ry + q;
					}
				}
			}
		}
	}
	char ch1, ch2;
	if ( tx < rx )
	{
		ch1 = 'N';
		ch2 = 'S';
	}
	if ( tx > rx )
	{
		ch1 = 'S';
		ch2 = 'N';
	}
	if ( ty > ry )
	{
		ch1 = 'E';
		ch2 = 'W';
	}
	if ( ty < ry )
	{
		ch1 = 'W';
		ch2 = 'E';
	}
	for ( int i = 0; i < (n - d[rx][ry]); ++i )
	{
		cout << ch1;
		swap(ch1, ch2);
	}
	return 0;
}