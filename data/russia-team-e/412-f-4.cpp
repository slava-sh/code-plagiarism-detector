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

const int INF = 1000000000;
const ld eps = 1E-8;

class Point{
public:
	long double x, y;
	Point(ld x, ld y) : x(x), y(y){}
	Point(){}
	void turn(){
		ld tmp = x;
		x = y;
		y = -tmp;
	}
};

Point p[3000], k;

long double dist(Point a, Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double vp(Point a, Point b, Point c){
	ld ax = a.x - c.x;
	ld bx = b.x - c.x;
	ld ay = a.y - c.y;
	ld by = b.y - c.y;
	return ax * by - ay * bx;
}

long double sp(Point a, Point b, Point c){
	ld ax = a.x - c.x;
	ld bx = b.x - c.x;
	ld ay = a.y - c.y;
	ld by = b.y - c.y;
	return ax * bx + ay * by;
}

pair<Point, Point> getP(Point o, long double r, Point a, Point b){
	ld h = vp(a, b, o) / dist(a, b);
	Point v(a.x - b.x, a.y - b.y);
	v.turn();
	Point p1(a.x + v.x * h / dist(a, b), a.y + v.y * h / dist(a, b));
	if(!(abs(vp(a, b, p1)) < eps)){
		v.turn();
		v.turn();
		p1.x = a.x + v.x * h / dist(a, b);
		p1.y = a.y + v.y * h / dist(a, b);
	}
	ld l = sqrt(r * r - h * h);
	v.turn();
	Point p2(p1.x + v.x * l / dist(a, b), p1.y + v.y * l / dist(a, b));
	v.turn();
	v.turn();
	Point p3(p1.x + v.x * l / dist(a, b), p1.y + v.y * l / dist(a, b));
	pair<Point, Point> ans;
	if(abs(vp(a, b, p2)) < eps && sp(a, b, p2) < -eps)
		ans.first = p2;
	else ans.first.x = INF;
	if(abs(vp(a, b, p3)) < eps && sp(a, b, p3) < -eps)
		ans.second = p3;
	else ans.second.x = INF;
	return ans;
}

vector<Point> per;

const ld PI = atan2(1.0, 0.0) * 2.0;
long double findmax(Point a){
	Point m = per[0];
	ld tmp2 = atan2(a.y, a.x);
	ld tmp = (tmp2 - atan2(m.y, m.x));
	if (tmp < 0)
		tmp += PI;
	ld tmp3;
	for (int i = 1; i < per.size(); ++i) {
		tmp3 = tmp2 - atan2(per[i].y, per[i].x);
		if (tmp3 < 0) tmp3 += PI;
		if (tmp3 < tmp) {
			tmp = tmp3;	
		}
	}
	
	//cout << PI << endl;
	return tmp / PI * 180;
}

long double findmin(Point a){
	Point m = per[0];
	ld tmp2 = atan2(a.y, a.x);
	ld tmp = (tmp2 - atan2(m.y, m.x));
	if (tmp < 0)
		tmp += PI;
	ld tmp3 ;
	for (int i = 1; i < per.size(); ++i) {
		tmp3 = (tmp2 - atan2(per[i].y, per[i].x));
		if (tmp3 < 0)
			tmp3 += PI;
		if (tmp3 > tmp) {
			tmp = tmp3;	
		}
	}
	if (tmp < 0)
		tmp += 2 * PI;
	return tmp / PI * 180;
}

int main(void) {
    freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, m;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> p[i].x >> p[i].y;
	p[n] = p[0];
	cin >> m;
	cout << fixed << setprecision(20);
	for(int i = 0; i < m; ++i){
		cin >> k.x >> k.y;
		per.clear();
		for(int q = 0; q < n; ++q){
			pair<Point, Point> ne = getP(p[0], dist(p[0], k), p[q], p[q + 1]);
			if(ne.first.x < INF)
				per.pb(ne.first);
			if(ne.second.x < INF)
				per.pb(ne.second);
		}
		if (per.size() > 0)
			cout << 360.0 - findmin(k) << ' ' << findmax(k) << "\n";
		else
			cout << "360.0 360.0" << "\n";
	}

	return 0;
}