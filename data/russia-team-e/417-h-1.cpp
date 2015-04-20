#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int N,M;
	ifstream inf("secure.in");
	//ofstream ouf ("secure.out");
	inf>>N>>M;
	vector < vector <unsigned long long> > mass;
	mass.resize(N);
	for (int i=0;i<N;i++)
	{
		mass[i].resize(N);
		for (int j=0;j<N;j++)
		{
			mass[i][j] = 10000000000+1;
		}
	}
	vector<short> data;
	data.resize(N);
	for (int i=0;i<N;i++)
	{
		inf>>data[i];
	}
	for (int i=0;i<M;i++)
	{
		int a,b,c;
		inf>>a>>b>>c;
		mass[a-1][b-1]=c;
		mass[b-1][a-1]=c;
	}
	inf.close();
	int k,i,j;
	for (k=0;k<N;k++)
		for (i=0;i<N;i++)
			for (j=0;j<N;j++)
			{
				mass[i][j]=min(mass[i][j],mass[i][k]+mass[k][j]);
			}
	unsigned long long min=-1;
	int minx,miny;
	for (int i=0;i<N;i++)
	{
		if (data[i]==1)
		{
			for (int j=0;j<N;j++)
				if (data[j]==2)
				{
					if ((mass[i][j]<min) ||( min==-1))
					{
						min = mass[i][j];
						minx=i;
						miny=j;
					}
				}
		}
	}
	ofstream ouf ("secure.out");
	if (min == 10000000000+1)
		ouf<<-1;
	else
		ouf<<minx+1<<' '<<miny+1<<' '<<min;
	ouf.close();
	return 0;
}