#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#include <set>

using namespace std;

int n, k, m;
string c, s, x;
map < string, int > C;
set < string > R[110];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c >> k;
		C.insert(make_pair(c, i));
		for(int j = 0; j < k; ++j)
		{
			cin >> s;
			R[i].insert(s);
		}
	}
	cin >> m;
	getline(cin, x);
	for (int i = 0; i < m; ++i)
	{
		int ans_j = 0;
		int ans_jj = 0;
		getline(cin, x);
		bool ok = false;
		for (int j = 1; j <= 3 && ok == false; ++j)
		{
			if (x[0] == '0') continue;
			int ind = C[x.substr(0, j)];
			if (ind > 0)
			{
				for (int jj = 3; jj <= 5 && ok == false; ++jj)
					if (R[ind].find(x.substr(j, jj)) != R[ind].end() && x[j + jj] != '0')
					{
						ok = true;
						ans_j = j;
						ans_jj = jj;
					}
			}
		}
		if (ok == false)
			puts("Incorrect");
		else
		{
			cout << "+" << x.substr(0, ans_j) << "(" << x.substr(ans_j, ans_jj) + ")";
			int l = x.size() - ans_j - ans_jj;
			int pos = ans_j + ans_jj;
			if (l & 1)
			{
				cout << x.substr(pos, 3);
				pos += 3;
			}
			for (int j = pos; j < x.size(); j+=2)
			{
				if ((l & 1) && (j == pos))
					cout << "-";
				if (j != pos)
					cout << "-";
				cout << x.substr(j, 2);
			}
			cout << endl;
		}
	}
}