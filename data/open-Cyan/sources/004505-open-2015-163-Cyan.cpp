#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

int A, B, N;
vector<vector<pair<int, int> > > lines;
vector<int> tpl, atpl;

bool cmpx(int a, int b){
	return lines[a][0].second < lines[b][0].second
		|| (lines[a][0].second == lines[b][0].second
			&& (ll(lines[a][1].second - lines[a][0].second) * ll(lines[b][1].first - lines[b][0].first)
			< (ll(lines[b][1].second - lines[b][0].second) * ll(lines[a][1].first - lines[a][0].first))));
}

bool cmp(vector<pair<int, int> >::iterator a, vector<pair<int, int> >::iterator b, ld x){
	ld ax = a->second;
	ld bx = b->second;
	ax += (x - a->first) * ld((a+1)->second - a->second) / ((a+1)->first - a->first);
	bx += (x - b->first) * ld((b+1)->second - b->second) / ((b+1)->first - b->first);
	return (ax <= bx);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	cin >> A >> B >> N;
	lines.resize(N);
	tpl.resize(N);
	vector<pair<int, int> > ev;
	for(int i = 0; i < N; i++){
		int t;
		scanf("%d", &t);
		lines[i].resize(t+2);
		scanf("%d%d", &lines[i][0].first, &lines[i][0].second);
		for(int j = 1; j <= t; j++){
			scanf("%d%d", &lines[i][j].first, &lines[i][j].second);
			ev.emplace_back(make_pair(lines[i][j].first, i));
		}
		lines[i][t+1] = make_pair(B + 1, lines[i][t].second);
		tpl[i]= i;
	}
	sort(tpl.begin(), tpl.end(), cmpx);
	atpl.resize(tpl.size());
	for(int i = 0; i < (int)tpl.size(); i++){
		atpl[tpl[i]] = i;
	}
	sort(ev.begin(), ev.end());
	vector<vector<pair<int, int> >::iterator> it(N);
	for(int i = 0; i < N; i++){
		it[i] = lines[i].begin();
	}
	for(int i = 0; i < (int)ev.size(); i++){
		pair<int, int> cevent = ev[i];
		if(atpl[cevent.second] != 0){
			if(!cmp(it[tpl[atpl[cevent.second] - 1]], it[cevent.second], cevent.first)){
				cout << "No\n" << cevent.second + 1 << " " << tpl[atpl[cevent.second] - 1] + 1;
				return 0;
			}
		}
		if(atpl[cevent.second] != N - 1){
			if(!cmp(it[cevent.second], it[tpl[atpl[cevent.second] + 1]], cevent.first)){
				cout << "No\n" << cevent.second + 1 << " " << tpl[atpl[cevent.second] + 1] + 1;
				return 0;
			}
		}
		it[cevent.second]++;
	}
	cout <<"Yes";
	return 0;
}