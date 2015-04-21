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

int answer = INF;

vector <int> ans;

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
	for(int i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			ans.push_back(i);
			solve(n / i, k - 1);
			ans.pop_back();
		}
	}
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	solve(n, k);
	cout << answer;
	return 0;
}
