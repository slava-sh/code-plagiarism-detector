#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int binpos(vector <long int> &mass,int l, int r,int max,int nach)
{
	if (l>r)// || l+1 == r)
		return mass.size()-l;
	int k = (r+l)/2;
	if (mass[k]-mass[nach]>max)
	{
		return binpos(mass,l,k-1,max,nach);
	}
	else
	{
		return binpos(mass,k+1,r,max,nach);
	}
}
int main()
{
	long int N,R;
	ifstream inf ("che.in");
	inf>>N>>R;
	vector <long int> mass;
	mass.resize(N);
	for (int i=0;i<N;i++)
	{
		inf>>mass[i];
	}
	inf.close();
	int ans=0;
	int l=0;
	for (l=0;l<=N-2;l++)// цикл перебора начальных позиций
	{
		ans+=binpos(mass,l+1,N-1,R,l);
	}
	ofstream ouf ("che.out");
	ouf<<ans;
	ouf.close();
	return 0;
}