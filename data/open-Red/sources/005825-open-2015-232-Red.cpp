#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define mp make_pair
#define ll long long

using namespace std;

multimap<int, int> m[100001];
multimap<int, int> save[100001];
multimap<int, pair<int, int> > s;
priority_queue<pair<int, pair<int, int> >, vector<int>, greater<int> > s2;

int a, b, c, d, e, g;
const int INF = 2E9 + 1;

int solve(int fr, int to){
	//s.clear();
	while(!s2.empty()) s2.pop();
	s2.push(mp(0, mp(fr, INF)));
	//s.insert(mp(0, mp(fr, INF)));
	while(!s2.empty()){
		int x = s2.top().second.first;
		int t = s2.top().second.second;
		int time = s2.top().first;
		//cout << x + 1 << ' ' << t << ' ' << time << "\n";
		s2.pop();
		int min_ = t - c;
		int max_ = t + c;
		if(t == INF) min_ = -INF, max_ = INF;
		multimap<int, int>::iterator l = m[x].lower_bound(min_);
		multimap<int, int>::iterator r = m[x].upper_bound(max_), l_ = l;
		while(l != r){
			if(l->second == to) return time + 1;
			s2.push(mp(time + 1, mp(l->second, l->first)));
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
	for(int i = 0; i < a; ++i)
		save[i] = m[i];
	for(int i = 0; i < d; ++i){
		if(i != 0)
			for(int i = 0; i < a; ++i)
				m[i] = save[i];
		cin >> e >> g;
		--e, --g;
		cout << solve(e, g) << "\n";
	}
}