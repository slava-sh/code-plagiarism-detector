#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define NAME "numbers"

//#define DEBUG

#ifdef DEBUG
#define eprintf(...) printf(__VA_ARGS__), fflush(stdout)
#else
#define eprintf(...)
#endif

typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define frs first
#define scn second
#define mp make_pair
#define pb push_back
#define ins insert

typedef pair<int, int> pii;

int const N = 1000 + 10;

int order[N];

int n;
int co[N];
int codes[N][N];

char s[20], s1[20], s2[20];

pii country[N];

inline int find_c(int num)
{
	int l(-1);
	int r(n);
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (country[m].frs <= num)
			l = m;
		else
			r = m;
	}
	if (country[l].frs != num)
		return -1;
	return country[l].scn;
}

inline int find_r(int c, int num)
{
	int l(-1);
	int r(co[c]);
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (codes[c][m] <= num)
			l = m;
		else
			r = m;
	}
	if (codes[c][l] != num)
		return -1;
	return num;
}

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d", &n);
	for (int i(0); i < n; ++i)
	{
		order[i] = i;
		int c;
		scanf("%d%d", &c, &co[i]);
		country[i] = mp(c, i);
		for (int j(0); j < co[i]; ++j)
			scanf("%d", &codes[i][j]);
		sort(codes[i], codes[i] + co[i]);
	}
	sort(country, country + n);

	#ifdef DEBUG
	printf("! Country:\n");
	for (int i(0); i < n; ++i)
	{
		printf("!   %d --> %d\n", country[i].frs, country[i].scn);
		for (int j(0); j < co[i]; ++j)
			printf("!     %d\n", codes[i][j]);
	}
	#endif

	int m;
	scanf("%d", &m);
	while (m --> 0)
	{
		eprintf("===============================================================================================\n");
		scanf(" %s", s);
		int k = strlen(s);
		bool flag = false;

		for (int cl(1); !flag && cl <= 3; ++cl)
		{
			memset(s1, 0, sizeof(s1));
			strncpy(s1, s, cl);
			int num;
			sscanf(s1, "%d", &num); 
			int id = find_c(num);

			eprintf("! Country: code %d --> %d | %c\n", num, id, s[cl]);
			if (id == -1 || s[cl] == '0')
				continue;

			for (int rl(3); !flag && rl <= 5; ++rl)
			{
				memset(s2, 0, sizeof(s2));
				strncpy(s2, s + cl, rl);
				int region;
				sscanf(s2, "%d", &region);
				region = find_r(id, region);
				
				eprintf("!   Region: %d | %c\n", region, s[cl + rl]);
				if (region == -1 || s[cl + rl] == '0')
					continue;

				flag = true;
				printf("+%d(%d)", num, region);
				switch (k - cl - rl)
				{
					case 3:
						printf("%s\n", s + cl + rl);
						break;
					case 4:
						memset(s2, 0, sizeof(s2));
						strncpy(s2, s + cl + rl, 2);
						printf("%s-%s\n", s2, s+ cl + rl + 2);
						break;
					case 5:
						memset(s2, 0, sizeof(s2));
						strncpy(s2, s + cl + rl, 3);
						printf("%s-%s\n", s2, s + cl + rl + 3);
						break;
					case 6:
						memset(s1, 0, sizeof(s1));
						memset(s2, 0, sizeof(s2));
						strncpy(s1, s + cl + rl, 2);
						strncpy(s2, s + cl + rl + 2, 2);
						printf("%s-%s-%s\n", s1, s2, s + cl + rl + 2 + 2);
						break;
					case 7:
						memset(s1, 0, sizeof(s1));
						memset(s2, 0, sizeof(s2));
						strncpy(s1, s + cl + rl, 3);
						strncpy(s2, s + cl + rl + 3, 2);
						printf("%s-%s-%s\n", s1, s2, s + cl + rl + 3 + 2);
						break;
				}
			}

		}

		if (!flag)
			printf("Incorrect\n");
	}

	return 0;
}