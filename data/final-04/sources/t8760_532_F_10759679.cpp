#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define MAXN 200010

string s, t;

long long ct[26];
long long cs[26];
//long long step = 2;
long long step = 239017;
long long h[MAXN];


int main()
{

#if !defined( ONLINE_JUDGE )
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ns, nt;
	cin >> ns >> nt;
	cin >> s;
	cin >> t;

	h[0] = step;
	int pt[26] = {-1};
	for (int i = 0; i < nt; i++)
	{
		ct[t[i] - 'a'] += h[i];
		cs[s[i] - 'a'] += h[i];
		h[i + 1] = h[i] * step;
		pt[t[i] - 'a'] = i;
	}

	vector<int> ans;
	for (int i = nt; i <= ns; i++)
	{
		set<long long> ss;
		for (int j = 0; j < 26; j++)
			ss.insert(cs[j]);
		int fl = 0;
		int sootv[26];
		for (int j = 0; j < 26; j++)
			sootv[j] = -1;
		for (int j = 0; j < 26; j++)
		{
			if (ss.find(ct[j]) == ss.end())
			{
				fl = 1;
				break;
			} else
			{
				if (ct[j] != 0)
				{
					int c1 = t[pt[j]] - 'a';
					int c2 = s[i - nt + pt[j]] - 'a';
					if ((sootv[c1] != -1 && sootv[c1] != c2) || (sootv[c2] != -1 && sootv[c2] != c1))
//					if (sootv[c1] != c2 || sootv[c2] != c1)
					{
						fl = 1;
						break;
					}
					sootv[c1] = c2;
					sootv[c2] = c1;
				}
			}
		}
		if (fl == 0)
		{
			ans.push_back(i - nt + 1);
		}
		if (i != ns)
		{
			cs[s[i - nt] - 'a'] -= h[i - nt]; 
			cs[s[i] - 'a'] += h[i]; 
		}
		for (int j = 0; j < 26; j++)
		{
			ct[j] *= step;
		}
		h[i + 1] = h[i] * step;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}