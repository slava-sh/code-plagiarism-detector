#include<iostream>
using namespace std;
	__int64 a[300000], t = 0;
int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	int n, r; 
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
