#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <string>
#include <cstring>
#pragma comment(linker, "/STACK:100000000")
using namespace std;

const int MAXINT = 1000000010;
const long long MAXLL = 2e18;
const long long MODUL = 1000000007;



template <typename T>
inline T MIN(T a, T b)
{
	return (a < b ? a : b);
}
int n, cnt[3], si, ck(0), pi[400010];
string s, m;

void cpi()
{
	pi[0] = 0;
	for(int i(1); i < si; ++i)
	{
		int j = pi[i - 1];
		for(; j > 0 && s[i] != s[j]; j = pi[j - 1]);
		if(s[i] == s[j])
			++j;
		pi[i] = j;
	}
}

int main()
{
	cin >> n >> s;
	cnt[0] = cnt[1] = cnt[2] = 0;
	si = s.size();
	for(int i(0); i < si; ++i)
		++cnt[s[i] - 'a'];
	for(int i(0); i < 3; ++i)
		ck += cnt[i] != 0;
	if(ck == 1)
	{
		cout << 1 << endl << s[0];
		return 0;
	}
	if(n >= si)
	{
		cout << 1 << endl << s;
		return 0;
	}
	n = MIN(n, si / 2);
	for(int i(2); i <= n; ++i)
	if(si % i == 0)
	{
		bool f = 1;
		for(int j(0); j < si; ++j)
		if(s[j] != s[j % i])
		{
			f = 0;
			break;
		}
		if(f)
		{
			cout << 1 << endl;
			for(int j(0); j < i; ++j)
				cout << s[j];
			return 0;
		}
	}
	if(ck == 2)
	{
		cout << 2 << endl;
		if(cnt[0])
			cout << 'a' << endl;
		if(cnt[1])
			cout << 'b' << endl;
		if(cnt[2])
			cout << 'c' << endl;
		return 0;
	}
	cpi();

	return 0;
}














