#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#define ll long long

using namespace std;

//const int N = 1000001;
const int INF = 1000*1000*1000;
const int NOTHING = INF;

struct tree{
	ll sum;
};

tree rtree[2][1000000];
int tk=1, n;

void relax(int tr, int i) {
	tree & p = rtree[tr][i];
	tree & l = rtree[tr][i*2];
	tree & r = rtree[tr][i*2+1];

	p.sum = l.sum + r.sum;
}

void init(int tr) {
	while (tk<n) tk*=2;

	for (int i=1; i<=tk+10; ++i) {
		tree & t = rtree[tr][i+tk-1];
		t.sum = 0;
	}

	for (int i=tk-1; i>=1; --i) relax(tr, i);
}

void complete_set(int tr, int i, ll x) {
	tree & t = rtree[tr][i];
	t.sum = x;
}

void _set(int trn, int i, int tl, int tr, int pos, ll d) {
	if (pos<tl || tr<pos) return;
	if (pos<=tl && tr<=pos) {
		complete_set(trn, i, d);
		return;
	}

	int m = (tl+tr)/2;
	_set(trn, 2*i,   tl,  m,  pos, d);
	_set(trn, 2*i+1, m+1, tr, pos, d);
	relax(trn, i);
}

ll _get(int trn, int i, int tl, int tr, int ql, int qr) {
	ll ans = 0;

	if (qr<tl || tr<ql) return 0ll;
	if (ql<=tl && tr<=qr) {
		return rtree[trn][i].sum;
	}

	int m = (tl+tr)/2;
	ans += _get(trn, 2*i,   tl,  m,  ql, qr);
	ans += _get(trn, 2*i+1, m+1, tr, ql, qr);
	relax(trn, i);
		
	return ans;
}

void set(int trn, int pos, int t) {
	_set(trn, 1,1,tk,pos,(ll)t);
}

ll get(int ql, int qr) {
	if (ql%2==1) {
		int _qr = ((qr%2)==1)? ((qr+1)/2) : (qr/2);
		ll a1 = _get(0, 1, 1,tk,(ql+1)/2, _qr);
		_qr = ((qr%2)==1)? ((qr)/2) : (qr/2);
		ll a2 = _get(1, 1, 1,tk,(ql+1)/2, _qr);
		return a1-a2;
	} else {
		int _qr = ((qr%2)==1)? ((qr)/2) : (qr/2);
		ll a2 = _get(1, 1, 1,tk, ql/2, _qr);
		_qr = ((qr%2)==1)? ((qr+1)/2) : (qr/2);
		ll a1 = _get(0, 1, 1,tk,(ql+2)/2, _qr);
		return a2-a1;
	}
}

int m;

int main() {
	freopen("signchange.in", "r", stdin);
	freopen("signchange.out", "w", stdout);

	scanf("%d", &n);
	init(0); init(1);

	for (int i=1; i<=n; ++i) {
		int a; scanf("%d", &a);
		if (i%2==1)
			set(0, (i+1)/2, a);
		else 
			set(1, (i)/2, a);
	}

	scanf("%d", &m);
	int act; int a, b;
	for (int i=0; i<m; ++i) {
		cin >> act >> a >> b;
		if (act==0)
			if (a%2==1)
				set(0, (a+1)/2, b);
			else 
				set(1, (a)/2, b);
		else
			printf("%lld\n", get(a,b) );
	}

	return 0;
}
