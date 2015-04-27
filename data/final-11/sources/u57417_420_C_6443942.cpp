#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long lli;
const int N = 311111;
pair <int,int> p[N];
int sum[N],ssum[N];

int main()
{
	ios::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	memset(sum,0,sizeof(sum));
	memset(ssum,0,sizeof(ssum));
	for(int i=0;i<n;i++)
	{
		int a,b; cin>>a>>b;
		a--; b--;
		if(a > b) swap(a,b);
		p[i] = make_pair(a,b);
		sum[a]++; sum[b]++;
		ssum[a]++; ssum[b]++;
	}
	lli ans = 0;
	sort(ssum,ssum+n);
	for(int i=0;i<n-1;i++)
		if(ssum[i]+ssum[n-1]>=m)
		{
			int left = i+1,right = n;
			while(left+1<right)
			{
				int mid = (left+right)>>1;
				if(ssum[i]+ssum[mid-1]>=m)
					right = mid;
				else left = mid;
			}
			ans += n-left;
			//cout<<i<<' '<<left<<'\n';
		}
	sort(p,p+n);
	pair <int,int> t = p[0];
	p[n] = make_pair(0,0);
	int it = 1;
	for(int i=1;i<=n;i++)
		if(p[i] == p[i-1])
			it++;
		else
		{
			int a = t.first;
			int b = t.second;
			if((sum[a]+sum[b]>=m)&&(sum[a]+sum[b]-it<m))
				ans--;
			it = 1;
			t = p[i];
		}
	cout<<ans<<'\n';
	return 0;
}