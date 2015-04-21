#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#define mp make_pair
#define ll long long

using namespace std;

multimap<int, int> m[100001];
multimap<int, int> save[100001];
multimap<int, pair<int, int> > s;

int a, b, c, d, e, g;
const int INF = 2E9 + 1;

int solve(int fr, int to){
	s.clear();
	s.insert(mp(0, mp(fr, INF)));
	while(!s.empty()){
		int x = s.begin()->second.first;
		int t = s.begin()->second.second;
		int time = s.begin()->first;
		//cout << x << ' ' << t << ' ' << time << "\n";
		s.erase(s.begin());
		int min_ = t - c;
		int max_ = t + c;
		if(t == INF) min_ = -INF, max_ = INF;
		multimap<int, int>::iterator l = m[x].lower_bound(min_);
		multimap<int, int>::iterator r = m[x].upper_bound(max_), l_ = l;
		while(l != r){
			if(l->second == to) return time + 1;
			s.insert(mp(time + 1, mp(l->second, l->first)));
			++l;
		}
		m[x].erase(l_, r);
	}
	return -1;
}

int main(){
	cin >> a >> b >> c;
	for(int i = 0; i < b; ++i){
		cin >> d >> e >> g;
		--d, --e;
		m[d].insert(mp(g, e));
		m[e].insert(mp(g, d));
	}
	cin >> d;
	for(int i = 0; i < d; ++i){
		if(i != 0)
			for(int i = 0; i < a; ++i)
				m[i] = save[i];
		cin >> e >> g;
		--e, --g;
		cout << solve(e, g) << "\n";
	}
}