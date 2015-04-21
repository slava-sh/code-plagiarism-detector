#define INPUT 0
#define DEBUG 1
#define OUTPUT 0

#include <bits/stdc++.h>

using namespace std;

bool debug = 0;

#define ll long long
#define ull unsigned long long 
#define uint unsigned int
#define VI vector<int>
#define PII pair<int, int>
#define dbg(x) if (debug) cerr << #x << " = " << (x) << endl;

const int INF = 2e9 + 7;
const ll INFL = 8e18 + 7;
const int MOD = 1e9 + 7;

void run();

int main()
{
	#ifdef LOCAL
		if (DEBUG)
			debug = 1;
		if (INPUT)
			freopen("input.txt", "r", stdin);
		if (OUTPUT)
			freopen("output.txt", "w", stdout);
	#endif
	
	int st = clock();
	run();
	int en = clock();
	
	#ifdef LOCAL
		freopen("CON", "w", stdout);
		printf("%1.3f seconds\n", (en - st) / (double) CLOCKS_PER_SEC);
	#endif
	
	return 0;
}

const int N = 6000 + 7;
int n;

void runtime()
{
	VI vi;
	vi.at(7);
	cout << 1 / 0 << endl;
}

void handle(char x)
{
	printf("%c\n", x);
	fflush(stdout);
	char c;
	do
		scanf("%c", &c);
	while (c != 'N' && c != 'Y' && c != 'E');
	if (c == 'E')
		runtime();
	if (c == 'Y')
		exit(0);
}

bool need[N][N], used[N][N];

const char ch[4] = {'U', 'R', 'D', 'L'};
void run()
{
	/*
	int i = 0, k = 1;
	for (int j = 0; j < 10000; j++)
	{
		for (int j = 0; j < k; j++)
			handle(ch[i]);
		if (i % 2 == 1)
			k++;
		i = (i + 1) % 4;
	}
	//*/
	
	const int S = 4;
	for (int i = 1; i <= S; i++)
		for (int j = S / i; j >= 0; j--)
			for (int q = 0; q < i; q++)
				need[j][q] = 1;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (debug) printf("%c", '0' + need[i][j]);
		if (debug) printf("\n");
	}
	
	int amn = 0;
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			amn += need[i][j];
	dbg(amn);
	dbg(need[0][2]);
	
	for (int i = 0, j = 0; need[i][j]; )
	{
		for ( ; need[i][j]; j++)
		{
			used[i][j] = 1;
			handle('D');
		}
		j--;
		handle('R');
		i++;
		for ( ; j >= 0 && !used[i][j]; j--)
		{
			used[i][j] = 1;
			handle('U');
		}
		if (j == -1 || used[i][j])
			j++;
		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				if (debug) printf("%c", '0' + used[i][j]);
			if (debug) printf("\n");
		}
		if (debug) printf("\n");
		
		for ( ; need[i][j]; i++)
		{
			used[i][j] = 1;
			handle('R');
		}
		i--;
		handle('D');
		j++;
		for ( ; i >= 0 && !used[i][j]; i--)
		{
			used[i][j] = 1;
			handle('R');
		}
		if (i == -1 || used[i][j])
			i++;
		j++;
		
		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				if (debug) printf("%c", '0' + used[i][j]);
			if (debug) printf("\n");
		}
		if (debug) printf("\n");
	}
	runtime();
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/