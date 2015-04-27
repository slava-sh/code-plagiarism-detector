
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::set;
using std::min;

int main()
{
	int max_len = 0;
	cin >> max_len;

	string message;
	cin >> message;

	int n = message.length();

	if (max_len >= message.size ())
	{
		cout << 1 << std::endl;
		cout << message;
		return 0;
	}

	vector < vector < vector <string> > > table(n);
	for (int i = 0; i < n; i++) table[i] = vector < vector <string> >(n);

	for (int len = 1; len <= max_len; len++)
	{
		for (int i = 0; i < n; i++)
		{
			int real_len = min(len, n - i);

			table[i][i + real_len - 1].push_back(message.substr(i, real_len));
		}
	}

	for (int l = n - 1; l >= 0; l--)
	{
		for (int r = l; r < n; r++)
		{
			if (r - l + 1 > max_len)
			{
				for (int k = l; k < r; k++)
				{
					set <string> unique;

					for (int i = 0; i < table[l][k].size(); i++)
					{
						unique.insert(table[l][k][i]);
					}

					for (int i = 0; i < table[k + 1][r].size(); i++)
					{
						unique.insert(table[k + 1][r][i]);
					}

					if (table[l][r].size() == 0 || unique.size() <= table[l][r].size())
					{
						table[l][r] = vector <string>(unique.begin(), unique.end());
					}
				}
			}
		}
	}

	cout << table[0][n - 1].size() << std::endl;

	for (int i = 0; i < table[0][n - 1].size(); i++)
	{
		cout << table[0][n - 1][i] << std::endl;
	}

	cin.get();
	cin.get();
	return 0;
}