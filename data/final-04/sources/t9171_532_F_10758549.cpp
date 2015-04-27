#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 200005

using namespace std;

typedef long long ll;

struct num {
	static const int MA = 1e9 + 7, MB = 1e9 + 9;

	int a, b;

	num() { }
	num( int x ) : a(x), b(x) { }
	num( int _a, int _b ) : a(_a), b(_b) { }

	num operator + ( const num &x ) const { return num((a + x.a) % MA, (b + x.b) % MB); }
	num operator - ( const num &x ) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
	num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
	num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
	bool operator == ( const num &x ) const { return a == x.a && b == x.b; }

	explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};


int main ()
{
	num P = num(239017);
	static num Ppow[MAXN];
	Ppow[0] = num(1);
	int i;
	for (i = 1; i < MAXN; i++) Ppow[i] = Ppow[i-1] * P;
	
	int N, M;
	scanf("%d %d",&N,&M);
	static char a[MAXN];
	static char b[MAXN];
	scanf("\n%s",a);
	scanf("\n%s",b);

	static int preva[MAXN];
	static int prevb[MAXN];
	static int nexta[MAXN];
	static int prev[256];

	for (i = 'a'; i <= 'z'; i++) prev[i] = -1;
	for (i = 0; i < N; i++)
	{
		if (prev[a[i]] == -1) preva[i] = 0;
		else preva[i] = i - prev[a[i]];
		prev[a[i]] = i;
	}

	for (i = 'a'; i <= 'z'; i++) prev[i] = -1;
	for (i = 0; i < M; i++)
	{
		if (prev[b[i]] == -1) prevb[i] = 0;
		else prevb[i] = i - prev[b[i]];
		prev[b[i]] = i;
	}

	for (i = 'a'; i <= 'z'; i++) prev[i] = -1;
	for (i = N-1; i >= 0; i--)
	{
		if (prev[a[i]] == -1) nexta[i] = -1;
		else nexta[i] = prev[a[i]];
		prev[a[i]] = i;
	}

	num ans = num(0);
	for (i = 0; i < M; i++) ans = ans * P + num(prevb[i]);

	int resc = 0;
	static int res[MAXN];

	static int curFirst[256];
	for (i = 'a'; i <= 'z'; i++) curFirst[i] = -1;

	num cur = num(0);
	for (i = 0; i < M; i++)
	{
		cur = cur * P + num(preva[i]);
	}

	for (i = 0; i < N; i++)
	{
		if (preva[i] == 0) curFirst[a[i]] = i;
	}

	static char perm[256];

	for (i = M; i <= N; i++)
	{
		int first = i - M;
		if (cur == ans)
		{
			int j;
			for (j = 'a'; j <= 'z'; j++) perm[j] = 0;
			char flag = 1;

			//printf("%d\n",first+1);

			for (j = 'a'; j <= 'z'; j++)
			{
				//if (curFirst[j] != -1) printf("%c: %d\n",j,curFirst[j]);
				if ((curFirst[j] != -1) && (curFirst[j] < i))
				{
					char from = a[curFirst[j]];
					char to = b[curFirst[j] - first];
					//printf("%c %c\n",from,to);
					if (!((perm[from] == to) && (perm[to] == from)))
					{
						if ((perm[from] == 0) && (perm[to] == 0))
						{
							perm[from] = to;
							perm[to] = from;
						}
						else
						{
							flag = 0;
							break;
						}
					}
				}
			}
			if (flag)
			{
				res[resc] = first;
				resc++;
			}
		}
		if (i == N) break;
		curFirst[a[first]] = nexta[first];
		if (nexta[first] < i)
		{
			cur = cur - Ppow[i - nexta[first] - 1] * num(preva[nexta[first]]);
		}
		if (nexta[first] != -1)
		{
			preva[nexta[first]] = 0;
		}

		cur = cur * P + num(preva[i]);
	}

	printf("%d\n",resc);
	for (i = 0; i < resc; i++)
	{
		if (i) printf(" ");
		printf("%d",res[i] + 1);
	}
	printf("\n");

	return 0;
}
