#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
typedef __int64 llint;
string cut(string &tmp, int len)
{
	string ans = tmp.substr(0, len);
	tmp.erase(0, len);
	return ans;
}
char buf[2000];
vector <string> cnt;
vector <string> reg[200];
bool inc;
string Answer3(string num)
{
	string ans = "";
	if(num[0] == '0')
	{
		goto theend;
	}
	if(num.size() == 3)
	{
		return ans + num;
	}
	if(num.size() == 4)
	{
		ans += cut(num, 2); ans += "-" + cut(num, 2);
		return ans;
	}
	if(num.size() == 5)
	{
		ans += cut(num, 3); ans += "-" + cut(num, 2);
		return ans;
	}
	if(num.size() == 6)
	{
		ans += cut(num, 2); ans += "-" + cut(num, 2); ans += "-" + cut(num, 2);
		return ans;
	}
	if(num.size() == 7)
	{
		ans += cut(num, 3); ans += "-" + cut(num, 2); ans += "-" + cut(num, 2);
		return ans;
	}
theend:
	inc = 1;
	return ans;
}
string Answer2(string num, int nc)
{
	int i;
	string ans, h;
	for(i = 0; i < reg[nc].size(); i++)
	{
		if(num.size() >= reg[nc][i].size() && num.substr(0, reg[nc][i].size()) == reg[nc][i])
		{
			h = num; h.erase(0, reg[nc][i].size());
			ans = "(" + reg[nc][i] + ")" + Answer3(h);
			if(inc == 0)
			{
				return ans;
			}
			inc = 0;
		}
	}
	inc = 1;
	return ans;
}
string Answer(string num)
{
	string ans, h;
	int i, nc;
	if(num[0] == '0')
	{
		goto theend;
	}
	for(i = 0; i < cnt.size(); i++)
	{
		if(num.size() >= cnt[i].size() && num.substr(0, cnt[i].size()) == cnt[i])
		{
			h = num; h.erase(0, cnt[i].size()); 
			ans = "+" + cnt[i] + Answer2(h, i);
			if(inc == 0)
			{
				return ans;
			}
			inc = 0;
		}
	}
theend:
	return "Incorrect";
}
int main()
{
	freopen("numbers.in", "r", stdin); freopen("numbers.out", "w", stdout);
	int n, i, j, nc;
	scanf("%d\n", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s%d\n", buf, &nc);
		cnt.push_back(string(buf));
		for(j = 0; j < nc; j++)
		{
			scanf("%s\n", buf);
			reg[i].push_back(string(buf));
		}
	}
	int k;
	scanf("%d\n", &k);
	for(i = 0; i < k; i++)
	{
		scanf("%s\n", buf);
		printf("%s\n", Answer(string(buf)).c_str());
	}
	return 0;
}