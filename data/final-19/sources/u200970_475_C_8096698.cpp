#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int MX = 1000;

int ddown[MX][MX];
int dright[MX][MX];

int N, M;
bool field[MX][MX];
bool nfield[MX][MX];
int ans;
int r = -1, c;

bool ok(int H, int W)
{
	if (H <= 0 || W <= 0)
		return false;

	if (r < 0)
	{
	jij(N, M) if (field[i][j])
	{
		r = i;
		c = j;
		goto npart;
	}
	}
	npart:

//	jij(N, M)
//	{
		#define nfield(i, j) (field[i][j] && dright[i][j] >= W && ddown[i][j] >= H)
		//[i][j] = field[i][j] && dright[i][j] >= W && ddown[i][j] >= H;
//	}
	jij(N, M)
	{
		//printf("%d %d   %d %d\n", W, H, i, j);
		if (i < N-1 && j < M-1 && nfield(i, j) && nfield(i+1, j) && nfield(i, j+1))
		{
			return false;
		}
		int a = i;
		int b = j;
		if (nfield(a, b) && !((a > 0 && nfield(a-1, b)) || (b > 0 && nfield(a, b-1))) && (a != r || b != c))
			return false;
	}
	ans = min(ans, W * H);
	return true;
}

int main()
{
	rint(N), rint(M);

	ji(N)
	{
		char buf[1001];
		scanf("%s", buf);
		jj(M)
			//field[i][j] = !((j == N-1 && i == 0) || (j == 0 && i == N-1));
			field[i][j] = buf[j] == 'X';
	}

	for (int i = N-1; i >= 0; i--)
	{
		for (int j = M-1; j >= 0; j--)
		{
			if (!field[i][j])
			{
				ddown[i][j] = dright[i][j] = 5000;
				continue;
			}
			if (i == N-1 || !field[i+1][j])
				ddown[i][j] = 1;
			else
				ddown[i][j] = ddown[i+1][j] + 1;
			if (j == M-1 || !field[i][j+1])
				dright[i][j] = 1;
			else
				dright[i][j] = dright[i][j+1] + 1;
		}
	}

	int maxH = N;
	int maxW = M;
	jij(N, M)
	{
		if (i == 0 || !field[i-1][j])
		{
			maxH = min(maxH, ddown[i][j]);
		}
		if (j == 0 || !field[i][j-1])
		{
			maxW = min(maxW, dright[i][j]);
		}
	}

	ans = maxW * maxH + 1;
	bool wasOK;
	for (int i = 1; i <= maxH; i++) if (ok(i, maxW)) break;
	for (int i = 1; i <= maxW; i++) if (ok(maxH, i)) break;

	printf("%d\n", ans == maxW * maxH + 1 ? -1 : ans);
}