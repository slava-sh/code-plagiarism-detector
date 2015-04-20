#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("prizes.in");
ofstream fout("prizes.out");
long long n,m,a,b,s;
int main()
{
	fin>>n>>m;
	if(n>m)
	{
		a=n; b=m; n=b; m=a;
	}
	n--;
	if(n>=2)
		s=1;
	if(n==0 && m>2)
		s=1+(m-3)/4;
	fout<<s<<endl;
	return 0;
}