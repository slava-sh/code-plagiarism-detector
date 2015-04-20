#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n;
	cin >> n;
	map <string, set<string> > tel;
	string s, t;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> s >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> t;
			tel[s].insert(t);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> s;
		vector <string> answer;
		bool flag = 1;
		for (int j = 1; j <= 3 && flag; ++j)
		{
			string h = string(s.begin(), s.begin() + j);
			map<string, set<string> > :: iterator it = tel.find(h);
			if (it != tel.end())
			{
				for (int o = 3; o <= 5; ++o)
				{
					string g = string(s.begin() + j, s.begin() + j + o);
					set <string> :: iterator jt = it->second.find(g);
					if (jt != it->second.end())
					{
						if(s[j + o] != '0')
						{
							answer.push_back(h);
							answer.push_back(g);
							answer.push_back(string(s.begin() + j + o, s.end()));
							flag = 1;
							break;
						}
					}
				}
			}
		}
		if (answer.size())
		{
			cout << "+" << answer[0] << "(" << answer[1] << ")";
			if (answer[2].size() == 3)
			{
				cout << answer[2] << "\n";
			}
			else if (answer[2].size() == 4)
			{
				cout << string(answer[2].begin(), answer[2].begin() + 2) << "-" << string(answer[2].begin() + 2, answer[2].end()) << "\n";
			}
			else if (answer[2].size() == 5)
			{
				cout << string(answer[2].begin(), answer[2].begin() + 3) << "-" << string(answer[2].begin() + 3, answer[2].end()) << "\n";
			}
			else if (answer[2].size() == 6)
			{
				cout << string(answer[2].begin(), answer[2].begin() + 2) << "-" << string(answer[2].begin() + 2, answer[2].begin() + 4) << "-" 
					<< string(answer[2].begin() + 4, answer[2].end()) << "\n";
			}
			else if (answer[2].size() == 7)
			{
				cout << string(answer[2].begin(), answer[2].begin() + 3) << "-" << string(answer[2].begin() + 3, answer[2].begin() + 5) << "-" 
					<< string(answer[2].begin() + 5, answer[2].end()) << "\n";
			}
		}
		else
		{
			cout << "Incorrect\n";
		}
	}
	return 0;
}