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

bool check(int i, string ds)
{
	if (i == n)
		return 1;
	int len = ds.length();
	return i + len <= n && s.substr(i, len) == ds;
}

bool check(int i, string s1, string s2)
{
	if (i == n)
		return 1;
	return (check(i, s1) && check(i + s1.length(), s1, s2)) || (check(i, s2) && check(i + s2.length(), s1, s2));
}

void run()
{
	scanf("%d", &l);
	cin >> s;
	n = s.length();
	
	//dbg(check(0, "a", "b"));
	//return;
	
	if (l >= n)
	{
		printf("%d\n", 1);
		cout << s << endl;
		return;
	}
	
	for (int l1 = 1; l1 <= l; l1++)
	{
		string s1 = s.substr(0, l1);
		for (int i = 0; i <= n; i += l1)
			if (i == n)
			{
				printf("%d\n", 1);
				cout << s1 << endl;
				return;
			}
			else if (!check(i, s1))
				break;
	}
	
	for (int l1 = 1; l1 <= l; l1++)
	{
		string s1 = s.substr(0, l1);
		int ist = 0;
		while (check(ist, s1))
			ist += s1.length();
		for (int l2 = 1; l2 <= l && l1 + l2 <= n; l2++)
		{
			string s2 = s.substr(ist, l2);
			if (check(0, s1, s2))
			{
				printf("%d\n", 2);
				cout << s1 << endl;
				cout << s2 << endl;
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