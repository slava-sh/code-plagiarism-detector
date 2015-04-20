#include<iostream>
#include<algorithm>
using namespace std;
	__int64 a[300010];
int min(int a,  int b){return a < b ? a : b;}	

__int64 minn = 10000000000;int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	__int64 n, r; 
	__int64 t = 0;
	cin>>n>>r;
	for(int i = 0; i < n; i ++)
	cin>>a[i];
	sort(a, a + n);
    for(int i = 1; i < n - 1; i ++)
minn = min(a[i] - a[i - 1], minn);
minn =	min(r - a[n - 1], minn);
 minn =	min(a[0] , minn);
	
	cout<<minn;
	return 0;
}
