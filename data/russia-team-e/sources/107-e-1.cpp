#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

const int nmax = 100000;


bool check(string s, string t)
{
	return ((t.size() <= s.size()) && (s.substr(0, t.length()) == t));
}

string nc[101];
vector <string> tw[101];



int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nc[i];
		int k;
		cin >> k;
		tw[i].resize(k);
		for (int j = 0; j < k; j++) cin >> tw[i][j];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string ss;
		cin >> ss;
		bool ok = false;
		for (int j = 0; j < n; j++)
		{
			if (!check(ss, nc[j])) continue;
			for (int l = 0; l < tw[j].size(); l++)
			{
				if (ok) continue;
				if ((check(ss, nc[j] + tw[j][l])) && (ss[nc[j].length() + tw[j][l].length()] != '0'))
				{
					ok = true;
					cout << "+" << nc[j] << "(" << tw[j][l] << ")";
					string gs = ss.substr(nc[j].length() + tw[j][l].length(), ss.length() - nc[j].length() - tw[j][l].length());
					if (gs.length() != 0)
					{
						cout << gs[0];
						gs = gs.substr(1, gs.length() - 1);
					}
					for (int i = 0; i < gs.length() - 1; i++)
					{
						cout << gs[i];
						if (i % 2 == 1)
						{
							cout << "-";
						}
					}
					cout << gs[gs.length() - 1] << endl;
				}
			}
		}
		if (!ok) cout << "Incorrect" << endl;
	}
	return 0;
}