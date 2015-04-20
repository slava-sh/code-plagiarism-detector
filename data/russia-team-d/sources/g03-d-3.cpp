#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
long long n,m,a[100002],mn,i;
int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
	{
		fin>>a[i];
		if(i==1)
			mn=a[i];
		else
		{
			if(a[i]<mn)
				mn=a[i];
		}
	}
	if(m/n<=mn)
		fout<<m/n<<endl;
	else
		fout<<mn<<endl;
	return 0;
}