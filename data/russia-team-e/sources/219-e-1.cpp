#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <functional>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define SS stringstream
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> > 
#define FIN freopen("1.in", "r", stdin)
#define FOUT freopen("1.out", "w", stdout)
#define FILE FIN; FOUT
#define SRD srand((int)time(NULL))
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) (1ll*(x)*(x))
#define pw(x) (1ll<<(x))
#define SC(x) scanf("%d", &x)
#define CC(x) cout << x << endl
#define CCS(x) cout << x << " "
#define forr(i, l, r) for(int i = l; i <= r; i++)
#define CCC(x) cout << x

typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;

using namespace std;

set<pii> ST;

	inline void write(int l, int r, int a,int b, string s)
	{
		cout << "+" << a << "(" << b << ")";
		string ss = "";
		int cc = l+r;
		for(int i = 1; i < s.length(); i++)
			if (cc == 0) ss += s[i]; else cc--;
		int len = ss.length();	
		if (len == 3) CC(ss); else
		if (len == 4) 
		{
			for(int i = 0; i<2; i++) CCC(ss[i]);
			CCC('-');
			for(int i = 2; i<4; i++) CCC(ss[i]);
			CC("");
		} else
		if (len == 5)
		{
			for(int i = 0; i<3; i++) CCC(ss[i]);
			CCC('-');
			for(int i = 3; i<5; i++) CCC(ss[i]);
			CC("");
		} else
		if (len == 6)
		{
			for(int i = 0; i<2; i++) CCC(ss[i]);
			CCC('-');
			for(int i = 2; i<4; i++) CCC(ss[i]);
			CCC('-');
			for(int i = 4; i<6; i++) CCC(ss[i]);
			CC("");
		}else
		if (len == 7)
		{
			for(int i = 0; i<3; i++) CCC(ss[i]);
			CCC('-');
			for(int i = 3; i<5; i++) CCC(ss[i]);
			CCC('-');
			for(int i = 5; i<7; i++) CCC(ss[i]);
			CC("");
		}
	}

int main()
{	
	//FIN;
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	SS qq;
	int n, m;
	cin >> n;
	forr(i, 1, n)
	{
		int a, m;
		cin >> a >> m;
		forr(j, 1, m)
		{
			int b;
			cin >> b;
			ST.insert(mp(a, b));
		}	
	}
	cin >> n;
	forr(t, 1, n)
        {
        	string s;
        	cin >> s;
        	s = " " + s;
        	bool f = false;
        	forr(i, 1, 3) if (!f)
        		forr(j, 3, 5)
        		{
        			if (s[1] != '0' && s[i+1] != '0' && s[i+j+1] != '0')
        			{
        				int a, b;
        				string g = "";
        				forr(ii, 1, i) g += s[ii];
        				qq << g;
        				qq >> a;
        				qq.clear();
        				g = "";
        				forr(ii, i+1, i+j) g += s[ii];
        				qq << g;
        				qq >> b;
        				qq.clear();
        				if (ST.find(mp(a, b)) != ST.end())
        				{
        					f = true;
        					write(i, j, a, b, s);
						break;
        				}
        			}
        		}
               if (!f) CC("Incorrect");
        }
	return 0;
}