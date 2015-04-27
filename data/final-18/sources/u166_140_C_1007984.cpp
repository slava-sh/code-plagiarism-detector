//#pragma comment(linker,"/STACK:256000000")

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cassert>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

#define ldb long double
#define LL long long
#define nextline() {int c; while ((c = getchar()) != 10 && c != EOF);}

#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

#define sqr(x) ((x) * (x))
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)

#define all(a) a.begin(), a.end()
#define two(i) (1 << (i))
#define has(mask, i) ((((mask) & two(i)) == 0) ? false : true)

const int INF = 1000 * 1000 * 1000;
const LL INF64 = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;

int n;

void Load()
{
	scanf ("%d", &n);

}

vector <int> v;
vector <pair <int, int> > tmp;
map <int, int> mp;
set <pair <int, int> > mn_st, mx_st;

vector <vector <int> > ans_v;

void Solve()
{                              	
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &x);
		if (mp.find(x) == mp.end())
		{
			mp[x] = 1;
			v.push_back(x);
		}
		else
			mp[x]++;
	}

	for (int i = 0; i < (int)v.size(); i++)
	{
		x = v[i];
		mn_st.insert(make_pair (mp[x], x));
		mx_st.insert(make_pair (-mp[x], x));	
	}

	pair <int, int> p;

	while ((int)mn_st.size() > 2)
	{
		v.clear();
		tmp.clear();
		p = (*mn_st.begin());
		mn_st.erase (p);
		mx_st.erase (make_pair (-p.first, p.second));
		tmp.push_back(p);

		p = (*mx_st.begin());
		p.first *= -1;
		mn_st.erase (p);
		mx_st.erase (make_pair (-p.first, p.second));
		tmp.push_back(p);
		p = (*mx_st.begin());
		p.first *= -1;
		mn_st.erase (p);
		mx_st.erase (make_pair (-p.first, p.second));
		tmp.push_back(p);
		for (int i = 0; i < 3; i++)
		{
			v.push_back(tmp[i].second);
			tmp[i].first--;
			if (tmp[i].first > 0)
			{
				mn_st.insert (tmp[i]);
				mx_st.insert (make_pair (-tmp[i].first, tmp[i].second));
			}
		}
		sort (v.begin(), v.end());
		ans_v.push_back(v);
	}

	printf ("%d\n", (int)ans_v.size());
 	for (int i = 0; i < (int)ans_v.size(); i++)
 		printf ("%d %d %d\n", ans_v[i][2], ans_v[i][1], ans_v[i][0]);
}
                
int main()
{
	//ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("in", "rt", stdin);
	freopen("out", "wt", stdout);
#endif
	Load();
	Solve();
	return 0;
}
