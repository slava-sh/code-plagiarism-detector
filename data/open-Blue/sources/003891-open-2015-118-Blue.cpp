#define INPUT 1
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
		printf("%f seconds\n", (en - st) / (double) CLOCKS_PER_SEC);
	#endif
	
	return 0;
}

const int N = 1e5 + 7;
int n, l;

string s;
VI subs[1007][1007];

const int AMN = 3;
const ll MODS[AMN] = {1000000003, 1000000007, 1000000009};
const ll PS[AMN] = {5, 7, 11};
ll KS[AMN][N];
ll HS[AMN][N];

inline bool check(int i, VI &ds, int len)
{
	return i == n || (i + len <= n && subs[i][len] == ds);
}

VI s1, s2;
int l1, l2;
bool check(int i)
{
	return i == n || (check(i, s1, l1) && check(i + l1)) || (check(i, s2, l2) && check(i + l2));
}

void run()
{
	scanf("%d", &l);
	cin >> s;
	n = s.length();
	
	if (l >= n)
	{
		printf("%d\n", 1);
		cout << s << endl;
		return;
	}
	
	
	for (int h = 0; h < AMN; h++)
		KS[h][0] = 1;
	for (int h = 0; h < AMN; h++)
		for (int i = 1; i <= n; i++)
			KS[h][i] = (KS[h][i - 1] * PS[h]) % MODS[h];
	
	for (int h = 0; h < AMN; h++)
		HS[h][0] = (s[0] - 'a' + 1);
	for (int h = 0; h < AMN; h++)
		for (int i = 1; i < n; i++)
			HS[h][i] = (HS[h][i - 1] + (s[i] - 'a' + 1) * KS[h][i]) % MODS[h];
	
	for (int i = 0; i < n; i++)
		for (int j = 1; i + j <= n; j++)
		{
			subs[i][j].resize(AMN);
			for (int h = 0; h < AMN; h++)
				subs[i][j][h] = (HS[h][i + j - 1] - (i == 0 ? 0 : HS[h][i - 1]) + MODS[h]) % MODS[h] * KS[h][n - i] % MODS[h];
		}
	
	for (int l1 = 1; l1 <= l; l1++)
	{
		VI s1 = subs[0][l1];
		for (int i = 0; i <= n; i += l1)
			if (i == n)
			{
				printf("%d\n", 1);
				cout << s.substr(0, l1) << endl;
				return;
			}
			else if (!check(i, s1, l1))
				break;
	}
	
	for (l1 = 1; l1 <= l; l1++)
	{
		s1 = subs[0][l1];
		int ist = 0;
		while (check(ist, s1, l1))
			ist += l1;
		for (l2 = 1; l2 <= l && (l1 + l2 <= n); l2++)
		{
			s2 = subs[ist][l2];
			if (check(0))
			{
				printf("%d\n", 2);
				cout << s.substr(0, l1) << endl;
				cout << s.substr(ist, l2) << endl;
				return;
			}
		}
	}
	
	printf("%d\n", 3);
	cout << "a" << endl;
	cout << "b" << endl;
	cout << "c" << endl;
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/