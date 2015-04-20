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
	__int64 t = 0, s = 0, k;
	cin>>n>>r;

	for(int i = 0; i < n; i ++)
	cin>>a[i], s += a[i];
	sort(a, a + n);
while(a[0])
{
if(a[0] * n <= r)
{
k = a[0]; break;
}
else
a[0] --;
 }
 cout<<min(k,r-a[n - 1]);
 return 0;
}
