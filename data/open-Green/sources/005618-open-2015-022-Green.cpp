#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

const int INF = 2e9;

int n, k;

int answer = INF, size;

vector <int> ans, v;

int f(int n)
{
	return n / 2 + n % 2; 
}

void solve(int n, int k)
{
	if(k == 1)
	{
		ans.push_back(n);
		int size = ans.size();
		int gg = 1;
		for(int i = 0; i < size; i++)
		{
			gg *= f(ans[i]);
		}
		answer = min(answer, gg);
		ans.pop_back();
		return;
	}
	for(int i = 0; i < size; i++)
	{
		if(n % v[i] == 0)
		{
			ans.push_back(v[i]);
			solve(n / v[i], k - 1);
			ans.pop_back();
		}
	}
}

void gen()
{
	for(int i = 1; i <= (int)sqrt(1. * n); i++)
	{
		if(n % i == 0)
		{
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end());
	size = v.size();
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	gen();
	solve(n, k);
	cout << answer;
	return 0;
}
