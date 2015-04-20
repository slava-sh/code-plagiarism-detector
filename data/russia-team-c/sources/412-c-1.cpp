#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#include<queue>
#include<string>
#include<map>

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define next next_asjkdh
using namespace  std;
int t1, t2;
vector<vector<int> > v;
vector<bool> onWay;
vector<bool> used;
int fP, sP;
vector<int> f, s;
//vector<int> df, ds;
vector<int> way;
vector<bool> tused;
int ways = 0;

void updateF(int x) {
	used[x] = true;
	f[x] = 0;
	tused[x] = true;
	for (int i = 0; i < v[x].size(); ++i) {
		if (!used[v[x][i]] && !onWay[v[x][i]]) {
			updateF(v[x][i]);
		}
		if (!tused[v[x][i]] && !onWay[v[x][i]])
			f[x] = max(f[x], f[v[x][i]] + 1);
	}
	tused[x] = false;
}

void updateS(int x) {
	//cout << x << endl;
	used[x] = true;
	s[x] = 0;
	tused[x] = true;
	for (int i = 0; i < v[x].size(); ++i) {
		if (!used[v[x][i]] && !onWay[v[x][i]]) {
			updateS(v[x][i]);
		}
		if (!tused[v[x][i]] && !onWay[v[x][i]]) {
			s[x] = max(s[x], s[v[x][i]] + 1);
			//cerr << s[v[x][i]] << "!" << endl;
		}
	}
	tused[x] = false;
}

bool findWay(int x) {
	//cerr << ways << endl;
	//cerr << x << endl;
	way[ways++] = x;
	//cerr << x << endl;
	onWay[x] = true;
	//cerr << x << endl;
	if (x == sP)
		return true;
	for (int i = 0; i < v[x].size(); ++i) {
		//cerr << v[x][i] << " ";
		if (!onWay[v[x][i]]) {
			if (findWay(v[x][i])) 
				return true;
		}
	}
	onWay[x] = false;
	ways--;
	return false;
}

int main(void) {
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
    int n;
	cin >> n;
	v.resize(n);
	used.resize(n);
	onWay.resize(n);
	f.resize(n);
	s.resize(n);
	//ds.resize(n);
	//df.resize(n);
	tused.resize(n);
	way.resize(n);
	for (int i = 0; i < n; ++i) {
		used[i] = false;
		onWay[i] = false;
	}
	for (int i = 1; i < n; ++i) {
		cin >> t1 >> t2;
		t1--, t2--;
		v[t1].pb(t2);
		v[t2].pb(t1);
	}

	cin >> fP >> sP;
	fP--, sP--;
	//cerr << "OK" << endl;
	findWay(fP);
	way.resize(ways);
	for (int i = 0; i < (int)way.size() - 1; ++i) {
		updateF(way[i]);
		f[way[i]] += i;
		if (i > 0)
			f[way[i]] = max(f[way[i]], f[way[i - 1]] + 1);
	}
	/*for (int i = 0 ; i < n; ++i)
		used[i] = false;*/
	for (int i = (int) way.size() - 1; i > 0; --i) {
		updateS(way[i]);
		s[way[i]] += (ways - 1) - i;
		if (i < ways - 1)
			s[way[i]] = max(s[way[i]], s[way[i + 1]] + 1);
	}
	int max_ = -1;
	/*for (int i = 0; i < n; ++i)
		cout << s[i] << " ";
	cout << endl;*/
	for (int i = 0; i < ways - 1; ++i) {
		//cout << f[way[i]] << " " << s[way[i + 1]] << endl;
		if (min(f[way[i]], s[way[i + 1]]) > max_)
			max_ = min(f[way[i]], s[way[i + 1]]);
	}
	cout << max_ + 1 << endl;
}