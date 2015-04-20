#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int binpos(vector <long int> &mass,long int l, long int r,long int max,long int nach)
{
	if (l>r)// || l+1 == r)
		return mass.size()-l;
	long int k = (r+l)/2;
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
	for (long int i=0;i<N;i++)
	{
		inf>>mass[i];
	}
	inf.close();
	unsigned long long ans=0;
	long int l=0;
	for (l=0;l<=N-2;l++)// ���� �������� ��������� �������
	{
		ans+=binpos(mass,l+1,N-1,R,l);
	}
	ofstream ouf ("che.out");
	ouf<<ans;
	ouf.close();
	return 0;
}