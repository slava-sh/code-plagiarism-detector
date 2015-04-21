#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> z_function(string S)
{
	int n = (int)S.size();
	vector<int> Z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i)
	{
		if (i <= r)
			Z[i] = min(r - i + 1, Z[i - 1]);
		while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]])
			++Z[i];
		if (i + Z[i] - 1 > r)
			l = i, r = i + Z[i] - 1;
	}
	return Z;
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");
	int N, a = 0, b = 0, c = 0;
	string S;
	cin >> N >> S;
	if (N >= (int)S.size())
		cout << 1 << endl << S << endl;
	else
	{
		for (int i = 0; i < (int)S.size(); ++i)
			if (S[i] == 'a')
				a += 1;
			else if (S[i] == 'b')
				b += 1;
			else
				c += 1;
		if (c == 0)
		{
			if (b == 0)
				cout << "1\na\n";
			else if (a == 0)
				cout << "1\nb\n";
			else
			{
				vector<int> Z = z_function(S);
				int n = (int)S.size();
				bool found = false;
				for (int i = 1; i < min(n, N + 1); ++i)
				{
					if (i + Z[i] == n && n % i == 0)
					{
						cout << 1 << endl;
						for (int j = 0; j < i; ++j)
							cout << S[j];
						cout << endl;
						found = true;
						break;
					}
				}
				if (!found)
					cout << "2\na\nb\n";
			}
		}
	}
}