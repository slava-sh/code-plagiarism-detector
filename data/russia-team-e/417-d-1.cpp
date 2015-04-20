#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned long long N,K,min;
	ifstream inf("fence.in");
	inf>>N>>K;
	vector <unsigned long> mass;
	mass.resize(N);
	min = K+1;
	
	for (unsigned long long i=0;i<N;i++)
	{
		inf>>mass[i];
		if (mass[i]<min)
			min = mass[i];
	}
	inf.close();
	sort(mass.begin(),mass.end());
	unsigned long long limlow=0, limhigh=min;
	unsigned long long sum = 0;
	while (limlow!=limhigh)
	{
		unsigned long long x;
		

		x = (limlow+limhigh)/2;
		if (limhigh-1==limlow)
			x=limhigh;
		sum = mass[0];
		for (unsigned long long i=1;i<N;i++)
		{
			if (sum+x>=mass[i])
				sum+=x;
			else
				sum = mass[i];
			
		}
		if (sum>K)
			{
				if (limhigh-1==limlow)
					break;
				limhigh = x;
				
			}
			else
			{
				limlow = x;
			}
	}
	ofstream ouf ("fence.out");
	ouf<<limlow;
	ouf.close();
	return 0;
}