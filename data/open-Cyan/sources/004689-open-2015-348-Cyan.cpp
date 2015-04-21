#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define local
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 100010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



struct vect {
	ld x, y;
	vect(){}
	vect(ld x, ld y) : x(x), y(y){}
	vect(vect s, vect t) : x(t.x - s.x), y(t.y - s.y){}
	void scan(){
		scanf("%Lf %Lf", &x, &y);
	}
	vect operator + (vect s){
		return vect(x + s.x, y + s.y);
	}
	vect operator - (vect s){
		return vect(x - s.x, y - s.y);
	}
	vect operator * (ld t){
		return vect(x * t, y * t);
	}
};

ld c_prod(vect s, vect t){
	return s.x*t.y - s.y*t.x;
}

ld d_prod(vect s, vect t){
	return s.x*t.x + s.y*t.y;
}

ld len_v(vect s){
	return hypot(s.x, s.y);
}

struct line {
	vect s, v;
	line(){}
	line(vect s, vect t) : s(s), v(t - s){}
};

vect l_vs_l(line a, line b){
	ld t = c_prod(b.v, b.s - a.s) / c_prod(b.v, a.v);
	return a.s + (a.v * t);
}

struct poly {
	vector<vect> p;
	int num;
};

int p_vs_p(poly &a, poly &b){
	int n = a.p.size(), m = b.p.size();
	int big = -1;
	for (int i = 0; i < n; i++){
		ld x = a.p[i].x, y = a.p[i].y;
		int l = -1, r = m, mid;
		while (r - l > 1){
			mid = (l + r) >> 1;
			if (x < b.p[mid].x + eps){
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (r == 0){
			l++, r++;
		}
		line ln(b.p[l], b.p[r]), h(vect(x, 100), vect(x, 0));
		if (abs(c_prod(ln.v, h.v)) < eps){
			continue;
		}
		vect M = l_vs_l(ln, h);
		if (big == -1){
			if (abs(y - M.y) > eps){
				big = y > M.y;
			}
		}
		else if (abs(y - M.y) > eps){
			if (big != (y > M.y)){
				return inf;
			}
		}
	}
	return big;
}

bool operator < (poly a, poly b){
	int big1 = p_vs_p(a, b), big2 = p_vs_p(b, a);
	if (big1 == inf || big2 == inf){
		cout << "No\n" << a.num << " " << b.num;
		exit(0);
	}
	if (big1 == -1 && big2 == -1){
		return 0;
	}
	if (big2 == -1){
		return !big1;
	}
	if (big1 == -1){
		return big2;
	}
	return big2;
}

int main(){
#ifdef local
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	int n, m, i, k, a, b;
	cin >> a >> b;
	cin >> n;

	vector<poly> lns;
	for (i = 0; i < n; i++){
		scanf("%d", &m);
		poly cp;
		cp.num = i + 1;
		for (k = 0; k <= m; k++){
			vect cur;
			cur.scan();
			cp.p.push_back(cur);
		}
		lns.push_back(cp);
	}

	sort(lns.begin(), lns.end());

	/*for (i = 0; i < n; i++){
		for (k = i + 1; k < n; k++){
			if (p_vs_p(lns[i], lns[k]) == inf || p_vs_p(lns[k], lns[i]) == inf){
				cout << "No\n" << lns[i].num << " " << lns[k].num;
				return 0;
			}
		}
	}*/
	cout << "Yes";

	return 0;
}