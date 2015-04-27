#include <iostream>
#include <cassert>
#include <string>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long int64;
typedef long double ext;

const int inf = 1000 * 1000 * 1000;
const ext eps = 1e-7;

using namespace std;

const int w = 100000;
const int h = 100;
const int maxn = 1000;
const int maxr = 5000;

struct mirror{
	int v, a, b;
	char c;
	void read(){
		scanf("%d %c %d %d", &v, &c, &a, &b);
	};
};

bool inside(ext a, mirror m){
	return (a - m.a >= -eps) && (a - m.b <= eps);
}

int n;
int hl, hr;
mirror m[maxn];
bool was[maxn];
int ans;

void calc(ext vy){
	ext a, b, c, d, u;
	for (int i = 0; i < n; i++)
		was[i] = false;
	ext x = 0;
	ext y = hl;
	int sum = 0;
	for(;;){
		int i;
		a = vy;
		b = -w;
		c = -(a * x + b * y);
		d = -c / a;
		u = -(c + b * h) / a;
		for (i = 0; i < n; i++){
			if (was[i])
				continue;
			if ((m[i].c == 'F') && inside(d, m[i])){
				x = d;
				y = 0;
				break;
			}
			if ((m[i].c == 'T') && inside(u, m[i])){
				x = u;
				y = h;
				break;
			}
		}
		if (i == n)
			break;
		was[i] = true;
		sum += m[i].v;
		vy *= -1.0;
	}
	a = vy;
	b = -w;
	c = -(a * x + b * y);
	if (fabs(a * w + b * hr + c) <= eps){
		ans = max(ans, sum);
		//cerr << sum << "\n";
	}
}

int main()
{
	#ifdef HOME
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
	#endif
	scanf("%d %d %d", &hl, &hr, &n);
	for (int i = 0; i < n; i++)
		m[i].read();
	ans = 0;
	for (int i = 1; i <= maxr; i++){
		ext y;
		if (i % 2 == 1)
			y = hl + h * (i - 1) + hr;
		else
			y = hl + h * (i - 1) + h - hr;
		calc(-y);
		if (i % 2 == 1)
			y = h - hl + h * (i - 1) + h - hr;
		else
			y = h - hl + h * (i - 1) + hr;
		calc(y);
	}
	printf("%d", ans);
    return 0;
}
