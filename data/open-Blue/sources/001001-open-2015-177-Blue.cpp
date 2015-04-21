#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 100500;
bool used[5];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		used[s[i] - 'a'] = true;
	}
	vector <char> res;
	for (int i = 0; i < 5; i++)
		if (used[i])
			res.push_back(char(i + 'a'));

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}