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
	string cand;
	for (int i = 0; i < s.length(); i++)
	{
		cand += s[i];
		string tmp = cand;
		while (tmp.length() < s.length())
		{
			tmp += cand;
		}
		if (tmp == s && cand.length()<=l)
		{
			cout << 1 << endl << cand << endl;
			return 0;
		}
	}	
	cout << "2\na\nb";
	return 0;	
}