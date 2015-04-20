#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("prizes.in");
ofstream fout("prizes.out");
long long n,m,p,s,k;
int main()
{
	fin>>n>>m;
	if(n<=m)
	{
		p=n;
		n=m;
		m=p;
	}
	if(m==2 ||(m==1 && n<=2))
	{
		fout<<0<<endl;
		return 0;
	}
	if(m==1)
		fout<<(n-2)/4+1<<endl;
	else
		fout<<1<<endl;
	return 0;
}