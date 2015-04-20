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
	s=(m-1)*2+1;
	s+=n-m;
	s-=1;
	if(s<=2)
	{
		fout<<0<<endl;
		return 0;
	}
	s-=3;
	k++;
	k+=(s-s%6)/6;
	fout<<k<<endl;
	return 0;
}