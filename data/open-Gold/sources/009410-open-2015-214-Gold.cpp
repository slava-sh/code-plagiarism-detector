#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//int best[1007];
long long l[200007], r[200007];
const long long INF = 1000000000000666666;
long long needAdd = 0;
vector<long long>segs;
long long ps[200007], dp[200007];

int main()
{
	long long n, k, c, d;
	cin >> n >> k >> d >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		needAdd += (r[i] - l[i])*c;
	}
	if (n == 1)
	{
		cout << needAdd << endl;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		l[i] = r[i];
		r[i] = l[i + 1];
		segs.push_back(r[i]-l[i]);
	}	
	sort(segs.rbegin(), segs.rend());	
	ps[0] = segs[0];
	for (int i = 0; i < segs.size(); i++)
	{
		ps[i] = ps[i - 1] + segs[i];
	}
	//k--;
	for (int i = 0; i < segs.size(); i++)
	{
		if (i - k >= 0)
		{
			dp[i] = min(dp[i - 1] + segs[i] * c, dp[i - k] + d);
		}
		else
		{
			dp[i] = min(dp[i - 1] + segs[i] * c, d);
		}
	}
	long long more = dp[segs.size() - 1];
	int pos = segs.size() - 1;
	for (int ll = 1; ll + 1 <= k; ll++)
	{
		//pos--;
		more = min(more, dp[pos]);
		pos--;
	}
	
	cout << needAdd + more << endl;
}