#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>

#define ll long long
#define TASKNAME "numbers"

using namespace std;

const int maxn = 3*1e5+2;


int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector <set <int> > A(1000, set <int>());

	for (int i = 0; i < n; i++)
	{
		int c, k;
		cin >> c >> k;

		for (int j = 0; j < k; j++)
		{
			int num;
			cin >> num;
			A[c].insert(num);
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		bool flag = 0;

		for (int k1 = 1; k1 <= 3 && !flag; k1++)
			for (int k2 = 3; k2 <= 5 && !flag; k2++)
			{
				int a, b;

				sscanf(s.substr(0, k1).c_str(), "%d", & a);
				sscanf(s.substr(k1, k2).c_str(), "%d", & b);
				string r = s.substr(k1 + k2);

				if (A[a].count(b) == 1 && s[0] != '0' && s[k1] != '0' && s[k1 + k2] != '0')
				{
					cout << "+" << a << "(" << b << ")";

					if (r.size() == 3)
						cout << r;
					if (r.size() == 4)
						cout << r.substr(0, 2) + "-" + r.substr(2, 2);
					if (r.size() == 5)
						cout << r.substr(0, 3) + "-" + r.substr(3, 2);
					if (r.size() == 6)
						cout << r.substr(0, 2) + "-" + r.substr(2, 2) + "-" + r.substr(4, 2);
					if (r.size() == 7)
						cout << r.substr(0, 3) + "-" + r.substr(3, 2) + "-" + r.substr(5, 2);
					cout << '\n';
					flag = 1;
				}
			}

		if (!flag)
			cout << "Incorrect\n";
	}
	return 0;
}