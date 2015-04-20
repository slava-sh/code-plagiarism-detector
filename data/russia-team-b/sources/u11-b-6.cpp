#include<iostream>
using namespace std;
	__int64 a[300010];
	
int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	__int64 n, r; 
	__int64 t = 0;
	cin>>n>>r;
	for(int i = 0; i < n; i ++)
	cin>>a[i];
	for(int i = 0; i < n; i ++)
	for(int j = i; j < n; j ++)
	if(a[j] - a[i] > r)
	t ++;
	cout<<t;
	return 0;
}
