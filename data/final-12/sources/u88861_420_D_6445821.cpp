#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int N = 2000100;
int n, m, p[N], a[N], pos[N], cur;
bool occ[N];
namespace BIT {
	int c[N], n, tlv;
	inline void pre(int _n) {
		n = _n;
		for (tlv=0; (1<<tlv)<n; ++tlv);
	}
	inline void A(int w, int x) {
		for (; w<=n; w+=w&-w)
			c[w] += x;
	}
	inline int Q(int w) {
		int sum = 0;
		for (; w; w-=w&-w)
			sum += c[w];
		return sum;
	}
	inline int find(int key) {// last sum < key
		int ans = 0, to;
		for (int i=tlv; i>=0; --i) {
			to = ans|(1 << i);
			if (to <= n && c[to] < key)
				ans = to, key -= c[to];
		}
		return ans;
	}
}
int main() {
	R(n); R(m);
	cur = 1000005;
	BIT::pre(cur + n);
	for (int i=1; i<=n; ++i) {
		p[i+cur-1] = i;
		BIT::A(i+cur-1, 1);
	}
	int x, y;
	for (int i=1; i<=m; ++i) {
		R(x); R(y);
		y = BIT::find(y) + 1;
		--cur;
		BIT::A(y, -1);
		BIT::A(cur, 1);
		p[cur] = p[y];
		if (a[p[cur]] && a[p[cur]] != x) {
			puts("-1");
			return 0;
		}
		if (pos[x] &&  pos[x] != p[cur]) {
			puts("-1");
			return 0;
		}
		pos[x] = p[cur];
		a[p[cur]] = x;
		occ[x] = 1;
	}
	int co = 1;
	for (int i=1; i<=n; ++i) if (!a[i]) {
		for (; occ[co]; ++co);
		a[i] = co;
		++co;
	}
	for (int i=1; i<=n; ++i)
		printf("%d ", a[i]);
	return 0;
}
