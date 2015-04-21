#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cassert>	

using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;

const int M = 3 * 1e3;

struct seg{
	int x1, y1, x2, y2, num;
};

struct point{
	int x, y;
	point(){}
	point (int x1, int y1){
		x = x1;
		y = y1;
	}
	
};

 /*bool operator = (point a, point b){
		return (a.x == b.x) && (a.y == b.y);
}*/


vector<seg> g[M];
int x[M][M], y[M][M];

 point operator - ( point a,  point b){
	point c;
	c.x = b.x - a.x;
	c.y = b.y - a.y;
	return c;
}
 ll operator * ( point a,  point b){
	return (ll)a.x * (ll)b.y - (ll)a.y * (ll)b.x;
}


  
ld val (seg a, int X){
	return (ld)(a.y2 - a.y1) * (ld)(X - a.x1) / (ld)(a.x2 - a.x1) + a.y1;
}/*
bool operator <  (seg a, seg b){
	return val(a) < val(b);
}   */

bool go(int x1, int y1, int x2, int y2){
	return x1 == y1 && x2==y2;
}       /*
void check(seg a, seg b){
	if ((point(a.x2 - a.x1, a.y2 - a.y1) * point(b.x2 - b.x1, b.y2 - b.y1)) == 0)
		return;
	if (go(a.x1, a.y1, b.x1, b.y1))
		return;
	if (go(a.x1, a.y1, b.x2, b.y2))
		return;
	if (go(a.x2, a.y2, b.x1, b.y1))
		return;
	if (go(a.x2, a.y2, b.x2, b.y2))
		return;
	bool ok1 =  ((point(b.x2 - a.x1, b.y2 - a.y1) * point(a.x2 - a.x1, a.y2 - a.y1)) * (point(b.x1 - a.x1, b.y1 - a.y1) *point(a.x2 - a.x1, a.y2 - a.y1) ) < 0);
	bool ok2 =  ((point(a.x2 - b.x1, a.y2 - b.y1) * point(b.x2 - b.x1, b.y2 - b.y1)) * (point(a.x1 - b.x1, a.y1 - b.y1) *point(b.x2 - b.x1, b.y2 - b.y1) ) < 0);
	if (ok1 && ok2){
		cout << "No" << endl << a.num << " " << b.num << endl;
		exit(0);
	}
}                  */


int xx(seg a, int x, int y){
	if ((point(x - a.x1, y - a.y1) * point(a.x2 - a.x1, a.y2 - a.y1)) == 0)
		return 1;
	return (val(a, x) < y) ? 0 : 2;
}

int cnt[3];
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, n, l, k, t, i, j;
	scanf("%d%d", &a, &b);
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &l);
		l++;
		for (j = 0; j < l; j++)
			scanf("%d%d", &x[i][j],&y[i][j]);
		for (j = 0; j < l - 1; j++){
			seg tmp;
			tmp.x1 = x[i][j];
			tmp.y1 = y[i][j];
			tmp.x2 = x[i][j + 1];
			tmp.y2 = y[i][j + 1];
			tmp.num = i + 1;
			g[i].pb(tmp);
		}
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			k = 0;
			if (i == j)
				continue;
			cnt[0] = cnt[1] = cnt[2] = 0;
			for (t = 0; t < (int)g[j].size() + 1; t++){
				while (1){

	//				cerr << t << " " << k<< g[i][k].x2 << " " << x[j][t] << endl;
					if (g[i][k].x2 < x[j][t]){
						k++;
						continue;
					}
				//	cerr << t << " " << k << " " << xx(g[i][k], x[j][t], y[j][t]) << endl;
					cnt[xx(g[i][k], x[j][t], y[j][t])]++;
					break;
				}
			}
			if (cnt[0] && cnt[2]){
				cout << "No" << endl;
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		} 
	}
	cout << "Yes";
	return 0;
}