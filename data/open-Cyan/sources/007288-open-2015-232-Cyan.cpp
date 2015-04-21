#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#define ld long double
#define ll long long
#define mp make_pair

const ld eps = 1E-6;

using namespace std;

class Point{
public:
	ld x, y;
	explicit Point(int){ cin >> x >> y; }
};

class Line{
public:
	Point a, b;
	Line(Point a, Point b): a(a), b(b){}
	ld get_y(ld);
};

ld A, B;
int a, b;
vector<Point> v[100001];
vector<Line> line[100001];
ll h[100001];

int X = 0;

ld abs_(ld a){
	return (a < 0 ? -a : a);
}

ld Line::get_y(ld x){
	if(abs_(x - a.x) < eps) return a.y;
	if(abs_(x - b.x) < eps) return b.y;
	if(abs_(a.y - b.y) < eps) return a.y;
	return (b.y - a.y) * (b.x - a.x) / (x - a.x) + a.y;
}

class Cmp{
public:
	bool operator()(pair<int, int> a, pair<int, int> b){
		bool f = 1;
		if(a.first == b.first) return 0;
		if(h[a.first] > h[b.first]) f = 0, swap(a, b);
		//cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << "\n";
		if(line[a.first][a.second].get_y(X) > line[b.first][b.second].get_y(X) + eps){
			cout << "No\n";
			cout << a.first + 1 << ' ' << b.first + 1;
			exit(0);
		}
		return f;
	}
};

set<pair<int, int>, Cmp> s;
vector<pair<int, pair<int, int> > > sr;

typedef set<pair<int, int>, Cmp>::iterator iter;

Cmp cmp;

iter next(iter a){
	++a;
	return a--;
}

iter prev(iter a){
	--a;
	return a++;
}

int main(){
	cin >> A >> B;
	cin >> a;
	for(int i = 0; i < a; ++i){
		cin >> b;
		for(int q = 0; q <= b; ++q){
			v[i].push_back(Point(0));
			if(q > 0){
				line[i].push_back(Line(v[i][q], v[i][q - 1]));
				sr.push_back(mp(v[i][q].x, mp(i, q)));
			}
		}
		h[i] = (ll)v[i][0].y * (ll)2E9 + (ll)v[i][1].y;
		s.insert(mp(i, 0));
	}
	sort(sr.begin(), sr.end());
	for(size_t i = 0; i < sr.size(); ++i){
		X = sr[i].first;
		set<pair<int, int>, Cmp>::iterator tmp = s.find(mp(sr[i].second.first, sr[i].second.second - 1));
		if(tmp != s.begin()) cmp(*prev(tmp), *tmp);
		if(next(tmp) != s.end()) cmp(*next(tmp), *tmp);
		s.erase(mp(sr[i].second.first, sr[i].second.second - 1));
		//cout << sr[i].first << ' ' << sr[i].second.first << "\n";
		if(sr[i].second.second != line[sr[i].second.first].size()) s.insert(sr[i].second);
		//cout << sr[i].first << ' ' << sr[i].second.first << "\n";
	}
	cout << "Yes\n";

	return 0;
}