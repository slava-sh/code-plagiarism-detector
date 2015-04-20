#include<iostream>
using namespace std;
int main()
{
	freopen("che","r",stdin);
	freopen("che","w",stdout);
	__int64 n, r, t = 0, a[300000];
	cin>>n>>r;
	for(int i = 0; i < n; i ++)
	cin>>a[i];
	for(int i = 0; i < n - 1; i ++)
	for(int j = i + 1; j < n; j ++)
	if(a[j] - a[i] > r)
	t ++;
	cout<<t;
	return 0;
}
