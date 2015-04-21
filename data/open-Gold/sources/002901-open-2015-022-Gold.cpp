#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2e5 + 111;

int n, k, c, d;

int a[MAX], b[MAX];

vector <int> v;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k >> c >> d;
	for(int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);
	long long ans = ((long long)b[n - 1] - a[0]) * d;
	for(int i = 1; i < n; i++)
		v.push_back(a[i] - b[i - 1]);
	sort(v.begin(), v.end());
	int cur = 1;
	int size = v.size();
	for(int i = size - 1; i >= 0; i--)
	{
		if(cur + 1 != k + 1)
		{
			ans -= v[i] * d;
			cur++;
		}
		else if(ans - v[i] * d + c < ans)
		{
			ans -= v[i] * d;
			ans += c;
			cur = 1;
		}
	}
	cout << ans;
	return 0;
}
