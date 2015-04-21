#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	long long n,k;
	cin>>n>>k;
	k--;
	long long r=1;
	while ((k>0)&&(n%2==0))
		{
			k--;
			n/=2;
		}
	long long q=sqrt(double(n));
	for (long long i=3;i<=q+1;i++)
	{
		long long u=n/i;
		while ((k>0)&&(n%u==0))
		{
			k--;
			n/=u;
			r*=(u+1)/2;
		}
	}

	long long ans=(n+1)/2;
	ans*=r;
	cout<<ans<<endl;
	return 0;
}