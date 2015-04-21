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

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");
	int L, a = 0, b = 0, c = 0;
	string S;
	cin >> L >> S;
	if (L >= (int)S.size())
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
				int n = (int)S.size();
				bool found = false;
				for (int l = 1; l <= L; ++l)
				{
					if (n % l != 0)
						continue;
					bool good = true;
					for (int j = 0; j < n; j += l)
					{
						if (S.substr(j, l) != S.substr(0, l))
						{
							good = false;
							break;
						}
					}
					if (good)
					{
						found = true;
						cout << 1 << endl;
						cout << S.substr(0, l) << endl;
						break;
					}
				}
				if (!found)
					cout << "2\na\nb\n";
			}
		}
	}
}