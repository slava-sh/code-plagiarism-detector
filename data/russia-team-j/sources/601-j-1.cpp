#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <set>
using namespace std;

#define TASK "travel"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
const int maxn = 510;

const int X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0};
const char go[] = {'E', 'W', 'S', 'N'};

int w, h, n;
int Sx, Sy, Ax1, Ay1, Ax2 = -1, Ay2 = -1;
int A[maxn][maxn];
int use1[maxn][maxn];
int use2[maxn][maxn];
int p2[maxn][maxn];
int p[maxn][maxn];

vector <char> Ans1, Ans2;


void f1() {
     int Vx = Sx, Vy = Sy;
	 //cerr << Vx << " " << Vy << endl;
	 vector <pair<int, int> > Q;
	 Q.push_back(make_pair(Vx, Vy));
	 int b = 0;
	 use1[Vx][Vy] = 1;
	 while (b < Q.size()) {
		 int Ux = Q[b].first, Uy = Q[b].second;
		 ++b;
		 cerr << Ux << " " << Uy << endl;
		 for (int i = 0; i < 4; ++i) {
		     if (A[Ux + X[i]][Uy + Y[i]] != 0 && use1[Ux + X[i]][Uy + Y[i]] == 0) {
			     use1[Ux + X[i]][Uy + Y[i]]  = use1[Ux][Uy] + 1;
				 Q.push_back(make_pair(Ux + X[i], Uy + Y[i]));
				 p[Ux + X[i]][Uy + Y[i]] = i;
				 if (A[Ux + X[i]][Uy + Y[i]] == 1) {
				     Ax1 = Ux + X[i];
					 Ay1 = Uy + Y[i];
					 return;
				 }
			 }
		 }

	 }
}

struct Pt{
    int x, y, fl;
	Pt(){}
	Pt (int _x, int _y, int _fl) {
	    x = _x;
		y = _y;
		fl = _fl;
	}
};

void f2() {
     int Vx = Sx, Vy = Sy;
	 vector <Pt> Q;
	 Q.push_back(Pt(Vx, Vy, 0));
	 int b = 0;
	 use2[Vx][Vy] = 1;
	 while (b < Q.size()) {
		 int Ux = Q[b].x, Uy = Q[b].y;
		 if (A[Ux][Uy] == 3 && Q[b].fl == 0) {
		     ++b;
			 use2[Ux][Uy]++;
			 Q.push_back(Pt(Ux, Uy, 1));
			 continue;
		 }
		 ++b;
		 for (int i = 0; i < 4; ++i) {
		     if (A[Ux + X[i]][Uy + Y[i]] != 0 && use2[Ux + X[i]][Uy + Y[i]] == 0) {
			     use2[Ux + X[i]][Uy + Y[i]]  = use2[Ux][Uy] + 1;
				 Q.push_back(Pt(Ux + X[i], Uy + Y[i], 0));
				 p2[Ux + X[i]][Uy + Y[i]] = i;
				 if (A[Ux + X[i]][Uy + Y[i]] == 2) {
				     Ax2 = Ux + X[i];
					 Ay2 = Uy + Y[i];
					 return;
				 }
			 }
		 }

	 }
}


void res1() {
	int X1 = Ax1, Y1 = Ay1;
	//cerr << X1 << " " << Y1 << endl;
	while (X1 != Sx || Y1 != Sy) {
		Ans1.push_back(go[p[X1][Y1]]);
		X1 += (-X[p[X1][Y1]]);
		Y1 += (-Y[p[X1][Y1]]);
		//cerr << X1 << " " << Y1 << endl;
	}
	reverse(Ans1.begin(), Ans1.end());
	int cur = n - 1;
	while (cur != 0) {
		//cerr << cur << " " << Ax1 << " " << Ay1 << endl;
	    for (int i = 0; i < 4; ++i) {
		    if (A[Ax1][Ay1] == 3 && A[Ax1 + X[i]][Ay1 + Y[i]] > 0 &&  A[Ax1 + X[i]][Ay1 + Y[i]] < 3) {
				Ans1.push_back(go[i]);
				Ax1 += X[i];
				Ay1 += Y[i];
				--cur;
				break;
			}
			if (A[Ax1][Ay1] < 3 && A[Ax1 + X[i]][Ay1 + Y[i]] > 0) {
				Ans1.push_back(go[i]);
				Ax1 += X[i];
				Ay1 += Y[i];
				break;
			}
		}
	}
}

void res2() {
	cerr << Ax2 << " " << Ay2 << endl; 
	int cur = n;
	int X1 = Ax2, Y1 = Ay2;
	while (X1 != Sx || Y1 != Sy) {
		Ans2.push_back(go[p[X1][Y1]]);
		if (A[X1][Y1] < 3) --cur;
		X1 += (-X[p[X1][Y1]]);
		Y1 += (-Y[p[X1][Y1]]);
		cerr << X1 << " " << Y1 << " " << cur << endl;
	}
	reverse(Ans2.begin(), Ans2.end());
	while (cur != 0) {
		cerr << cur << Ax2 << " " << Ay2 << endl;
	    for (int i = 0; i < 4; ++i) {
		    if (A[Ax2 + X[i]][Ay2 + Y[i]] == 2) {
				Ans2.push_back(go[i]);
				Ax2 += X[i];
				Ay2 += Y[i];
				--cur;
				break;
			}
		}
	}
}


int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	cin >> h >> w >> n;
	for (int i = 1; i <= w; ++i) {
	    for (int j = 1; j <=h; ++j) {
		    char c;
			cin >> c;
			if (c == 'T') {
			    A[i][j] = 1;
			}
			else {
			    A[i][j] = 3;
			}
			if(c == 'V') {
				cerr << "V" << endl;
			    Sx = i;
				Sy = j;
			}
		}
	}
	f1();
	for (int i = 1; i <= w; ++i) {
	    for (int j = 1; j <= h; ++j) {
		     if (A[i][j] == 1) {
			     for (int g = 0; g < 4; ++g) {
				     if (A[i + X[g]][j + Y[g]] == 1 || A[i + X[g]][j + Y[g]] == 2) {
					     A[i][j] = 2;
					 }
				 }
			 }
		}
	}
	f2();
	cerr << "ok";
	res1();
	if (Ax2 != -1) res2();
	if (Ans1.size() < Ans2.size() || Ax2 == -1) {
	    for (int i = 0; i < Ans1.size(); ++i) {
		    cout << Ans1[i];
		}
	}
	else {
	    for (int i = 0; i < Ans2.size(); ++i) {
		    cout << Ans2[i];
		}
	}
}