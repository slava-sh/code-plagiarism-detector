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

const int N = 1e5 + 7;
int n;

void handle(char x)
{
	printf("%c\n", x);
	fflush(stdout);
	char c;
	do
		scanf("%c", &c);
	while (c != 'N' && c != 'Y' && c != 'E');
	if (c != 'N')
		exit(0);
}

void run()
{
	//6007, 6011;
	while (1)
	{
		for (int i = 0; i < 6007; i++)
		{
			handle('U');
			handle('R');
		}
		for (int i = 0; i < 4; i++)
			handle('R');
	}
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/