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

uint anssize = N;
set<string> ans;
void go(int i, set<string> ss)
{
	if (i == n)
	{
		if (ss.size() < anssize)
		{
			anssize = ss.size();
			ans = ss;
		}
		return;
	}
	for (int j = 1; j <= l && i + j <= n; j++)
	{
		set<string> ns = ss;
		ns.insert(s.substr(i, j));
		go(i + j, ns);
	}
}

void run()
{
	scanf("%d", &l);
	cin >> s;
	n = s.length();
	
	go(0, {});
	printf("%d\n", ans.size());
	for (string s : ans)
		cout << s << endl;
	printf("\n");
}
/*
if (debug) printf("%d\n", );
if (debug) printf("\n");
*/