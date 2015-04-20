#include <cstdio>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int n, m, t;

set <set<pair<int, int> > > End;

#define x first
#define y second

void gen(set<pair<int, int> > &conf, int T)
{
	if (T == t)
		return void(End.insert(conf));
	set <pair<int, int> > used;
	int N = conf.size();
	for (set<pair<int, int> > :: iterator it = conf.begin(); it != conf.end(); ++it)
	{
		if (it->x + 1 < n &&  used.find(make_pair(it->x + 1, it->y)) == used.end())
		{
			used.insert(make_pair(it->x + 1, it->y));
			conf.insert(make_pair(it->x + 1, it->y));
			if (conf.size() > N) {
				gen(conf, T + 1);
				conf.erase(make_pair(it->x + 1, it->y));
			}
		}
		if (it->x > 0 &&  used.find(make_pair(it->x - 1, it->y)) == used.end())
		{
			used.insert(make_pair(it->x - 1, it->y));
			conf.insert(make_pair(it->x - 1, it->y));
			if (conf.size() > N) {
				gen(conf, T + 1);
			conf.erase(make_pair(it->x - 1, it->y));
			}
		}
		if (it->y > 0 &&  used.find(make_pair(it->x, it->y - 1)) == used.end())
		{
			used.insert(make_pair(it->x, it->y - 1));
			conf.insert(make_pair(it->x, it->y - 1));
			if (conf.size() > N) {
				gen(conf, T + 1);
			conf.erase(make_pair(it->x, it->y - 1));
			}
		}
		if (it->y + 1 < m &&  used.find(make_pair(it->x, it->y + 1)) == used.end())
		{
			used.insert(make_pair(it->x, it->y + 1));
			conf.insert(make_pair(it->x, it->y + 1));
			if (conf.size() > N) {
				gen(conf, T + 1);
			conf.erase(make_pair(it->x, it->y + 1));
			}
		}
	}
}

int main()
{
	freopen("virus.in", "r", stdin);
	freopen("virus.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &t);
	char c;
	set <pair<int, int> >  conf;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			do
			{
				scanf("%c", &c);
			}
			while (c != '.' && c !='*');
			if (c == '*')
				conf.insert(make_pair(i, j));
		}
	}
	gen(conf, 0);
	printf("%d\n", End.size());
	return 0;
}