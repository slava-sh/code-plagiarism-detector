#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

const long long INF = 2e18;

long long n, k;

long long answer = INF, size;

vector <long long> ans, v;

long long f(long long n)
{
	return n / 2 + n % 2; 
}

void solve(long long n, int k)
{
	if(k == 1)
	{
		ans.push_back(n);
		int size = ans.size();
		long long gg = 1;
		for(int i = 0; i < size; i++)
		{
			gg *= f(ans[i]);
		}
		answer = min(answer, gg);
		ans.pop_back();
		return;
	}
	int sz = ans.size() - 1;
	for(int i = 0; i < size; i++)
	{
		if(sz != -1 && v[i] < ans[sz])
			continue;
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
