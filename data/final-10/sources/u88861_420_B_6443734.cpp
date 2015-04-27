#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
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
const int N = 100005;
int n, m;
pair<int, int> a[N], b[N];
char op[N];
int firsta[N], sta[N];
set<int> pi, po;
vector<int> p;
int main() {
	R(n); R(m);
	for (int i=1; i<=m; ++i) {
		scanf("%s", op);
		if (op[0] == '+')
			a[i].fir = 1; else
			a[i].fir = -1;
		R(a[i].sec);
		if (!firsta[a[i].sec])
			firsta[a[i].sec] = a[i].fir;
	}
	
	int incnt = 0;
	for (int i=1; i<=n; ++i) {
		sta[i] = -firsta[i];
		if (sta[i] == 1) pi.insert(i), ++incnt;
		if (sta[i] == -1) po.insert(i);
	}
	
	if (pi.size() > 0)
		po.clear();
	for (int i=1; i<=m; ++i) {
		if (a[i].fir == 1) {
			sta[a[i].sec] = 1;
			++incnt;
			if (po.count(a[i].sec))
				pi.insert(a[i].sec);
			po.clear();
		}
		else {
			sta[a[i].sec] = -1;
			--incnt;
			if (pi.count(a[i].sec)) {
				if (incnt <= 0)
					po.insert(a[i].sec);
				pi.erase(a[i].sec);
			}
		}
	}
	
	for (int i=1; i<=n; ++i)
		if (!sta[i] || pi.count(i) || po.count(i))
			p.pb(i);
	
	printf("%d\n", p.size());
	
	for (int i=0; i<p.size(); ++i)
		printf("%d ", p[i]);
	return 0;
}
