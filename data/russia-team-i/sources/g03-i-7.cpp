#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("sochi.in");
ofstream fout("sochi.out");
long long a[100002],n,d,i,s;
int main()
{
	fin>>n>>d;
	for(i=1;i<=n;i++)
		fin>>a[i];
	sort(a+1,a+n+1);
	s=a[n];
	for(i=n-1;i>=1;i--)
	{
		if(a[i]<=2*d)
			break;
		s+=a[i]-2*d;
		if(a[i]<3*d)
			break;
	}
	fout<<s<<endl;
	return 0;
}