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
	int q=sqrt(double(n));
	for (int i=q+1;i>2;i--)
	{
		while ((k>0)&&(n%i==0))
		{
			k--;
			n/=i;
			r*=(i+1)/2;
		}
	}
	long long ans=(n+1)/2;
	ans*=r;
	cout<<ans<<endl;
	return 0;
}