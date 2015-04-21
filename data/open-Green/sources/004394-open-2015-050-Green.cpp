//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;
long long pp[20];
int main()
{
	long long n, k;
	cin >> n >> k;
	vector <long long> v;
	for(long long i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			n/=i;
			v.push_back(i);
		}
	}
	if(n != 1)
	{
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int cur = 0;
	for(int j = 0; j < (int)v.size(); j++)
	{
		if(pp[cur] == 0)
		{
			pp[cur] = 1;
		}
		pp[cur] *= v[j];
		cur = (cur + 1) % k;
	}
	long long ans = 1;
	for(int i = 0; i < k; i++)
	{
		ans *= max(1ll, (pp[i] + 1) / 2);
	}
	cout << ans;
	return 0;
}