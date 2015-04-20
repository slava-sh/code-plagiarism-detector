#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fname "numbers"
#define ll long long
#define ull unsigned long long
#define f first
#define s second
const ll INF = (ll)1e18 + 123;
const int MAXN = (int)1e6 + 123;
const double eps = 1e-6;

using namespace std;
int n,sz[1005],a,m,kol,fs;
string s,city[1133],region[1005][105];
int main()
{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cin >> city[i] >> sz[i];
		for (int j = 1;j <= sz[i];j ++)
		{
			cin >> region[i][j];	
		}
	}
/*	for (int i = 1;i <= n;i ++)
	{
		cout << city[i];
		cout << " ";
		for(int j = 1;j <= sz[i];j ++)
			cout << region[i][j] << " ";
		cout << endl;
	}
	return 0;
*/	cin >> m;
	for (int i = 1;i <= m;i ++)
	{
		cin >> s;
		if (s[0] == '0')
		{
			cout << "Incorrect\n";
			continue;
		}	
		for (int j = 1;j <= n;j ++)
		{
			for (int o = 0;o < city[j].size();o ++)
			{
				if(s[o] != city[j][o])
					goto qwe;
			}
//			cout << s << " " << city[j] << endl;
			for (int k = 1;k <= sz[j];k ++)
			{
				for (int o = 0;o < region[j][k].size();o ++)
				{
					if (s[city[j].size() + o] != region[j][k][o])
						goto ert;
				}
				if (s[city[j].size() + region[j][k].size()] == '0')
					goto ert;
				cout <<"+";
				for (int o = 0;o < city[j].size();o ++)
				{
					cout << city[j][o];
				}
				cout << "(";
				for (int o = 0;o < region[j][k].size();o ++)
					cout << region[j][k][o];
				cout << ")";
				kol = s.size() - (city[j].size() + region[j][k].size());
				fs = city[j].size() + region[j][k].size();
				if (kol == 3)
				{
					for (int o = fs;o < s.size();o ++)
						cout<< s[o];
				}
				else if (kol == 4 || kol == 5)
				{
					for (int o = fs;o < s.size() - 2;o ++)
						cout << s[o];
					cout << "-";
					for (int o = s.size() - 2;o < s.size();o ++)
						cout << s[o];
				}
				else if (kol == 6 || kol == 7)
				{
					for (int o = fs;o < s.size() - 4;o ++)
						cout << s[o];
					cout << "-";
					for (int o = s.size() - 4;o <s.size() - 2;o ++)
						cout << s[o];
					cout << "-";
					for (int o = s.size() - 2;o < s.size();o ++)
						cout << s[o];
				}
				goto wer;
				ert:;
			}
			qwe:;
		}
		cout << "Incorrect\n";   
		continue;
		wer:;
		cout << endl;
	}
	return 0;
}