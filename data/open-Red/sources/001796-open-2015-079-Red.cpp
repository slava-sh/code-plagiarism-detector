#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30;
const ld eps = 1e-9;

struct edge{
	int v, t, pos;
	bool was;
};

struct qpos{
	int u, v, t, step;
};

queue <qpos> q;

vector <edge> V[130000];

int N, M, D, Q;

void get_z(qpos &z, int a, int i){
	z.u = a; z.v = V[a][i].v; z.t = V[a][i].t;
}

void outp(qpos z){
	printf("%d %d %d %d\n", z.u, z.v, z.t, z.step);
}

int solve(int a, int b){
	qpos z;
	forn(i, V[a].size()){
		get_z(z, a, i); z.step = 0;
		q.push(z); 
		V[a][i].was = true; 
	}

	while (!q.empty()){
		z = q.front();

		//outp(z);

		if (z.u == b) return z.step;

		qpos nz;
		forn(i, V[z.v].size())
			if (abs(z.t - V[z.v][i].t) <= D && !V[z.v][i].was){
				get_z(nz, z.v, i); nz.step = z.step + 1;
				q.push(nz);
				V[z.v][i].was = true; 
			}
	
	q.pop();
	}

	return -1;
}

void restore(){
	while(!q.empty()) q.pop();

	forn(i, N + 1){
		forn(j, V[i].size()) V[i][j].was = false;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d%d%d", &N, &M, &D);
	
	int u, v, t;
	edge e;
	forn(i, M){
		scanf("%d%d%d", &u, &v, &t);
		e.v = v; e.t = t; e.was = false;
		e.pos = V[v].size();

		V[u].pb(e);
		
		e.v = u; e.pos = ((int)V[u].size()) - 1;
		V[v].pb(e);
	}

	scanf("%d", &Q);
	int a, b;
	forn(i, Q){
		scanf("%d%d", &a, &b);
		printf("%d\n", solve(a, b));
		restore();
	}
	return 0;
}

