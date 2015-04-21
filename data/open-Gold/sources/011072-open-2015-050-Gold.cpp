//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

const int maxN = 3e5;	

long long a[maxN];
long long b[maxN];

int main()
{
	long long n, k, c, d1;
	cin >> n >> k >> c >> d1;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		ans += (b[i] - a[i]);
	}
	if(n == 1)
	{
		cout << ans * d1 << endl;
		return 0;
	}
	vector <long long> v;
	for(int i = 2; i <= n; i++)
	{
		v.push_back(a[i] - b[i - 1]);
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < (int)v.size(); i++)
	{
		v[i] += v[i - 1];
	}
	long long glb = ans * d1 + (c) * ((n + k - 1) / k) - c;
	for(int i = 0; i < (int)v.size(); i++)
	{
		int t = i + 1;
		int cnt = (n - t + k - 1) / k;
		glb = min(glb, ans*d1 + (cnt * c - c) + v[i] * d1);
	}

	cout << glb << endl;
	return 0;
}