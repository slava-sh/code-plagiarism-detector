#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct F {
	bool operator<(const F& f) const {
		return a*f.b < b*f.a;
	}
	bool operator==(const F& f) const {
		return a*f.b == b*f.a;
	}
	bool operator<(int i) const {
		return a < b*i;
	}
	bool operator>(int i) const {
		return a > b*i;
	}
	ll a,b;
};
struct E {
	F t;
	bool add;
	bool operator<(const E& e) const {
		if (t==e.t) return add > e.add;
		return t < e.t;
	}
};
int HL,HR,N;
const int H = 100;
const int W = 100000;

const int MN = 1024;

struct I {
	int a,b,v;
	bool operator<(const I& i) const {
		return a<i.a;
	}
};
I is[2][MN];
int ns[2];

int test(F f) {
	int dy = HL;
	bool up = 0;
	int as[2] = {};
	if (f.a < 0) {
		f.a *= -1;
	} else {
		up = 1;
		dy = H - HL;
	}

	int res=0;
	while(1) {
//		cout<<"k "<<up<<' '<<as[0]<<' '<<as[1]<<'\n';
		F g = {f.b * dy, f.a};
//		cout<<(float)g.a/g.b<<'\n';
		if (!(g < W)) return res;
		while(as[up]<ns[up] && g > is[up][as[up]].b) {
			++as[up];
		}
		if (as[up]==ns[up]) return -1;
//		cout<<"trying "<<g.a<<' '<<g.b<<" ; "<<is[up][as[up]].b<<'\n';
		if (g < is[up][as[up]].a) return -1;
		res += is[up][as[up]].v;
		++as[up];

		up ^= 1;
		dy += H;
	}
}

int main() {
	cin>>HL>>HR>>N;
	for(int i=0; i<N; ++i) {
		int v,a,b;
		char s;
		cin>>v>>s>>a>>b;
		if (s=='T') is[1][ns[1]++] = (I){a,b,v};
		else is[0][ns[0]++] = (I){a,b,v};
	}
	sort(is[0],is[0]+ns[0]);
	sort(is[1],is[1]+ns[1]);

	int r=0;
	for(int i=-N; i<=N; ++i) {
		int dy = HR-HL + 2*i*H;
		F f = {dy, W};
		int rr = test(f);
//		cout<<"asd "<<i<<' '<<rr<<'\n';
		r = max(r, rr);
	}
	for(int i=-N; i<=N; ++i) {
		int dy = -HR-HL + 2*i*H;
		F f = {dy, W};
		int rr = test(f);
//		cout<<"asd2 "<<i<<' '<<rr<<" ; "<<dy<<'\n';
		r = max(r, rr);
	}
	cout<<r<<'\n';
}
