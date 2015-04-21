#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
bool checkUnique(string& s, vector<string>& dict)
{
	vector<int>dp(s.length(), 0);
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < dict.size(); j++)
		{
			int t = i - dict[j].length() + 1;
			if (t >= 0 && s.substr(t,dict[j].length())==dict[j])
			{
				int w = i - dict[j].length();
				if (w >= 0)
				{
					dp[i] += dp[w];
				}
				else
				{
					dp[i]++;
				}				
			}
		}
	}	
	return dp[s.length() - 1] == 1;
}
int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	if (s.length() <= l)
	{
		cout << 1 << endl << s << endl;		
	}
	bool is2 = false;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != s[i - 1]) is2 = true;
	}
	if (!is2)
	{
		cout << 1 << endl << s[0] << endl;
		return 1234;
	}
	else
	{
		cout << "2\na\nb";
	}
}