#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define div divv
using namespace std;

long long n, k;

vector <long long> v, div;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	for(int i = 2; i <= (int)sqrt(1. * n); i++)
	{
		if(n % i == 0)
		{
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end());
	int size = v.size();
	int ind = 0;
	long long m = 1;
	long long prev = n;
	while(k > 0)
	{	
		if(ind == size)
			break;
		while(n % v[ind] == 0)
		{
			div.push_back(v[ind]);
			n /= v[ind];
			k--;
			m *= v[ind];
			if(k == 0)
			break;
		}
		ind++;
	}
	n = prev;
	if(n != m)
	{
		div[div.size() - 1] *= n / m;
		//long long last = div[div.size() - 1];
		//div.pop_back();
		//div.push_back(n / (last * m));
	}
	sort(div.begin(), div.end());
	for(int i = 0; i < k; i++)
		div.push_back(1);
	size = div.size();
	long long ans = 1;
	for(int i = 0; i < size; i++)
		ans *= div[i] / 2 + div[i] % 2;
	cout << ans;
	return 0;
}
