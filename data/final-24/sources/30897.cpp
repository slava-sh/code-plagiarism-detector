#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<iomanip>

#define ll long long
#define ull unsigned ll
#define VE vector
#define VI VE<ll>

using namespace std;
VI a;
int n, q, er;
VI pref(string s)
{
	int k, n = s.size();
	VI p(n);
	for(int i = 1;i < n;i++)
	{
		k = p[i-1];
		while(k > 0 && s[k] != s[i])
			k = p[k - 1];
		if(s[k] == s[i])
			k++;
		p[i] = k;
	}
	return p;
}
vector<string> ts;
bool win = 0;
void pref_bomb(string a, string b)
{
	string tot = a + '^' + b;

	int sbl = a.size();
	int h = tot.size();
	VE<string> ans(1);
	int cnt=0;
	VI p = pref(tot);
	bool prev = 0, cur = 0;
	for(int i = sbl + 1;i < h;i++)
	{
		prev = cur;
		if(i + sbl - 1 < h && p[i + sbl - 1] != sbl)
		{
			cur = 1;
			if(prev)
				ans[cnt] += tot[i];
			else
			{ans.push_back(""+tot[i]);cnt++;}
		}
	}
	if(ans.size() + 1 < er)
	{
		if(!win)
		{
		
		win = 1;
		}
		else
		{
			if(ts.size() > ans.size() + 1)
			{
				ts.clear();
				ts.push_back(a);
				for(int i = 0;i < ans.size();i++)
					ts.push_back(ans[i]);
			}
		}

	}
}
int main()
{
	
	ios_base::sync_with_stdio(0);
	
	ifstream cin("input.txt");
	ofstream cout("output.txt");


	cin >> n;
	string s;
	cin >> s;
	int k = s.size();
	set<char> st;
	for(int i = 0;i < k;i++)
	{
		st.insert(s[i]);
	}
	er = st.size();
	for(int i = 0;i < k;i++)
	{
		for(int j = i + 1;j < i + n;j++)
		{
			string sg = s.substr(i,j-i);
			pref_bomb(sg ,s);
		}
	}
	if(win)
	{
		cout << ts.size() << "\n";
		for(int i = 0;i < ts.size();i++)
			cout << ts[i] << "\n";

	}
	else
	{
		cout << er << "\n";
		for(int i = 0;i < er;i++)
		{
			cout << *st.begin() <<"\n";
			st.erase(st.begin());
		}
	}
	return 0;
}