#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 100;
int H1, H2, N;
bool used[MAX];

struct rec
{
	int score, a, b;
	char top;
} in[MAX];

const double EPS = 1e-9;

int main()
{
	scanf("%d%d%d", &H1, &H2, &N);
	REP(i, N)
	{
		scanf("%d %c%d%d", &in[i].score, &in[i].top, &in[i].a, &in[i].b);
		in[i].top = in[i].top=='T';
	}

	int result = 0;
	REP(step, 2)
	{
		FOR(layers, 1, 205)
		{
			double d = 100000.0/((layers-1)*100+H1+(layers%2==0?100-H2:H2)), x = 0.0;
			int score = 0;
			bool ok = true;
			memset(used, 0, sizeof(used));
			REP(i, layers)
			{
				x += (i?100:H1)*d;
				int mir = -1;
				REP(j, N)
					if (in[j].top == i%2 && in[j].a-EPS <= x && x <= in[j].b+EPS)
					{
						mir = j;
						break;
					}
				if (mir == -1 || used[mir]) { ok = false; break; }
				used[mir] = true;
				score += in[mir].score;
			}
			if (ok)
				chmax(result, score);
		}

		H1 = 100-H1;
		H2 = 100-H2;
		REP(i, N) in[i].top = !in[i].top;
	}
	printf("%d\n", result);

	return 0;
}